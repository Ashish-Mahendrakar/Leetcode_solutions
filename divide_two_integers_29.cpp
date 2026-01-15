class Solution {
public:
    int divide(int dividend, int divisor) {
        long div=dividend;
        long dis=divisor;
        int sign=1;
        if(div <0)
        {
            sign=(-1)*sign;
            div=abs(div);
        }

        if(dis <0)
        {
           sign=(-1)*sign; 
           dis=abs(dis);
        }
        //cout<<sign<<endl;
        if(dis> div)
        {
            return 0;
        }
        else if(dis == div)
        {
            return (sign)*1;
        }
        

        long ans=1;
        long denom=dis;
        while(denom<div)
        {
            ans=ans+ans;
            denom=denom+denom;
        }

        while(denom>div)
        {
            ans--;
            denom=denom-dis;
        }
        ans=(ans)*sign;
        if(ans>INT_MAX)
        {
            return INT_MAX;
        }
        else if(ans<INT_MIN)
        {
            return INT_MIN;
        }

        return ans;
    }
};