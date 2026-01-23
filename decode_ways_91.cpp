class Solution {
public:
    int numDecodings(string s) {
        

        vector<int> dp(s.length()+1,INT_MIN);
        dp[0]=1;
        if(s[0]!='0')
            dp[1]=1;
        else
            dp[1]=0;

        for(int i=2;i<=s.length();i++)
        {
            dp[i]=dp[i-1];
            string temp;
            if(s[i-1]=='0')
            {
                dp[i]=0;
            }
            
            temp.push_back(s[i-2]);
            temp.push_back(s[i-1]);

            int no=stoi(temp);

            if(no<=26 && no>=10)
            {
                dp[i]=dp[i]+dp[i-2];
            }
        }
        return dp[s.length()];
    }
};