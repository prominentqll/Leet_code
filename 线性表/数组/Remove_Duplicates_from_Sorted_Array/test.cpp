#include<iostream>
#include<vector>
using namespace std;

//在排序的数组允许至多重复两个元素，返回有效元素的个数
/*
1.      原始数组：1112233
   处理后的数组：112233
2.       原始数组：12233
   处理后的数组：12233


*/
int  removeDuplicates(vector<int> &vec)
{
	int len = vec.size();
	if (len < 2)
	{
		return 0;
	}
	int index = 2;//index相当于一个慢指针，i相当于一个快指针
	for (int i = 2; i < len - 1; ++i)
	{
		if (vec[i] != vec[index - 2])
		{
			vec[index++] = vec[i];
		}
	}
	return index + 1;
}


int  main()
{

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(4);
	vec.push_back(5);
	int a = removeDuplicates(vec);
	cout << a << endl;
	getchar();
	return 0;
}