class Solution {
public:
    void rr(int min,int k,vector<int> &temp,vector<vector<int>> &ans,int n)
    {
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }

        if(min == n)
        {
            return;
        }

        for(int i=min+1;i<=n;i++)
        {
            temp.push_back(i);
            rr(i,k-1,temp,ans,n);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1;i<=n;i++)
        {
            temp.push_back(i);
            rr(i,k-1,temp,ans,n);
            temp.pop_back();
        }
        return ans;
    }
};