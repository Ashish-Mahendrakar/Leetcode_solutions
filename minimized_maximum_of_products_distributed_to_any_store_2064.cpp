class Solution {
public:
    bool check(vector<int>& quantities,int max,int &n)
    {
        int count=0;
        for(int i=0;i<quantities.size();i++)
        {
            count=count+((quantities[i]+max-1)/max);
            //cout<<count<<endl;
        }
        
        if(count>n)
        {
            return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1;
        int end=quantities[0];
        for(int i=0;i<quantities.size();i++)
        {
            if(end<quantities[i])
            {
                end=quantities[i];
            }
        }

        int ans=end;
        while(start <= end)
        {
            
            
            int mid=(start+end)/2;
            //cout<<start<<" "<<mid<<" "<<end<<endl;
            bool status=check(quantities,mid,n);
            //cout<<status<<" "<<mid<<endl;
            if(status)
            {
                //cout<<"h"<<endl;
                if(ans>mid)
                {
                    ans=mid;
                }
                end=mid-1;
                //cout<<mid<<" "<<end<<endl;
            }
            else
            {
                start=mid+1;
            }
        }

        return ans;
    }
};