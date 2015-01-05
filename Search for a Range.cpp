class Solution {
public:
    int binSearch(int* data,int len,int target)
    {
        if( 0 == data )
            return -1;
        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
            int mid = left + ( right - left ) / 2;
            if( target < data[mid] )
                right = mid - 1;
            else if( target > data[mid] )
                left = mid + 1;
            else
                return mid;
        }
        return -1;
        
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        if( A == 0 )
        {
            return vector<int>(2,-1);
        }
        int index = binSearch(A,n,target);
        if( index == -1 )
            return vector<int>(2,-1);
        int left = index;
        while( A[left] == target && left >= 0 )
            left--;
        int right = index;
        while( A[right] == target && right < n)
            right++;
        vector<int> res;
        res.push_back(left >= 0 ? left + 1 : 0 );
        res.push_back(right < n ? right - 1 : n-1);
        return res;
    }
};
