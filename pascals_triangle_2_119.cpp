class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1,1);
        if(rowIndex==0)
        {
            return prev;
        }
        prev.push_back(1);
        if(rowIndex==1)
        {
            return prev;
        }

        int c=1;
        vector<int> ans;
        while(c < rowIndex)
        {
            c++;
            vector<int>temp(c+1,1);
            for(int i=1;i<temp.size()-1;i++)
            {
                temp[i]=prev[i-1]+prev[i];
            }
            prev=temp;
            ans=temp;
        }
        return ans;
    }
};