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
    vector<int> preorderTraversal(TreeNode *root) 
    {
        vector<int> res;
        if( NULL == root )
            return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        s.push(p);
        while( !s.empty() )
        {
            p = s.top();
            s.pop();
            res.push_back(p->val);
            if( NULL != p->right )
                s.push(p->right);
            if( NULL != p->left )
                s.push(p->left);
        }
        return res;
    }
};
