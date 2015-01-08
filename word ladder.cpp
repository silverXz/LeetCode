class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        unordered_set<string> copy(dict);
        queue<string> qString;
        qString.push(start);
        queue<int> qStep;
        qStep.push(1);
        while(!qString.empty())
        {
            for( int i = 0 ; i < qString.front().length() ; i++ )
            {
                for( char j = 'a' ; j <= 'z' ; j++ )
                {
                    string tmp = qString.front();
                    tmp[i] = j;
                    if( tmp == end )
                        return qStep.front() + 1 ;
                    else
                    {
                        if( copy.count(tmp) > 0 ) // in the dictionary
                        {
                            qString.push(tmp);
                            qStep.push(qStep.front()+1);
                            copy.erase(tmp);
                        }
                    }
                }
            }
            qString.pop();
            qStep.pop();
        }
        return 0;
    }
};
