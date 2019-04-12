#include<iostream>
#include<vector>
using namespace std;

//�����������в�����Ŀ��ֵ
//�������п�������ת����
/*
 1.   0124567
 2.   2456701


*/
int search(const vector<int>& nums, int target)
{
	int len = nums.size();
	int first = 0;
	int last = len - 1;
	
	while (first <= last)
	{
		int mid = first + (last - first)/2;

		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[first] <= nums[mid])//0124567 �������
		{
			if (nums[first] <= target &&target < nums[mid])//target���󲿷�
			{
				last = mid;
			}
			else//target���Ҳ���
			{
				first = mid + 1;
			}
		}
		else  //  5670124  nums[first]>nums[mid]����������ת
		{
			if (nums[first] < target&&target >nums[mid])
			{
				last = mid;
			}
			else
			{
				first = mid + 1;
			}
		}
	}

	return -1;

}

int main()
{
	vector<int> nums;
	
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);

	cout << search(nums, 3) << endl;

	return 0;
}