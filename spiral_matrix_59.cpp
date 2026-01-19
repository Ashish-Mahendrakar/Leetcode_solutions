class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int start =1;
        int end=n*n;
        int i=0;
        int j=0;
        int mod=0;

        //unordered_map <pair<int,int>,bool> mp;

        while(start <= end)
        {
            cout<<i<<" "<<j<<" "<<start<<endl;
            ans[i][j]=start;
            start++;
            if(mod==0)
            {
                if(j<n-1 && ans[i][j+1]==0)
                {
                    j++;
                }
                else
                {
                    i++;
                    mod=1;
                }
            }
            else if(mod==1)
            {
                if(i<n-1 && ans[i+1][j]==0)
                {
                    i++;
                }
                else
                {
                    j--;
                    mod=2;
                }
            }
            else if(mod==2)
            {
                if(j>0 && ans[i][j-1]==0)
                {
                    j--;
                }
                else
                {
                    i--;
                    mod=3;
                }
            }
            else 
            {
                if(i>0 && ans[i-1][j]==0)
                {
                    i--;
                }
                else
                {
                    j++;
                    mod=0;
                }
            }

        }
        return ans;
    }
};