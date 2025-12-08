class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seive_array(n+1,true);
        int sqrtn=sqrt(n);
        //cout<<sqrtn<<endl;
        int count=0;
        //cout<<seive_array.size()<<"h";
        
        for(int i=2;i<=sqrtn+1;i++)
        {
            if(seive_array[i]==true)
            {
              long j=i*i;
              //int increment=2;
              while(j<=n)
                {
                  // cout<<j<<" "<<" "<<seive_array[j]<<" "<<endl;
                   seive_array[j]=false;
                   //cout<<j<<endl;
                   j=j+i;
                   //increment++;
                }
                //cout<<i<<endl;
                //count++;
            }

        }

        for(int i=2;i<n;i++)
        {
            if(seive_array[i])
             count++;
        }

        
        

        return count;
    }
};