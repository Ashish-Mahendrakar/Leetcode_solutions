class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1)
        {
            vector <int> temp;
            temp.push_back(0);
            temp.push_back(1);
            return temp;
        }

        vector<int> n_1=grayCode(n-1);
        vector<int> ans=n_1;
        reverse(n_1.begin(),n_1.end());
        for(int i=0;i<n_1.size();i++)
        {
            int ad=pow(2,n-1);
            n_1[i]=n_1[i]+ad;
        }

        for(int i=0;i<n_1.size();i++)
        {
            ans.push_back(n_1[i]);
        }
        
        return ans;
    }
};