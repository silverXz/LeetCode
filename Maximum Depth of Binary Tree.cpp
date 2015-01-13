/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) 
    {
        if( NULL == root )
            return 0;
        if( NULL == root->left && NULL == root->right )
            return 1;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};
