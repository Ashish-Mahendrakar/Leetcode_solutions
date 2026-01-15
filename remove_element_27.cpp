class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end)
        {
            if(nums[start]==val && nums[end]==val)
            {
                end--;

            }
            else if(nums[start]==val && nums[end]!=val)
            {
                swap(nums[start],nums[end]);
                start++;
                end--;
            }
            else if(nums[start]!=val && nums[end]==val)
            {
                start++;
                end--;
            }
            else 
            {
                start++;
            }
        }
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            return nums.size();
        }
        return index;
    }
};