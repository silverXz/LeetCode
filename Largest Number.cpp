// Key #1: Convert int to string.
// Key #2: Sort the string array with approperiate compare function.
// Key #3: Take care of some specially inputs such as [0,0,0].

class Solution {
public:

    static bool cmp(const string& s1, const string& s2)
    {
        return s2 + s1 < s1 + s2;
    }

    string largestNumber(vector<int> &num) {
        vector<string> s;
        for( int i = 0 ; i < num.size() ; i++ )
            s.push_back(to_string(num[i]));
        sort(s.begin(),s.end(),cmp);
        string res;
        if( s.empty() )
            return res;
        if( s[0] == "0" )
            return "0";
        for( int i = 0 ; i < s.size() ; i++ )
            res += s[i];
        return res;
    }
};
