// Solution #1: An intuitive algorithm. Recursive method.

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
    
    void pathSum(TreeNode* root, int left, vector<vector<int>>& res,vector<int> cur)
    {
        if( NULL == root )
            return;
        if( NULL == root->left && NULL == root->right ) // This is the leaf Node.
        {
            if( left == root->val )
            {
                cur.push_back(root->val);
                res.push_back(cur);
            }
            else
                return; // This paths cannot sum up to the given sum.
        }
        cur.push_back(root->val);
        pathSum(root->left,left - root->val,res,cur);
        pathSum(root->right,left - root->val,res,cur);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> curVec;
        pathSum(root,sum,res,curVec);
        return res;
    }
    
    
};
