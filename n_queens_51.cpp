class Solution {
public:
    void remov(vector<vector<int>> &state,int m,int n)
    {
        int i=m,j=n;
        state[i][j]--;

        //down
        i=m+1;
        j=n;
        while(i<state.size())
        {
            state[i][j]--;
            i++;
        }

        //up
        i=m-1;
        j=n;
        while(i>=0)
        {
            state[i][j]--;
            i--;
        }

        //right
        i=m;
        j=n+1;
        while(j<state.size())
        {
            state[i][j]--;
            j++;
        }

        //left
        i=m;
        j=n-1;
        while(j>=0)
        {
            state[i][j]--;
            j--;
        }

        //se
        i=m+1;
        j=n+1;
        while(j<state.size() && i<state.size())
        {
            state[i][j]--;
            i++;
            j++;
        }

        //nw
        i=m-1;
        j=n-1;
        while(j>=0 && i>=0)
        {
            state[i][j]--;
            i--;
            j--;
        }

        //ne
        i=m-1;
        j=n+1;
        while(j<state.size() && i>=0)
        {
            state[i][j]--;
            i--;
            j++;
        }

        //sw
        i=m+1;
        j=n-1;
        while(i<state.size() && j>=0)
        {
            state[i][j]--;
            i++;
            j--;
        }

        
    }
    void fill(vector<vector<int>> &state,int m,int n)
    {
        int i=m,j=n;
        state[i][j]++;

        //down
        i=m+1;
        j=n;
        while(i<state.size())
        {
            state[i][j]++;
            i++;
        }

        //up
        i=m-1;
        j=n;
        while(i>=0)
        {
            state[i][j]++;
            i--;
        }

        //right
        i=m;
        j=n+1;
        while(j<state.size())
        {
            state[i][j]++;
            j++;
        }

        //left
        i=m;
        j=n-1;
        while(j>=0)
        {
            state[i][j]++;
            j--;
        }

        //se
        i=m+1;
        j=n+1;
        while(j<state.size() && i<state.size())
        {
            state[i][j]++;
            i++;
            j++;
        }

        //nw
        i=m-1;
        j=n-1;
        while(j>=0 && i>=0)
        {
            state[i][j]++;
            i--;
            j--;
        }

        //ne
        i=m-1;
        j=n+1;
        while(j<state.size() && i>=0)
        {
            state[i][j]++;
            i--;
            j++;
        }

        //sw
        i=m+1;
        j=n-1;
        while(i<state.size() && j>=0)
        {
            state[i][j]++;
            i++;
            j--;
        }

        
    }
    void print(vector<vector<int>> &temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void rr(vector<string> &temp,vector<vector<int>> &state,set <vector<string>> &ans,int k)
    {
        //print(temp);
        //cout<<k<<endl;
        if(k==state.size())
        {
            
            ans.insert(temp);
            return;
        }

        //for(int i=0;i<state.size();i++)
        //{
            for(int j=0;j<state[k].size();j++)
            {
                if(state[k][j]==0)
                {
                    //fill
                    fill(state,k,j);


                    temp[k][j]='Q';
                    rr(temp,state,ans,k+1);
                    temp[k][j]='.';

                    
                    //remove
                    remov(state,k,j);

                }
            }
        //}
        
    }
    vector<vector<string>> solveNQueens(int n) {
        set <vector<string>> s;
        vector<vector<string>> ans;
        
        vector<string> temp(n,string(n,'.'));
        vector<vector<int>> state(n,vector<int>(n,0));
        int i=0;
        rr(temp,state,s,i);
        //cout<<ans.size();
        for(auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
        
    }
};