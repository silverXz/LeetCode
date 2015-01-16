// Key #1 : For a word with a length n, there're are 26 * n possible next word. Find those words that in the dictionary and make
//          them the start of the next step. At the same time, the step counter should increment itself with 1.
// Key #2 : We use STL queue to store the words we found each step and the step number we've made so far. Kind of like the BFS.

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
