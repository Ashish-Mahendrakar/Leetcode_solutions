class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> temp;
        pair<char,int> f;
        f.first=s[0];
        f.second=1;
        temp.push_back(f);

        int i=1;
        int len=s.length();
        while(i<len)
        {
            
            if(temp.size()>=1 &&s[i] == temp.back().first)
            {
                temp.back().second++;
                if(temp.back().second == k)
                {
                    temp.pop_back();
                }
            }
            else
            {
                pair<char,int>current;
                current.first=s[i];
                current.second=1;
                temp.push_back(current);
            }
            i++;
        
        }

        string ans;


        for (auto j : temp)
        {
            int m=0;
            while(m<j.second)
            {
                ans.push_back(j.first);
                m++;
            }
        }
        return ans;

    }
};