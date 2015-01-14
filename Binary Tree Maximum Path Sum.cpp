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
 
 // Solution 1: My own implemented algorithm. Lot of room to improve.
const int INT_MIN = -2147483648;
class Solution {
public:
  // I think there is still a lot of room to improve. Later...
    int maxPathSum(TreeNode* root,int& maxSum)
    {
        if( NULL == root )
            return INT_MIN;
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
        int maxSum = INT_MIN;
        maxPathSum(root,maxSum);
        return maxSum;
    }
};

//Solution 2:
// Found it in LeetCode Discuss Section
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
const int INTMIN = -2147483648;
 
class Solution {
public:
    int maxPathSum(TreeNode *root) 
    {
        int maxSum = INTMIN;
        sumToRoot(root,maxSum);
        return maxSum;
    }
    
    
private:
    int sumToRoot(TreeNode* root, int& maxSum)
    {
        if( NULL == root )
            return 0;
        int l = max(0,sumToRoot(root->left,maxSum));  // if the left child Tree is less than zero, then we don't have to consider it at all.
        int r = max(0,sumToRoot(root->right,maxSum));
        
        maxSum = max(maxSum,l+r+root->val);
        
        return root->val + max(l,r); // because l,r is definitely not nagative, so it's safe to return the sum of this node and all it's children.
    }
};
