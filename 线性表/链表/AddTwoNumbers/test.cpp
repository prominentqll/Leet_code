#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<vector>
#include<numeric>
using namespace std;

/*


You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/



struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}

};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	int carry = 0;
	int sumOfOne = l1->val + l2->val;
	
	carry = sumOfOne / 10;//进位
	sumOfOne %= 10;//在对应位置的值
	
	struct ListNode *result = new struct ListNode(sumOfOne);
	struct ListNode *cur = result;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 || l2)
	{
		if (l1&&l2)
		{
			sumOfOne = l1->val + l2->val + carry;
			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1 == NULL)
		{
			sumOfOne = l2->val + carry;
			l2 = l2->next;
		}
		else if (l2 == NULL)
		{
			sumOfOne = l1->val + carry;
			l1 = l1->next;
		}
		carry = sumOfOne / 10;//进位
		sumOfOne %= 10;//值
		struct ListNode *oneNode = new struct ListNode(sumOfOne);
		cur->next = oneNode;
		cur = cur->next;
	}
	if (carry == 1)//最后产生的进位
	{
		struct ListNode *oneNode = new struct ListNode(carry);
		cur->next = oneNode;
		cur = cur->next;
	}
	return  result;
}

int main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *cur= l1;


	cur->next = new ListNode(4);
	cur= cur->next;
	cur->next = new ListNode(3);
	cur= cur->next;


	ListNode *l2 = new ListNode(5);
     cur = l2;
	cur->next = new ListNode(6);
	cur = cur->next;
	cur->next = new ListNode(4);
	cur = cur->next;

	ListNode *p3 = addTwoNumbers(l1, l2);

	while (p3 != NULL)
	{
		cout << p3->val<<" ";
		p3=p3->next;
	}
	cout << endl;
	return 0;
}