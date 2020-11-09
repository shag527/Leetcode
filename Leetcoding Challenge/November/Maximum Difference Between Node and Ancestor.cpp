/*  Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

 
Example:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.   */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int abs_max=INT_MIN;
    int helper_func(TreeNode *root,int min_val,int max_val)
    {
        if(root==NULL)
            return 0;
        max_val=max(max_val,root->val);
        min_val=min(min_val,root->val);
        if(root->left!=NULL)
            helper_func(root->left,min_val,max_val);
        if(root->right!=NULL)
            helper_func(root->right,min_val,max_val);
        abs_max=max(abs_max,abs(max_val-min_val));
        return abs_max;
    }
    int maxAncestorDiff(TreeNode* root) {
        int res=helper_func(root,INT_MAX,INT_MIN);
        return res;
    }
};
