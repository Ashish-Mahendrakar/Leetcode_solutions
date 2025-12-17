class Solution {
public:
    bool isValid(string s) {
        stack <char> par;
        int len=s.length();
        //par.push(s[0]);
        for(int i=0;i<len;i++)
        {
            if(par.empty())
            {
                par.push(s[i]);
            }
            else if(par.top()=='(' && s[i]==')')
            {
                par.pop();
            }
            else if(par.top()=='{' && s[i]=='}')
            {
                par.pop();
            }
            else if(par.top()=='[' && s[i]==']')
            {
                par.pop();
            }
            else
            {
                par.push(s[i]);
            }
        }
        if(par.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};