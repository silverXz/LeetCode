// Solution 1:
// Sort it, then return the middle element
// O(nlogn)

class Solution {
public:
    int majorityElement(vector<int> &num) 
    {
        sort(num.begin(),num.end());
        return num[num.size()/2];
    }
};


//Solution 2:
// eliminate different elements, then return the left.
// O(n)

class Solution {
public:
    int majorityElement(vector<int> &num) 
    {
        int major = num[0];
        int times = 0;
        for( int i = 0 ; i < num.size() ; i++ )
            if( major == num[i])
                times++;
            else
            {
                if( --times == 0 )
                    major = num[i+1];
            }
        return major;
    }
};
