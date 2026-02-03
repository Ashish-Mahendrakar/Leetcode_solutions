class Solution {
public:
    bool rr(vector<vector<int>>& grid,int i,int j,int step)
    {
        //cout<<i<<" "<<j<<endl;
        int n=grid.size();
        if(step==((n*n)-1))
        {
            return true;
        }
        
        bool ans=false;

        if(i-2>=0 && j+1<n  && grid[i-2][j+1]==step+1)
        {
            
            ans=rr(grid,i-2,j+1,step+1);
            return ans;
        }

        else if(i-1>=0 && j+2<n  && grid[i-1][j+2]==step+1)
        {
            ans=rr(grid,i-1,j+2,step+1);
            return ans;

        }

        else if(i+1<n && j+2<n  && grid[i+1][j+2]==step+1)
        {
            ans=rr(grid,i+1,j+2,step+1);
            return ans;

        }

        else if(i+2<n && j+1<n  && grid[i+2][j+1]==step+1)
        {
            ans=rr(grid,i+2,j+1,step+1);
            return ans;

        }

        else if(i+2<n && j-1>=0  && grid[i+2][j-1]==step+1)
        {
            ans=rr(grid,i+2,j-1,step+1);
            return ans;

        }

        else if(i+1<n && j-2>=0  && grid[i+1][j-2]==step+1)
        {
           ans=rr(grid,i+1,j-2,step+1);
           return ans;

        }

        else if(i-1>=0 && j-2>=0  && grid[i-1][j-2]==step+1)
        {
            ans=rr(grid,i-1,j-2,step+1);
            return ans;

        }

        else if(i-2>=0 && j-1>=0  && grid[i-2][j-1]==step+1)
        {
            ans=rr(grid,i-2,j-1,step+1);
            return ans;
        }
        else
        {
            return ans;
        }



        
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        
        int step=0;
        

        if(grid[0][0]!=0)
        {
            return false;
        }

        bool ans=rr(grid,0,0,step);
        return ans;
    }
};