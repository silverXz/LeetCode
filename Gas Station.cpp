// #1: Solution 1: Very Intuitive Algorithm.
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
    {
        vector<int> left(gas.size(),0);
        for( int i = 0 ; i < gas.size() ; i++ )
            left[i] = gas[i] - cost[i];
        int start = 0;
        int remain = 0;
        while( start < gas.size() )
        {
            for( int i = start ; i < start + gas.size() ; i++ )
            {
                if( (remain += left[i%gas.size()]) < 0 )  // couldn't make it to i+1, couldn't start from i either.
                {
                    start = i + 1;
                    remain = 0;
                    break;
                }
                else if( i == (start + gas.size() - 1) ) // make is a circuit!
                    return start;
            }
        }
        return -1;
    }
};

// Solution #2 : A lot more simpler! Try from the end of the chain.

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};
