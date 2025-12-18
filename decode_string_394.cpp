class Solution {
public:
    void decode(stack <string> &st,int &no)
    {
        
        if(st.empty())
        {
            return ;
        }
        
        char top=st.top()[0];
        if(top>='0' && top<='9')
        {
            int digit=(int)top -48;
            st.pop();
            decode(st,no);
            no=no*10+digit;        
        }
        
    }
    string decodeString(string s) {
       stack <string> st;
       string ans;
       for(int i=0;i<s.length();i++)
       {
            if(s[i]!=']')
            {
                string temp;
                temp.push_back(s[i]);
                st.push(temp);
            }
            else
            {
                string sub;
                while(!st.empty() && st.top() !="[")
                {
                    //cout<<sub<<endl;
                    string ch=st.top();
                    //cout<<ch<<endl;
                    st.pop();
                    sub=ch+sub;
                    //cout<<sub<<endl;
                }
                int no=0;
                if(!st.empty())
                {
                    st.pop();
                }
                decode(st,no);
                
                //cout<<no<<endl;
                string temp=sub;
                while(no!=1)
                {
                    sub=temp+sub;
                    no--;
                }
                //cout<<sub<<endl;
                st.push(sub);
            }
       }
       //string ans;
       ans="";
       while(!st.empty())
       {
        ans=st.top()+ans;
        st.pop();
       }
       return ans;
    }
};