class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0;i<obstacleGrid.size();i++)
        {
            for(int j=0;j<obstacleGrid[i].size();j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    obstacleGrid[i][j]=-1;
                }
            }
        }
        if(obstacleGrid[0][0]==-1)
        {
            return 0;
        }
        obstacleGrid[0][0]=1;
        for(int i=0;i<obstacleGrid.size();i++)
        {
            for(int j=0;j<obstacleGrid[i].size();j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    //left
                    int left=0;
                    if(j>=1 && obstacleGrid[i][j-1] !=-1)
                    {
                        left=obstacleGrid[i][j-1];
                    }

                    //up
                    int up=0;
                    if(i>=1 && obstacleGrid[i-1][j] !=-1)
                    {
                        up=obstacleGrid[i-1][j];
                    }

                    obstacleGrid[i][j]=left+up;
                }
            }
        }
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // for(int i=0;i<obstacleGrid.size();i++)
        // {
        //     for(int j=0;j<obstacleGrid[i].size();j++)
        //     {
        //         cout<<obstacleGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        if(obstacleGrid[m-1][n-1]==-1)
        {
            return 0;
        }

        return obstacleGrid[m-1][n-1];
    }
};