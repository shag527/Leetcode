/* Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4] */

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
void inorder(TreeNode *root, vector<int>&v)
{
    if(root==NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
    
}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        inorder(root1,res);
        inorder(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};
