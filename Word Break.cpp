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
