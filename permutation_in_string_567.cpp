class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
        {
            return false;
        }

        vector<int> vs1(26,0);
        vector<int> vs2(26,0);
        for(int i=0;i<s1.length();i++)
        {
            vs1[(int)s1[i]-'a']++;
            vs2[(int)s2[i]-'a']++;
        }
        int start=0;
        if(vs1==vs2)
        {
            return true;
        }
        for(int i=s1.length();i<s2.length();i++)
        {
            vs2[(int)s2[i]-'a']++;
            vs2[(int)s2[start]-'a']--;
            start++;
            if(vs1==vs2)
            {
                return true;
            }
        }
        return false;
    }
};