class Solution {
public:
    string reverseWords(string s) {
        string temp;
        stack<string>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(temp!="")
                {
                    //cout<<temp<<endl;
                    st.push(temp);
                    temp.clear();
                }
            }
            else
            {
                temp.push_back(s[i]);
                //cout<<temp<<endl;
            }
        }

        if(temp!="")
        {
            //cout<<temp<<endl;        
            st.push(temp);
                    
        }
        s.clear();
        while(!st.empty())
        {
            temp=st.top();
            st.pop();
            s=s+temp+" ";
        }
        s.pop_back();

        return s;
    }
};