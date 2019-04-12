#include<iostream>
#include<vector>
using namespace std;

/*
《题目要求》
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

《解题思路》
1.有序数组优先考虑二分查找


对于题中的数组总共有以下7种旋转可能
0　　1　　2　　 4　　5　　6　　7

7　　0　　1　　 2　　4　　5　　6

6　　7　　0　　 1　　2　　4　　5

5　　6　　7　　 0　　1　　2　　4

4　　5　　6　　 7　　0　　1　　2

2　　4　　5　 　6　　7　　0　　1

1　　2　　4　　 5　　6　　7　　0

二分搜索法的关键在于获得了中间数后
判断下面要搜索左半段还是右半段
由此我们可以观察出规律：
如果中间的数小于最右边的数，则右半段是有序的，
若中间数大于最右边数，则左半段是有序的

我们只要在有序的半段里用首尾两个数来判断目标值是否在这一区域内，这样就可以确定保留哪半边了

*/
int search(const vector<int>& nums, int target)
{
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end)
	{
		int mid = begin + (end - begin)/2;
		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[mid] < nums[end])//右半边有序
		{
			if (nums[mid] < target&&target <= nums[end])
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		else//左半边有序
		{
			if (nums[mid] > target&&nums[begin] <= target)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
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

	cout << search(nums, 0) << endl;

	return 0;
}