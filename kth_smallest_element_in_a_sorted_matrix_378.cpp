class compare{
    public: 
        bool operator()(int a,int b)
        {
            return a<b;
        }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <int,vector<int>,compare> pq;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(pq.size()<k)
                {
                    //cout<<"h"<<endl;
                    pq.push(matrix[i][j]);
                }
                else
                {
                    if(pq.top() > matrix[i][j])
                    {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        
        return pq.top();
    }
};