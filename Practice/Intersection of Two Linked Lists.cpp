/* Write a program to find the node at which the intersection of two singly linked lists begins.

Example:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. 
From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int count_length(ListNode *head)
    {
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=count_length(headA);
        int lenB=count_length(headB);
        int diff=abs(lenA-lenB);
        if(lenA>lenB)
        {
            while(diff!=0)
            {
                headA=headA->next;
                diff--;
            }
        }
        else
        {
            while(diff!=0)
            {
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=headB&&headA!=NULL&&headB!=NULL)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
