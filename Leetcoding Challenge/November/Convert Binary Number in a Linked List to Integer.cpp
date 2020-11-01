/*  Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
 

Example:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10   */

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
    int getDecimalValue(ListNode* head) {
        ListNode *ptr=head;
        int res=0,base=0,count=0;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        ptr=head;
        base=pow(2,count-1);
        while(ptr!=NULL)
        {
            if(ptr->val==1)
                res+=base;
            base=base/2;
            ptr=ptr->next;
        }
        return res;
    }
};
