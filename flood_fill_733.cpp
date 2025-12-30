class Solution {
public:
    void dfs(int i,int j,int &m,int &n,int &cur,int &color,vector<vector<int>>& image)
    {
        
        image[i][j]=color;

        //top
        if(i>=1 && image[i-1][j]==cur)
        {
            dfs(i-1,j,m,n,cur,color,image);
        }
        //down
        if(i<=m-2 && image[i+1][j]==cur)
        {
            dfs(i+1,j,m,n,cur,color,image);
        }

        //left
        if(j>=1 && image[i][j-1]==cur)
        {
            dfs(i,j-1,m,n,cur,color,image);
        }

        //right
        if(j<=n-2 && image[i][j+1]==cur)
        {
            dfs(i,j+1,m,n,cur,color,image);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int cur=image[sr][sc];
        if(cur==color)
        {
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        dfs(sr,sc,m,n,cur,color,image);
        return image;
    }
};