class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted;
        for(auto i: strs)
        {
            string temp=i;
            sort(temp.begin(),temp.end());
            sorted.push_back(temp);
        }

        map<string,vector<int>> mp;
        for(int i=0;i<sorted.size();i++)
        {
            string temp=sorted[i];
            
            mp[temp].push_back(i);
            
        }

        vector<vector<string>> ans;
        for(auto i : mp)
        {
            vector<string>temp;
            for(int j=0;j<i.second.size();j++)
            {
                temp.push_back(strs[i.second[j]]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};