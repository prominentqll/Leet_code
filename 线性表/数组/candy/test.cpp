#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<vector>
#include<numeric>
using namespace std;

/*N个孩子站成一排，每个人被分配了一个排名值。

你需要给孩子分配糖果：
每个孩子至少有一个糖果，较高排名的孩子需要比他的邻居都要多。

较高排名的比左边较低排名的多，比右边较低排名的多。

*/

int cand(vector<int>& ratings)
{
   //首先至少保证每个孩子拥有一个糖果
	int len = ratings.size();
	vector<int>  result(len, 1);
	
	//从左到右依次遍历，
	//如果i+1个孩子的排名高于第i个孩子，则第i+1个孩子的糖果比第i个孩子的糖果多1
	for (int i = 1; i < len; ++i)
	{
		if (ratings[i] > ratings[i-1])
		{
			result[i] = result[i-1] + 1;
		}
	}

	//从右向左遍历，依据上述规则
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