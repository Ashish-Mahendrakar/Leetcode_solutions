class Solution {
public:
    int rrl(vector<int>& nums, int target,int start,int end,int ans)
    {
        if(start>end)
        {
            return ans;
        }
        else 
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                return rrl(nums,target,start,mid-1,ans);
            }
            else if(nums[mid]<target)
            {
                return rrl(nums,target,mid+1,end,ans);
            }
            else
            {
                return rrl(nums,target,start,mid-1,ans);
            }
        }
    }

    int rrr(vector<int>& nums, int target,int start,int end,int ans)
    {
        
        if(start>end)
        {
           // cout<<"h";
            return ans;
        }
        else 
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                //cout<<ans<<" ";
                return rrr(nums,target,mid+1,end,ans);
            }
            else if(nums[mid]<target)
            {
                return rrr(nums,target,mid+1,end,ans);
            }
            else
            {
                return rrr(nums,target,start,mid-1,ans);
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        int left=rrl(nums,target,0,len-1,-1);
        int right=rrr(nums,target,0,len-1,-1);
        vector<int> ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};