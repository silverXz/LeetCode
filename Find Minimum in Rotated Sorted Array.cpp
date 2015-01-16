class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size()-1;
        while(low < high)
        {
            int mid = low + ( high - low ) / 2;
            if( num[mid] <= num[high] )
                high = mid;
            else
                low = mid + 1;
        }   
        return num[low];
    }
};
