#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<vector>
#include<numeric>
using namespace std;

/*
    Given an array of integers, every element appears twice except for one. 
    Find that single one.
*/
/*
解题思路：
统计所有元素的第i个bit上为1的个数，因为其它元素出现了3次，而特殊元素只出现了1次，
所以当统计的个数不能整除3就表明特殊元素在第i个bit上是1，我们就把结果的第i个bit设为1，
通过检查32个bit，这样我们就构造出了特殊元素，最后返回结果即可，时间复杂度是O(32n）。
*/

int SingleNumber(vector<int> nums)
{
	int sum = 0;//计算每个位上1的个数之和
	int result = 0;
	int len = nums.size();
	for (int i = 0; i < 32; ++i)
	{
		sum = 0;
		for (auto j : nums)
		{
			if (j>>i& 1)
			{
				sum++;
			}
		}
		if (sum % 3)//要找的数字该位上为1
		{
			result |= 1 << i;
		}
	}
	return result;
}


int main()
{
	vector<int >  nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(5);
	nums.push_back(4);

	printf("%d\n", SingleNumber(nums));
	return 0;
}