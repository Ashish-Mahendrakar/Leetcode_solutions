class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000)
        {
            return 0;
        }
        if(n < 1000000)
        {
            long long temp=n;
            temp=temp-1000;
            return temp+1;
        }
        long long ans=999000;
        if(n < 1000000000)
        {
            long long temp=n;
            temp=temp-1000000;
            return ans+((temp+1)*2);
        }
        ans=ans+(999000000*2);
        if(n < 1000000000000)
        {
            long long temp=n;
            temp=temp-1000000000;
            return ans+((temp+1)*3);
        }
        ans=ans+(999000000000*3);
        if(n < 1000000000000000)
        {
            long long temp=n;
            temp=temp-1000000000000;
            return ans+((temp+1)*4);
        }
        ans=ans+(999000000000000*4);

        
        return ans+5;
        
        
        
    }
};