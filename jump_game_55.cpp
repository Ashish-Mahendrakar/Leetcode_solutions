class Solution {
public:
    int min(int a,int b)
    {
        if(a<b)
        {
            return a;
        }
        return b;
    }
    bool canJump(vector<int>& nums) {
        int cur=0;
        int n=nums.size()-1;
        int prev=0;
        while(cur<n)
        {
            int reach=cur+nums[cur];
            if(reach>=n)
            {
                return true;
            }
            int index=cur;
            
            for(int i=cur+1;i <=  min(nums.size()-1,cur+nums[cur]);i++)
            {
                if(reach <(i+nums[i]))
                {
                    reach=i+nums[i];
                    index=i;
                }
            }
            if(index == cur)
            {
                return false;
            }
            else
            {
                cur=index;
            }
        }
        return true;
    }
};