class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++)
        {
            freq[(int)(s[i]-'a')]++;
        }

        for(int i=0;i<s.length();i++)
        {
            if(freq[(int)(s[i]-'a')]==1)
            {
                return i;
            }
        }
        return -1;
    }
};