class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber >26)
        {
            int cur=columnNumber%26;
            columnNumber=columnNumber/26;
            if(cur==0)
            {
                ans.push_back('Z');
                columnNumber--;
                continue;
            }
            ans.push_back((char)(cur+64));
        }
        ans.push_back((char)(columnNumber+64));
        reverse(ans.begin(),ans.end());
        return ans;
    }
};