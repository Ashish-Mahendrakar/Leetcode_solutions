class Solution {
public:
    int minimum(int a,int b)
    {
        if(a<b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int jump(vector<int>& nums) {
        int cur=0;
        int j=0;
        int n=nums.size()-1;
        while(cur < n)
        {
            int reach=0;
            int index=-1;
            if((cur+nums[cur]) >= (nums.size()-1))
            {
                return j+1;
            }
            for(int i=cur+1;i<=(cur+nums[cur]);i++)
            {
                if(reach < (i+nums[i]))
                {
                    reach=(i+nums[i]);
                    
                    index=i;

                }
            }
            j++;
            cur=index;
            //cout<<cur<<endl;

        }

        return j;
    }
};