class compare{
    public:
        bool operator()(int a,int b)
        {
            return a>b;
        }
};
class Solution {
public:
    
    int fact(int n,vector<int> & dp)
    {
        if(n==1 || n==0)
        {
            dp[n]=1;
            return 1;
        }

        if(dp[n]!=0)
        {
            return dp[n];
        }

        dp[n]=n*fact(n-1,dp);
        return dp[n];
    }
    string getPermutation(int n, int k) {
        int pk=k;
        vector<int> dp(n+1,0);
        dp[0]=1;dp[1]=1;
        int t=fact(n,dp);
        //cout<<dp[n];
        priority_queue <int,vector<int>,compare> q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        //cout<<q.size()<<" "<<q.top()<<endl;
        string ans;
        while(n>1)
        {
            //cout<<dp[n-1]<<" "<<n-1<<endl;
            int nxt=(k-1)/dp[n-1];
            n--;

            k=k-(nxt*dp[n]);
           
            
            vector<int> temp;
            while(nxt >0)
            {
                int tp=q.top();
                q.pop();
                temp.push_back(tp);
                nxt--;
            }
            //cout<<temp.size()<<endl;

            int tp=q.top();
            q.pop(); 
            char ch=(char)(tp+48);
            ans.push_back(ch);
            for(auto i : temp)
            {
                q.push(i);
            }
        }
        if(!q.empty())
        {
            int tp=q.top();
            q.pop(); 
            char ch=(char)(tp+48);
            ans.push_back(ch);
        }
        //cout<<ans;
        return ans;
    }
};