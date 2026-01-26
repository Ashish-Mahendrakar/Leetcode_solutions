class Solution {
public:
    int rr(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=triangle.size())
        {
            return 0;
        }

        if(j>=triangle[i].size())
        {
            return 0;
        }
        if(dp[i][j]!=-10001)
        {
            return dp[i][j];
        }

        //down
        int ans1=rr(triangle,i+1,j,dp);
        int ans2=rr(triangle,i+1,j+1,dp);

        dp[i][j]=triangle[i][j]+min(ans1,ans2);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1)
        {
            return triangle[0][0];
        }
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-10001));
        int i=0;
        int j=0;
        int ans=rr(triangle,i,j,dp);
        return ans;
    }
};