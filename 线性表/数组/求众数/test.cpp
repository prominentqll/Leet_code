#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
typedef  struct  Arrary//����һ���ṹ�����飬leetcode 229����������
{
	int  number;
	int count;
}array;
int compare(const void* num1, const void* num2)//�Զ���ıȽϣ����num1>num2���򷵻�1�����򷵻�-1����0
{
	return (*(int*)num1 - *(int*)num2);
}


void  MajorityElement(int* arr, int len)
{
	array* arr1 = (array*)malloc(sizeof(array) * len);
	float times = floor((float)len / 3);//����ȡ��
	qsort(arr, len, sizeof(int), compare);
	int k = 1;
	int j = 0;
	int i = 0;
	for (; i < len; i++)
	{
		if (k == 1)
		{
			arr1[j].count = 1;
			arr1[j].number = arr[i];
			k = 2;
		}
		else
		{
			if (arr[i] == arr1[j].number)
			{
				arr1[j].count++;
			}
			else
			{
				if (arr1[j].count > times)
				{
					printf("%d ", arr1[j].number);
				}
				j++;
				arr1[j].count = 1;
				arr1[j].number = arr[i];
			}
		}
	}
	if (arr1[j].count > times)//�������һ����������ģ���ʱforѭ���Ѿ��˳�
	{
		printf("%d\n", arr1[j].number);
	}
}

int main()
{
	int arr[] = { 0,1,1,3,4,7,11,3,3,7,5,3,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MajorityElement(arr, len);



	int arr1[] = { 0,1,1,3,4,7,11,1,1,1,5,3,3 };
	int len1= sizeof(arr1) / sizeof(arr1[0]);
	MajorityElement(arr1, len1);

	int arr2[] = { 0,1,1,0 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	MajorityElement(arr2, len2);
	return 0;
}