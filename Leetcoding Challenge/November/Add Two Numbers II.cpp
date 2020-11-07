/*  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum=0;
        ListNode *ptr1=l1,*ptr2=l2,*res=NULL;
        stack<int>v1,v2;
        while(ptr1!=NULL)
        {
            v1.push(ptr1->val);
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL)
        {
            v2.push(ptr2->val);
            ptr2=ptr2->next;
        }
        while(v1.size()!=0&&v2.size()!=0)
        {
            sum=v1.top()+v2.top()+carry;
            v1.pop();
            v2.pop();
            if(sum>9)
                carry=1;
            else
                carry=0;
            ListNode *temp=new ListNode;
            temp->val=sum%10;
            temp->next=res;
            res=temp;
        }
        while(v1.size()!=0) 
        {
            ListNode *temp=new ListNode;
            sum=v1.top()+carry;
            temp->val=sum%10;
            if(sum>9)
                carry=1;
            else
                carry=0;
            v1.pop();
            temp->next=res;
            res=temp;
        }
        while(v2.size()!=0) 
        {
            ListNode *temp=new ListNode;
            sum=v2.top()+carry;
            temp->val=sum%10;
            if(sum>9)
                carry=1;
            else
                carry=0;
            v2.pop();
            temp->next=res;
            res=temp;
        }
        if(carry==1)
        {
            ListNode *temp=new ListNode;
            temp->val=1;
            temp->next=res;
            res=temp;
        }
        return res;
    }
};
