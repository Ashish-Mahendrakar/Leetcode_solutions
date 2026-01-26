class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> ans;
        vector<int> temp(1,1);
        ans.push_back(temp);
        if(n==1)
        {
            return ans;
        }
        temp.push_back(1);
        ans.push_back(temp);
        if(n==2)
        {
            return ans;
        }

        temp.clear();
        int c=2;
        while(c<n)
        {
            c++;
            vector<int> temp1(c,1);
            for(int i=1;i<temp1.size()-1;i++)
            {
                temp1[i]=ans.back()[i-1] + ans.back()[i];
            }

            ans.push_back(temp1);
        }

        return ans;
    }
};