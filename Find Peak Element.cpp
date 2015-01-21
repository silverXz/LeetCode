class Solution {
public:
    int findPeakElement(const vector<int> &num) 
    {
        return binFindPeak(num,0,num.size()-1);
    }
    
    int binFindPeak(const vector<int>& num, int left, int right)
    {
        if( left == right )
            return left;
        int mid1 = left + (right - left) / 2;
        int mid2 = mid1 + 1;
        if(num[mid1] > num[mid2])
            return binFindPeak(num,left,mid1);
        else
            return binFindPeak(num,mid2,right);
    }
};
