// My solution: Uses two queue to store neibour level nodes.


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
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int>> res;
        if( NULL == root )
            return res;
            
        queue<TreeNode*> q1,q2;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            vector<int> vl;
            while(!q1.empty())
            {
                TreeNode* p = q1.front();
                q1.pop();
                vl.push_back(p->val);
                if( p->left )
                    q2.push(p->left);
                if( p->right )
                    q2.push(p->right);
            }
            if(!vl.empty())
                res.push_back(vl);
            
            vl.clear();
            while(!q2.empty())
            {
                TreeNode* p = q2.front();
                q2.pop();
                vl.push_back(p->val);
                if( p->left )
                    q1.push(p->left);
                if( p->right )
                    q1.push(p->right);
            }
            if(!vl.empty())
                res.push_back(vl);
        }
        return res;
    }
};
