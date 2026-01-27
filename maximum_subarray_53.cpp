class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        int max=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            //cout<<sum<<endl;
            sum=sum+nums[i];
            
            if(nums[i]>max)
            {
                max=nums[i];
            }
            
            if(sum<0)
            {
                sum=0;
            }

            if(sum>ans)
            {
                
                ans=sum;
                cout<<ans<<endl;
            }
        }
        if(max<=0 )
        {
            return max;

        }

        return ans;
    }
};