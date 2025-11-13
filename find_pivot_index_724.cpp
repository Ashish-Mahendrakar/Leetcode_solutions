class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len=nums.size();
        int sum=0;
        for(auto i : nums)
        {
            sum=sum+i;
        }
        int lsum=0;
        for(int i=0;i<len;i++)
        {
            sum=sum-nums[i];

            if(lsum==sum)
            {
                return i;
            }
            lsum=lsum+nums[i];

        }
        return -1;
    }
};