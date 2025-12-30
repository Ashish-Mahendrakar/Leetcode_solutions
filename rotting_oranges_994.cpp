class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int min=0;
       int m=grid.size();
       int n=grid[0].size();
       
       queue <int> q;
       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                q.push((n*i)+j);

            }
        }
       }
       q.push(-1);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(curr==-1)
            {
                // for(int i=0;i<m;i++)
                // {
                //     for(int j=0;j<n;j++)
                //         {
                //             cout<<grid[i][j]<<" ";
                //         }
                //         cout<<endl;
                // }
                // cout<<endl;
                min++;
                if(q.empty())
                {
                    break;
                }
                else
                {
                   q.push(-1); 
                   continue;
                }
            }

            int i=curr/n;
            int j=curr%n;

            //top
            if(i>=1 )
            {
                
                

                if(grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    q.push((n*(i-1))+j);
                }
            }

            //down
            if(i<=m-2 )
            {
                
                

                if(grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    q.push((n*(i+1))+j);
                }
            }

            //left
            if(j>=1 )
            {
                
                

                if(grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    q.push((n*(i))+j-1);
                }
            }

            //right
            if(j<=n-2 )
            {
                
                

                if(grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    q.push((n*(i))+j+1);
                }
            }
        }

       for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                        {
                            if(grid[i][j]==1)
                            {
                                return -1;
                            }
                        }
                        //cout<<endl;
                }
                //cout<<endl; 

       return min-1;


    }
};