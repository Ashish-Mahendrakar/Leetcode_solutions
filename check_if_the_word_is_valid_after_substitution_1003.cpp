class Solution {
public:
    bool isValid(string s) {
        stack <pair<char,bool>> st;
        for(auto ch :s)
        {
            if(ch=='a')
            {
                pair<char,bool> temp;
                temp.first=ch;
                temp.second=false;
                st.push(temp);
            }
            else if(ch=='b')
            {
                pair<char,bool> temp;
                temp.first=ch;
                
                temp.second=false;
                if(!st.empty() && st.top().first=='a')
                {
                    temp.second=true;
                }
                st.push(temp);
            }
            else
            {
                if(!st.empty() && st.top().second==true)
                {
                    st.pop();
                    st.pop();
                }
                else
                {
                    pair<char,bool> temp;
                    temp.first=ch;
                    temp.second=false;
                    st.push(temp);
                }
            }
        }

        if(st.empty()) return true;


        return false;
    }
};