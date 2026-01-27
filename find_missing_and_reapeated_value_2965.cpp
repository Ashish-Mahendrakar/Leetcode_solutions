class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int ex=((n*n)*((n*n)+1))/2;
        int sum=0;
        int a=0;
        vector<int> freq((n*n)+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum=sum+grid[i][j];
                freq[grid[i][j]]++;
                if(freq[grid[i][j]]==2)
                {
                    a=grid[i][j];
                }
            }
        }
        //cout<<ex<<" "<<sum<<endl;
        int b_a=ex-sum;
        int b=b_a +a;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};