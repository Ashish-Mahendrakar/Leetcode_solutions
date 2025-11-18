class Solution {
public:
    int rr(vector<int> &nums)
    {
        int len=nums.size();
        int start=0;
        int end=len-1;
        int ans=-1;
        while(start <= end)
        {
            int mid=(start + end)/2;
            if(mid-1>0  && nums[mid]<nums[mid])
            {
                ans=mid;
                break;
            }
            if(nums[mid]<nums[0])
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int p_index=rr(nums);
        int len=nums.size();
        if(p_index ==-1)
        {
            p_index++;
        }
        int ans=-1;
        if(target >=nums[0] && p_index !=0)
        {
            int start=0;
            int end=p_index-1;
            
            while(start<=end)
            {
                int mid=(start + end)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }

                if(nums[mid]>target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
        }
        else
        {
           int start=p_index;
           int end=len-1;

           while(start<=end)
            {
                int mid=(start + end)/2;
                if(nums[mid]==target)
                {
                    return mid;
                }

                if(nums[mid]>target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
        }
        return p_index;
    }
};