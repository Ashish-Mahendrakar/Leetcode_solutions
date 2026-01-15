class Solution {
public:
    void rr(vector<int>& nums,int i, int &target,int &ans,int &min)
    {
        int start=i+1;
        int end=nums.size()-1;
        
        while(start < end)
        {
            //cout<<"h"<<endl;
            if(nums[i]+nums[start]+nums[end]==target)
            {
                ans=target;
                return;
                
            }
            else if(nums[i]+nums[start]+nums[end] < target)
            {
                if(min>abs(nums[i]+nums[start]+nums[end]-target))
                {
                    ans=nums[i]+nums[start]+nums[end];
                    min=abs(nums[i]+nums[start]+nums[end]-target);
                }
                start++;
            }
            else
            {
                if(min>abs(nums[i]+nums[start]+nums[end]-target))
                {
                    ans=nums[i]+nums[start]+nums[end];
                    min=abs(nums[i]+nums[start]+nums[end]-target);
                }
                end--;
            }
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            rr(nums,i,target,ans,min);
        }
        return ans;
    }
};