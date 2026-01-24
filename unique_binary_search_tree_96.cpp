class Solution {
public:
    int anss(int n,vector<int> &dp)
    {
        if(n==0)
        {
            dp[0]=0;
            return 0;
        }

        if(n==1)
        {
            dp[1]=1;
            return 1;
        }

        if(n==2)
        {
            dp[2]=2;
            return 2;
        }

        if(dp[n]!=INT_MIN)
        {
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int left=i-1;
            int right=n-i;

            int ans1=anss(left,dp);
            int ans2=anss(right,dp);
            if(left==0 || right==0)
                ans=ans+ans2+ans1;
            else
            {
                ans=ans+(ans2*ans1);
            }
        }
        dp[n]=ans;
        return ans;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,INT_MIN);
        return anss(n,dp);
    }
};