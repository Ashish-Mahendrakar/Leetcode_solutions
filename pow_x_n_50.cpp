class Solution {
public:
    double fast(double x, int n)
    {
        
      if(n==0)
      {
        return 1;
      }
      if(n==1)
      {
        return x;
      }

      double ans=0;
      if(n&1)
      {
        double temp=(fast(x,n/2));
        ans=x*temp*temp;
      }
      else
      {
        double temp=(fast(x,n/2));
        ans=temp*temp;
      }
      return ans;
    }
    
    double myPow(double x, int n) {
      if(x==0)  
      {
        return 0;
      }

      if(n==0)
      {
        return 1;
      }

      if(n==1)
      {
        return x;
      }

      int sign=1;
      if(n<0)
      {
        sign=-1;
      }



      //fast expo
      double ans=0;
      if(n&1)
      {
        double temp=(fast(x,n/2));
        ans=x*temp*temp;
      }
      else
      {
        double temp=(fast(x,n/2));
        ans=temp*temp;
      }
      if(sign == -1)
      {
        return 1/ans;
      }
      return ans;
    }
};