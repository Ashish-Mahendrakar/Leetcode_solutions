class Solution {
public:
    void changecol(int j,vector<vector<int>>& matrix)
    {
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i][j]=0;
        }
    }
    void changerow(int i,vector<vector<int>>& matrix)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            matrix[i][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector <pair<int,int>> ind;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    pair<int,int> temp;
                    temp.first=i;
                    temp.second=j;
                    ind.push_back(temp);
                }
            }
        }

        for(auto i : ind)
        {
            changerow(i.first,matrix);
            changecol(i.second,matrix);
        }
    }
};