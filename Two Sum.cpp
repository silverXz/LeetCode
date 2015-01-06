// My Own lame solution. 
// Key Point: You have to record the original indices of every integer before sort them.

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> res;
        multimap<int,int> numbers_map;
        for( int i = 0 ; i < numbers.size() ; i++ )
        {
            numbers_map.insert(pair<int,int>(numbers[i],i));
        }
        
        multimap<int,int>::iterator itr_left = numbers_map.begin();
        multimap<int,int>::iterator itr_right = numbers_map.end();
        itr_right--;
        while( itr_left != itr_right )
        {
            if( itr_left->first + itr_right->first > target )
                itr_right--;
            else if( itr_left->first + itr_right->first < target )
                itr_left++;
            else
            {
                res.push_back(min(itr_left->second,itr_right->second) + 1);
                res.push_back(max(itr_left->second,itr_right->second) + 1);
                break;
            }
        }
        return res;
        
    }
};
