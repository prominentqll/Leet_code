#include<iostream>
#include<vector>
using namespace std;

//��������������������ظ�����Ԫ�أ�������ЧԪ�صĸ���
/*
1.      ԭʼ���飺1112233
   ���������飺112233
2.       ԭʼ���飺12233
   ���������飺12233


*/
int  removeDuplicates(vector<int> &vec)
{
	int len = vec.size();
	if (len < 2)
	{
		return 0;
	}
	int index = 2;//index�൱��һ����ָ�룬i�൱��һ����ָ��
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