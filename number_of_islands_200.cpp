class Solution {
public:
    void dfs(int i,int j,int &m,int &n,unordered_map <int,bool> &visited,vector<vector<char>>& grid)
    {
        visited[(n*i)+j]=true;
        //top;
        if(i>=1)
        {
            if(grid[i-1][j]=='1' && visited[(n*(i-1))+j]==false)
            {
                dfs(i-1,j,m,n,visited,grid);
            }
        }

        //down
        if(i<=m-2)
        {
            if( grid[i+1][j]=='1' && visited[(n*(i+1))+j]==false)
            {
                dfs(i+1,j,m,n,visited,grid);
            }
        }

        //left
        if(j>=1)
        {
            if(grid[i][j-1]=='1' && visited[(n*(i))+j-1]==false)
            {
                dfs(i,j-1,m,n,visited,grid);
            }
        }

        //right
        if(j<=n-2)
        {
            if(grid[i][j+1]=='1' && visited[(n*(i))+j+1]==false)
            {
                dfs(i,j+1,m,n,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        unordered_map <int,bool> visited;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[(n*i)+j] == false)
                {
                    count++;
                    dfs(i,j,m,n,visited,grid);
                }
            }
        }
        return count;
    }
};