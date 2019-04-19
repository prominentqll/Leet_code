#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<vector>
#include<numeric>
using namespace std;

/*N������վ��һ�ţ�ÿ���˱�������һ������ֵ��

����Ҫ�����ӷ����ǹ���
ÿ������������һ���ǹ����ϸ������ĺ�����Ҫ�������ھӶ�Ҫ�ࡣ

�ϸ������ı���߽ϵ������Ķ࣬���ұ߽ϵ������Ķࡣ

*/

int cand(vector<int>& ratings)
{
   //�������ٱ�֤ÿ������ӵ��һ���ǹ�
	int len = ratings.size();
	vector<int>  result(len, 1);
	
	//���������α�����
	//���i+1�����ӵ��������ڵ�i�����ӣ����i+1�����ӵ��ǹ��ȵ�i�����ӵ��ǹ���1
	for (int i = 1; i < len; ++i)
	{
		if (ratings[i] > ratings[i-1])
		{
			result[i] = result[i-1] + 1;
		}
	}

	//�������������������������
	for (int i = len - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i+1] && result[i] <= result[i+1])
		{
			result[i] = result[i+1] + 1;
		}
	}
    
	return  accumulate(result.begin(), result.end(), 0);
	//int sum = 0;
	//for (int i = 0; i < result.size(); ++i)
	//{
	//	sum += result[i];
	//}
	//return sum;
}

int main()
{
	vector<int >  nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(3);

	printf("%d\n", cand(nums));
	return 0;
}