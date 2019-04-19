#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
	vector<int> result;
	unordered_map<int, int>  map;//用hash表存储每个数对应的下标

	for (int i = 0; i < nums.size(); ++i)
	{
		map[nums[i]] = i;
	}

	for (int i = 0; i < nums.size(); ++i)
	{
		int k = target - nums[i];
		if (map.find(k) != map.end() && map[k] > i)
		{
			result.push_back(i + 1);
			result.push_back(map[k] + 1);
			break;
		}
	}
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	int target = 10;
	vector<int>  result = twoSum(nums, target);
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		printf("%d ", *it);
	}
}