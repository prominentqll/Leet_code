#include<iostream>
#include<vector>
using namespace std;

//数组去重
/*
   原始数组：1 1 2 2 3 4 5 5 
 修改后数组：1 2 3 4 5
 
     原始数组：1
 修改后的数组：1


*/
int   removeDuplicates(vector<int>&arr)
{
	int len = arr.size();
	if (len <= 0)
	{
		return 0;
	}
	
	int index = 0;
	for (int i = 1; i < len; ++i)
	{
		if (arr[index] != arr[i])
		{
			arr[++index] = arr[i];
		}
	}
	return index + 1;
}

int main()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(5);

	cout << removeDuplicates(arr) << endl;
	getchar();
	return 0;
}