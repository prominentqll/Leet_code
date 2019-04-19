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
����˼·��
ͳ������Ԫ�صĵ�i��bit��Ϊ1�ĸ�������Ϊ����Ԫ�س�����3�Σ�������Ԫ��ֻ������1�Σ�
���Ե�ͳ�Ƶĸ�����������3�ͱ�������Ԫ���ڵ�i��bit����1�����ǾͰѽ���ĵ�i��bit��Ϊ1��
ͨ�����32��bit���������Ǿ͹����������Ԫ�أ���󷵻ؽ�����ɣ�ʱ�临�Ӷ���O(32n����
*/

int SingleNumber(vector<int> nums)
{
	int sum = 0;//����ÿ��λ��1�ĸ���֮��
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
		if (sum % 3)//Ҫ�ҵ����ָ�λ��Ϊ1
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