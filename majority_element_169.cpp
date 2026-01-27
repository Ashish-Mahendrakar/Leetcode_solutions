class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=1;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            
            if(freq==0)
            {
                ans=nums[i];
                freq=1;
            }
            else
            {
                if(nums[i]==ans)
                {
                    freq++;
                }
                else
                {
                    //cout<<ans<<" "<<freq<<endl;
                    freq--;
                    //cout<<ans<<" "<<freq<<endl;
                }
            }
        }
        return ans;
    }
};