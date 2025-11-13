class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        int max_sum=0;
        int index=0;
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum=sum+mat[i][j];

            }
            if(sum>max_sum)
            {
                max_sum=sum;
                index=i;
            }
            sum=0;
        }
        vector<int> ans(2,0);
        ans[0]=index;
        ans[1]=max_sum;
        return ans;
        
    }
};