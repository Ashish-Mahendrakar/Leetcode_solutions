class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        vector<int> flag(len,0);
        for(auto i : nums)
        {
            if(flag[i]==1)
            {
                return i;
            }
            flag[i]=1;
        }
        return -1;

    }
};