class Solution {
public: 
    bool pal(string &s)
    {
        int start=0;
        int end=s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void rr(string &s,int i,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return;
        }

        if(i>s.length())
        {
            return;
        }

        for(int j=i;j<=s.length();j++)
        {
            //cout<<i<<" "<<j<<endl;
            string sub=s.substr(i,j-i+1);
            bool status=pal(sub);
            if(status)
            {
                temp.push_back(sub);
                rr(s,j+1,temp,ans);
                temp.pop_back();

            }
            
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        int i=0;
        rr(s,i,temp,ans);
        return ans;
    }
};