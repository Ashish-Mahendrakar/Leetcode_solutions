class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        vector<vector<int>> dp(m,vector<int> (n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {

                if(dp[i][j] == 0)
                {
                    //left
                    int left=0;
                    if(j>=1)
                    {
                        left=dp[i][j-1];
                    }

                    //right
                    int right=0;
                    if(i>=1)
                    {
                        right=dp[i-1][j];
                    }
                    dp[i][j]=left+right;
                }
                

            }
        }
        return dp[m-1][n-1];
    }
};