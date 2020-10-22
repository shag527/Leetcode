/*  Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5   */

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
    int min_depth=INT_MAX;
    int find_min(TreeNode *root, int curr)
    {
        if(root==NULL)
            return 0;
        if(root->right==NULL&&root->left==NULL)
        min_depth=min(curr,min_depth);
        find_min(root->left,curr+1);
        find_min(root->right,curr+1);
        return min_depth;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
            return find_min(root,1);
    }
};
