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
//异或，不仅能处理两次的情况，只要出现偶数次，都可以清零

int SingleNumber(vector<int> nums)
{
	int result = 0;
	for (auto i : nums)
	{
		result ^= i;
	}

	return result;
}


int main()
{
	vector<int >  nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(5);

	printf("%d\n", SingleNumber(nums));
	return 0;
}