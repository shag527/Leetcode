/*   Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. If a node does not have a 
left child, then the sum of the left subtree node values is treated as 0. The rule is similar if there the node does not have a right child.

 

Example:


Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tile of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1   */

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
int helper(TreeNode* root,int &fsum)
{
    if(root==NULL)
    return 0;
    int sum=root->val;
    int suml=helper(root->left,fsum);
    int sumr=helper(root->right,fsum);
    fsum+=abs(suml-sumr);
    return sum+suml+sumr;
}


int findTilt(TreeNode* root) {
    int fsum=0;
    helper(root,fsum);
    return fsum;
}
};
