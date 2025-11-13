class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0;
        int n=1;
        int i=0;
        int len=nums.size();
        vector<int> ans(len,0);
        while ( i<len )
        {
            if(nums[i]>0 && p<len)
            {
                ans[p]=nums[i];
                p=p+2;
            }
            else if(n<len)
            {
                ans[n]=nums[i];n=n+2;
            }
            
            i=i+1;
        }
        return ans;
    }
};