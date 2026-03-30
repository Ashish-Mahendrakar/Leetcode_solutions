class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=i+1;j<nums.size();j++)
                    {
                        if(nums[i]==1 && nums[j]==2)
                        {
                            if(j-i < ans)
                            {
                                ans=j-i;
                            }
                        }
                        else if(nums[j]==1 && nums[i]==2)
                        {
                            if(j-i < ans)
                            {
                                ans=j-i;
                            }
                        }
                    }
            }
        if(ans==INT_MAX)
        {
            return -1;
            
        }
        return ans;
    }
};