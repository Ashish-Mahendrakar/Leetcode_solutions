class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        if(end==2)
        {
            return nums[0]^nums[1]^nums[2];
        }
        if(end==0)
        {
            return nums[0];
        }
        if(nums[1]!=nums[0])
        {
            return nums[0];
        }

        if(nums[nums.size()-1] != nums[nums.size()-2])
        {
            return nums.back();
        }
        while(start<end)
        {
            int mid=(start+end)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else 
            {
                if(mid&1 && nums[mid]==nums[mid-1])
                {
                    start=mid+1;
                }
                else if(mid&1)
                {
                    end=mid-1;
                }
                else if(nums[mid]==nums[mid+1])
                {
                    start=mid+2;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return nums[start];
    }
};