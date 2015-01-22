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
    vector<TreeNode*> generateTrees( int n, int base )
    {
        vector<TreeNode*> result;
        if( n == 0 )
        {
            result.push_back(NULL);
            return result;
        }
        for( int i = 1 ; i <= n ; i++ )
        {
            vector<TreeNode*> left = generateTrees(i-1,base);
            vector<TreeNode*> right = generateTrees(n-i,base+i);
            for( int j = 0 ; j < left.size() ; j++ )
                for( int k = 0 ; k < right.size() ; k++ )
                {
                    TreeNode* p = new TreeNode(i+base);
                    p->left = left[j];
                    p->right = right[k];
                    result.push_back(p);
                }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(n,0);
    }
};
