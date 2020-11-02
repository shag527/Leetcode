/*    Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example:

Input: 4->2->1->3
Output: 1->2->3->4   */

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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *ptr=head->next,*save,*curr,*prev=head;
        while(ptr!=NULL)
        {
            if(ptr->val<prev->val)
            {
                curr=head;
                save=NULL;
                if(ptr->val<=curr->val)
                {
                    ListNode *temp=new ListNode;
                    temp->val=ptr->val;
                    temp->next=head;
                    head=temp;
                }
                else
                {
                save=curr;
                curr=curr->next;
                while(curr!=NULL)
                {
                    if(ptr->val>save->val&&ptr->val<=curr->val)
                    {
                        ListNode *temp=new ListNode;
                        temp->val=ptr->val;
                        temp->next=curr;
                        save->next=temp;
                        break;
                    }
                    save=curr;
                    curr=curr->next;
                }
                }
                prev->next=ptr->next;
            }
            if(prev->next!=ptr->next)
                prev=ptr;
            ptr=ptr->next;
        }
        return head;
    }
};
