// My solution is a little bit nasty!

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
    int minDepth(TreeNode *root) 
    {
        if( NULL == root )
            return 0;
        if( root->left == 0 && root->right == 0 )
            return 1;
        if( root->left != 0 && root->right != 0 )
            return min(minDepth(root->left),minDepth(root->right)) + 1;
        return (root->left != 0 ? minDepth(root->left) : minDepth(root->right)) + 1;
    }
};
