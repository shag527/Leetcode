/*   Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

Follow up: Solve the problem if repeated values on the tree are allowed.

 

Example:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3   */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ref=NULL;
    void search_tree(TreeNode* ptr1, TreeNode* ptr2, int val)
    {
        if(ptr1==NULL)
            return;
        if(ptr1->val==val)
            ref=ptr2;
        search_tree(ptr1->left,ptr2->left,val);
        search_tree(ptr1->right,ptr2->right,val);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ptr1=original,*ptr2=cloned;
        int val=target->val;
        search_tree(ptr1,ptr2,val);
        return ref;
    }
};
