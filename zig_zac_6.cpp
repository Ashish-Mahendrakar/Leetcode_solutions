class Solution {
public:
    void print(vector<vector<char>> &temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        vector<vector<char>> temp(numRows,vector<char>(1000,'@'));
        temp[0][0]=s[0];
        int mode=1;
        string ans;
        int i=1;
        int j=0;
        int k=1;
        while(i<numRows && j<temp[0].size() && k<s.length())
        {
            if(mode==1)
            {
                if(i != numRows-1)
                {
                    temp[i][j]=s[k];
                    i++;
                    k++;

                }
                else
                {
                    temp[i][j]=s[k];
                    i--;
                    k++;
                    j++;
                    mode=2;
                }
            }
            else
            {
                if(i!=0)
                {
                    temp[i][j]=s[k];
                    i--;
                    k++;
                    j++;
                }
                else
                {
                    temp[i][j]=s[k];
                    i++;
                    k++;
                    mode=1;
                }
            }
        }
        //print(temp);

        for(i=0;i<temp.size();i++)
        {
            for(j=0;j<temp[0].size();j++)
            {
                if(temp[i][j] != '@')
                {
                    ans.push_back(temp[i][j]);
                }
            }
        }

        return ans;

    }
};