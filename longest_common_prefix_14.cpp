class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        if(len ==1)
        {
            return strs[0];
        }
        string ans;
        int j=0;
        while(j<strs[0].length()  && j<strs[1].length())
        {
            if(strs[0][j] != strs[1][j])
            {
                break;
            }
            else
            {
                ans.push_back(strs[0][j]);
                j++;
            }
        }
        //cout<<ans;
        //cout<<strs.size();
        for(int i=2;i<strs.size();i++)
        {
            if(strs[i].empty())
            {
                return "";
            }
            string temp=strs[i];
            //cout<<temp;
            int temp_len=strs[i].length();
            if(temp_len < ans.size())
            {
                ans.erase(temp_len,ans.size()-temp_len);
            }
            j=0;
            while(j<ans.length() && j<temp.length())
            {
                if(ans[j]==temp[j])
                {
                    j++;
                }
                else
                {
                    ans.erase(j,ans.length()-j);
                    break;
                }
            }
        }


        return ans;
    }
};