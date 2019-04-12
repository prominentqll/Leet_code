#include<iostream>
#include<vector>
using namespace std;

/*
����ĿҪ��
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

������˼·��
1.�����������ȿ��Ƕ��ֲ���


�������е������ܹ�������7����ת����
0����1����2���� 4����5����6����7

7����0����1���� 2����4����5����6

6����7����0���� 1����2����4����5

5����6����7���� 0����1����2����4

4����5����6���� 7����0����1����2

2����4����5�� ��6����7����0����1

1����2����4���� 5����6����7����0

�����������Ĺؼ����ڻ�����м�����
�ж�����Ҫ�������λ����Ұ��
�ɴ����ǿ��Թ۲�����ɣ�
����м����С�����ұߵ��������Ұ��������ģ�
���м����������ұ������������������

����ֻҪ������İ��������β���������ж�Ŀ��ֵ�Ƿ�����һ�����ڣ������Ϳ���ȷ�������İ����

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
		if (nums[mid] < nums[end])//�Ұ������
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
		else//��������
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