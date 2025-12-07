class Solution {
public:
    int compress(vector<char>& chars) {
        string ans;
        ans.push_back(chars[0]);
        int count=1;
        char last_ch=chars[0];
        //cout<<ans<<endl;
        for(int i=1;i<chars.size();i++)
        {
            if(last_ch == chars[i])
            {
                count++;
            }
            else
            {
                if(count > 1)
                {
                    ans=ans+to_string(count);
                    count=1;
                    ans.push_back(chars[i]);
                    last_ch=chars[i];
                }
                else
                {
                    count=1;
                    ans.push_back(chars[i]);
                    last_ch=chars[i];
                }
            }
        }
        if(count != 1)
        {
            ans=ans+to_string(count);
        }
        //cout<<ans;
        for(int i=0;i<ans.length();i++)
        {
            chars[i]=ans[i];
        }
        return ans.length();
    }
};