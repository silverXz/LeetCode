// I spent much time in this problem. Here are some solutions, accepted and not accepted, containing all my tries.

// Solution #1: Not acceptd. !!!!! Time Limite Excceded!
// Description: DFS alike.
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool res = false;
        for( int i = 1 ; i <= s.length() ; i++)
        {
            string tmp = s.substr(0,i);
            if(dict.count(tmp) > 0)
            {
                if( i == s.length())
                {
                    res = true;
                    break;
                }
                else
                    res = wordBreak(s.substr(i,s.length()-i),dict);
            }
        }
        return res;
    }
};

// Solution #2 : Accepted!!!!!! With Dynamical Programming!

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if( dict.size() == 0 )
            return false;
        vector<bool> dp(s.length()+1,false);
        dp[0] = true;
        for( int i = 1 ; i <= s.length() ; i++ )
        {
            for( int j = i-1; j >= 0 ; j-- )
            {
                if( dp[j] )
                {
                    if( dict.find(s.substr(j,i-j)) != dict.end() )
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
