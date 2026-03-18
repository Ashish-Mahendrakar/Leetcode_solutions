class Solution {
public:
    void rr(int i,vector<int>& nums, int &target,long cost,int &ans)
    {
        if(i==nums.size())
        {
            if(cost == target)
            {
                ans++;
            }
            return;
        }

        // -ve
        rr(i+1,nums,target,cost-nums[i],ans);

        //+ve
        rr(i+1,nums,target,cost+nums[i],ans);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        long cost=0;
        rr(0,nums,target,cost,ans);
        return ans;
    }
};