class Solution {
public:
    int mySqrt(int x) {
        long start=1;
        long end=x;
        int ans;
        double max_res=x;
        if(x==1 || x==0)
        {
            return x;
        }

        while(start <=end)
        {
            long mid=(start+end)/2;
            double temp=mid;
            double res=(x- (temp *temp));
            if(res == 0)
            {
                ans=mid;max_res=0;break;
            }

            if(res>0)
            {
                start=mid+1;
                if(max_res > res)
                {
                    max_res=res;
                    ans=mid;
                }
                
            }
            else
                {
                    end=mid-1;
                    // if(max_res > -1*res)
                    // {
                    //     max_res=-1*res;
                    //     ans=mid;
                    // }
                }
            
        }

        return ans;
    }
};