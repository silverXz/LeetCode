class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> unique;
        unique.resize(n+1,0);
        unique[0] = 1;
        for( int i = 1; i <= n ; i++)
        {
            for( int j = 1 ; j <= i ; j++ )
                unique[i] += unique[j-1] * unique[i-j];
        }
        return unique[n];
    }
};
