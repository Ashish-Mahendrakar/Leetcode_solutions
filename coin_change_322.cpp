class Solution {
public:
    int rr(vector<int>& coins, int amount,vector<int> &dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(dp[amount] != -2)
        {
            return dp[amount];
        }

        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            if(amount-coins[i]>=0)
            {
                int ans1=rr(coins,amount -  coins[i],dp);
                if(ans1 != INT_MAX)
                {
                    ans1++;
                }
                ans=min(ans,ans1);
            }
            
        }
        dp[amount]=ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        int  ans=rr(coins,amount,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};