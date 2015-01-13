/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /*
     A
   B   C
 */
class Solution {
public:
  // I think there is still a lot of room to improve. Later...
    int maxPathSum(TreeNode* root,int& maxSum)
    {
        if( NULL == root )
            return -9999;
        if( NULL == root->left && NULL == root->right ) // leaf node
        {
            if( root->val > maxSum )
                maxSum = root->val;
            return root->val;
        }
        
        int maxLeft = maxPathSum(root->left,maxSum);
        int maxRight = maxPathSum(root->right,maxSum);
        int subTreeSum = root->val + maxLeft + maxRight;
        int leftTrunk = maxLeft + root->val;
        int rightTrunk = maxRight + root->val;
        int m = max(max(leftTrunk,rightTrunk),root->val);
        int n = max(max(maxLeft,maxRight),max(m,subTreeSum));
        if( n > maxSum )
            maxSum = n;
        return m;
    }

    int maxPathSum(TreeNode *root) 
    {
        if( NULL == root )
            return 0;
        int maxSum = -999999;
        maxPathSum(root,maxSum);
        return maxSum;
    }
};
