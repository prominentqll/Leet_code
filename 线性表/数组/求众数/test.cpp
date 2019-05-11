#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>
typedef  struct  Arrary//定义一个结构体数组，leetcode 229（求众数）
{
	int  number;
	int count;
}array;
int compare(const void* num1, const void* num2)//自定义的比较，如果num1>num2，则返回1，否则返回-1或者0
{
	return (*(int*)num1 - *(int*)num2);
}


void  MajorityElement(int* arr, int len)
{
	array* arr1 = (array*)malloc(sizeof(array) * len);
	float times = floor((float)len / 3);//向下取整
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
	if (arr1[j].count > times)//处理最后一个满足情况的，此时for循环已经退出
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