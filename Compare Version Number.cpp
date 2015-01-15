// It's easy to come up with the sultion, but there are a lot of conditions to be considered which makes the AC rates
// low.


class Solution {
public:
    int find(const string& s,char t)
    {
        for( int i = 0 ; i < s.length() ; i++ )
        {
            if( s[i] == t )
                return i;
        }
        return -1;
    }
    
    int str2int(const string& s)
    {
        int res = 0;
        for( int i = 0 ; i < s.length() ; i++ )
            res = res * 10 + s[i] - '0';
        return res;
    }
    
    int getMajor(const string& s)
    {
        int dotPos = find(s,'.');
        if( dotPos != -1 ) // we have a dot
        {
            string majorStr = s.substr(0,dotPos);
            return str2int(majorStr);
        }
        else  // we don't have a dot.
            return str2int(s);
    }
    
    string getMinorStr(const string& s)
    {
        string res;
        int dotPos = find(s,'.');
        if( dotPos != -1 ) // we have a dot
        {
            res = s.substr(dotPos+1,s.length() - dotPos -1 );
        }
        return res;
    }
    
    int compareVersion(string version1, string version2) 
    {
        int major1 = getMajor(version1);
        int major2 = getMajor(version2);
        if( major1  > major2 )
            return 1;
        else if( major1 == major2 )
        {
            string sub1 = getMinorStr(version1);
            string sub2 = getMinorStr(version2);
            if( sub1 == sub2 )
                return 0;
            else
                return compareVersion(sub1,sub2);
        }
        else
            return -1;
    }
};
