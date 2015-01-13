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
    bool hasPathSum(TreeNode *root, int sum) 
    {
        // !note: root to leaf!
        if( NULL == root )
            return false;
        
        int leftOver = sum - root->val;
        
        if( NULL == root->left && NULL == root->right )  // leaf node
        {
            if( leftOver == 0 )
                return true;
            else
                return false;
        }
        else
            return hasPathSum(root->left,leftOver) || hasPathSum(root->right,leftOver);
    }
};
