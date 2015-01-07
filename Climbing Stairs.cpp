class Solution {
public:
    // f(n) = f(n-1) + f(n-2)
    // f(1) = 1;
    // f(2) = 2;
    // recursive way leads to time exceeding.
    int climbStairs(int n) 
    {
        if( 1 == n )
            return 1;
        if( 2 == n )
            return 2;
            
        int pre1 = 2, pre2 = 1, res = 0;

        for( int i = 3 ; i <= n ; i++ )
        {
            res = pre1 + pre2;
            pre2 = pre1;
            pre1 = res;
        }
        return res;
    }
};
