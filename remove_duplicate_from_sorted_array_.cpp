class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<len;i++)
        {
            if(nums[i] != ans.back())
            {
                ans.push_back(nums[i]);
            }
        }
        nums=ans;
        return ans.size();
        
    }
};