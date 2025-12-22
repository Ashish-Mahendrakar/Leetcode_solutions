class Solution {
public:
    void rr(stack <int> &st,vector <int> &ans)
    {
        if(st.empty())
        {
            return;
        }
        int temp=st.top();
        st.pop();
        rr(st,ans);
        ans.push_back(temp);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st;
        for(auto i : asteroids)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                if(st.top()>0 && i<0 )
                {
                    int temp=abs(i);
                    if(temp<st.top())
                    {
                        continue;
                    }
                    else if(temp ==st.top())
                    {
                        st.pop();
                        continue;
                    }
                    else
                    {
                        while(!st.empty() && st.top()<temp && st.top()>0)
                        {
                            st.pop();
                        }
                        if(st.empty())
                            st.push(i);
                        else if(st.top()<0)
                        {
                            st.push(i);
                        }
                        else if(st.top()==temp)
                        {
                            st.pop();
                        }
                    }
                }
                else
                {
                    st.push(i);
                }
            }
        }
        vector<int>ans;
        rr(st,ans);
        return ans;
    }
};