class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> ans(n+1,0);
        vector<long> speaker(n+1,0);
        vector<long> told(n+1,0);
        int mod=1000000007;
        for(int i=1;i<=delay;i++)
        {
            speaker[i]=0;
            told[i]=0;
            ans[i]=1;
        }
        speaker[delay+1]=1;
        told[delay+1]=1;
        told[1]=1;
        ans[delay+1]=2;
        for(int i=delay+2;i<=n;i++)
        {
            // if(ans[i-1]>=1000000007)
            // {
            //     return 1000000007;
            // }
            speaker[i]=speaker[i-1];
            //minus forget today
            if(i-forget>=1)
                 {
                    speaker[i]=(speaker[i]%mod)-(told[i-forget]%mod);
                    speaker[i]=speaker[i]%mod;
                    ans[i]=0-told[i-forget];
                    ans[i]=ans[i]%mod;
                 }

            //plus today active
            if(i-delay>=1)
                 {speaker[i]=(speaker[i]%mod)+(told[i-delay]%mod);speaker[i]=speaker[i]%mod;}

            //told today
            told[i]=speaker[i];

            //secret know today
            ans[i]=ans[i]+ans[i-1]+told[i];
            ans[i]=ans[i]%mod;
            
        }
        //cout<<mod+ans[n];
        if(ans[n]<=0)
            return mod+ans[n];
        return ans[n];
    }
};