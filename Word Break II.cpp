
// Solution: DP records all the break points for the string. Then backtrace all possible path.


class Solution {
public:

    vector<string> pathTrace(vector<vector<int>>& path, const string& s, int id)
    {
        vector<string> result;
        if( id <= 0 )
        {
            result.push_back("");
            return result;
        }
        for( int i = 0 ; i < path[id].size() ; i++ )
        {
            string str = s.substr(path[id][i],id - path[id][i]);
            vector<string> subStr = pathTrace(path,s,path[id][i]);
            for( int j = 0 ; j < subStr.size() ; j++ )
            {
                if( subStr[j].size() == 0 )
                    result.push_back(str);
                else
                    result.push_back(subStr[j] + " " + str);
            }
        }
        return result;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) 
    {
        vector<bool> dp(s.length()+1,false);
        dp[0] = true;
        vector<vector<int>> path(s.length() + 1);
        path[0].push_back(0);
        for( int i = 1; i <= s.length() ; i++ )
        {
            for( int j = i-1 ; j >= 0 ; j-- )
            {
                if( dp[j] && dict.find(s.substr(j,i-j)) != dict.end() )
                {
                    dp[i] = true;
                    path[i].push_back(j);
                }
            }
        }
        return pathTrace(path,s,s.length());
    }
};
