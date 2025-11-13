class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();
        //transpose
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse
        for(int i=0;i<len;i++)
        {
            int start=0;
            int end=len-1;
            while (start<end)
            {
                swap(matrix[i][start],matrix[i][end]);
                start++;end--;
            }
        }


    }
};