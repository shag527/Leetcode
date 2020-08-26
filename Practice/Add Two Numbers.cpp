/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *res=NULL;
        ListNode *ptr=NULL;
        int carry=0,sum=0;
        while(l1!=NULL&&l2!=NULL)
        {
            sum=l1->val+l2->val;
            ListNode *temp=new ListNode;
            if(sum+carry>9)
            {
                temp->val=(sum+carry)%10;
                carry=1;
            }
            else
            {
                temp->val=sum+carry;
                carry=0;
            }
            temp->next=NULL;
            if(res==NULL)
            {
                res=temp;
                ptr=res;
            }
            else
            {
                ptr->next=temp;
                ptr=temp;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            ListNode *temp=new ListNode;
            if(l1->val+carry>9)
            {
                temp->val=(l1->val+carry)%10;
                carry=1;
            }
            else
            {
                temp->val=l1->val+carry;
                carry=0;
            }
            temp->next=NULL;
            ptr->next=temp;
            ptr=temp;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            ListNode *temp=new ListNode;
            if(l2->val+carry>9)
            {
                temp->val=(l2->val+carry)%10;
                carry=1;
            }
            else
            {
                temp->val=l2->val+carry;
                carry=0;
            }
            temp->next=NULL;
            ptr->next=temp;
            ptr=temp;
            l2=l2->next;
        }
        if(carry!=0)
        {
            ListNode *temp=new ListNode;
            temp->val=carry;
            temp->next=NULL;
            ptr->next=temp;
            ptr=temp;
        }
        return res;
    }
};
