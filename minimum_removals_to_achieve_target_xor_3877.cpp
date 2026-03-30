class Solution {
public:
    int rr(vector<int>& nums, int target,int i,vector<vector<int>> &dp)
    {
        if(i==nums.size())
        {
            if(target==0)
            {
                return 0;
            }
            else
            {
                return INT_MAX;
            }
        }

        if(dp[target][i] != -2)
        {
            return dp[target][i];
        }

        //exclude
        int ans1=rr(nums,target,i+1,dp);
        if(ans1 != INT_MAX)
        {
            ans1++;
        }

        //include
        int ans2=rr(nums,target^nums[i],i+1,dp);

        dp[target][i]=min(ans1,ans2);
        return min(ans1,ans2);
        
        
    }
    int minRemovals(vector<int>& nums, int target) {
        int max=target;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>max)
                {
                    max=nums[i];
                }
            }
        vector<vector<int>> dp(2*max+1,vector<int>(nums.size(),-2));
        int ans=rr(nums,target,0,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};