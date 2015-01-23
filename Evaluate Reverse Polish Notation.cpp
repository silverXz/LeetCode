class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if( tokens.empty())
            return 0;
        stack<int> s;
        int a = 0;
        int b = 0;
        for( int i = 0 ; i < tokens.size() ; i++ )
        {
            if( tokens[i] == "+")
            {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b+a);
                continue;
            }
            if( tokens[i] == "-")
            {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b-a);
                continue;
            }
            if( tokens[i] == "*")
            {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b*a);
                continue;
            }
            if( tokens[i] == "/")
            {
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                s.push(b/a);
                continue;
            }
            s.push(atoi(tokens[i].c_str()));
        }
        return s.top();
    }
};
