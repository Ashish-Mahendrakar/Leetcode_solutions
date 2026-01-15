class Solution {
public:
    void rr(string temp,set <string> &s,unordered_map <char,string>&mp,int i,string &digits)
    {
        if(i>=temp.size())
        {
            return;
        }
        for(int j=0;j<mp[digits[i]].length();j++)
        {
            temp[i]=mp[digits[i]][j];
            s.insert(temp);
            rr(temp,s,mp,i+1,digits);

        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp;
        vector <string> ans;
        set <string> s;
        for(int i=0;i<digits.length();i++)
        {
            temp.push_back(mp[digits[i]][0]);
        }
        rr(temp,s,mp,0,digits);
        for(auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};