class Solution {
public:
    void rr(vector<int>&ans,vector<vector<int>>& matrix,vector<vector<int>>& flag,int &count,int i,int j,int &mod)
    {
        // if(count ==0 && flag[i][j] !=0)
        // {
        //     return;
        // }
        ans.push_back(matrix[i][j]);
        flag[i][j]=1;
        count--;
        if(count == 0)
        {
            return;
        }

        if(mod == 0)
        {
            if(((j+1) < matrix[0].size()) && flag[i][j+1] ==0)
            {
                rr(ans,matrix,flag,count,i,j+1,mod);
            }
            else
            {
                mod=mod+1;
                mod=mod%4;
                rr(ans,matrix,flag,count,i+1,j,mod);
            }
        }

        else if(mod==1)
        {
            if(((i+1) < matrix.size()) && flag[i+1][j] ==0)
            {
                rr(ans,matrix,flag,count,i+1,j,mod);
            }
            else
            {
                mod=mod+1;
                mod=mod%4;
                rr(ans,matrix,flag,count,i,j-1,mod);
            }
        }
        else if(mod ==2)
        {
            if(((j-1) >=0) && flag[i][j-1] ==0)
            {
                rr(ans,matrix,flag,count,i,j-1,mod);
            }
            else
            {
                mod=mod+1;
                mod=mod%4;
                rr(ans,matrix,flag,count,i-1,j,mod);
            }
        }

        else if(mod ==3)
        {
            if(((i-1) >=0) && flag[i-1][j] ==0)
            {
                rr(ans,matrix,flag,count,i-1,j,mod);
            }
            else
            {
                mod=mod+1;
                mod=mod%4;
                rr(ans,matrix,flag,count,i,j+1,mod);
            }
        }

        
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> flag(m,vector<int>(n,0));
        vector<int>ans;
        int count=m*n;
        int i=0,j=0;
        int mod=0;


        rr(ans,matrix,flag,count,i,j,mod);
        return ans;
    }
};