class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if( B == 0 || n <= 0 )
            return;
        if( A == 0 )
            return;
        int cursor = m + n - 1;
        int curA = m - 1;
        int curB = n - 1;
        while( cursor >= 0 && curB >= 0 )
        {
            if( curA < 0 )
            {
                A[cursor--] = B[curB--];
            }
            else
            {
                if( A[curA] >= B[curB] )
                    A[cursor--] = A[curA--];
                else
                    A[cursor--] = B[curB--];
            }
        }
    }
};
