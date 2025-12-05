class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len=s.length();
        int t_len=t.length();
        if(s_len != t_len)
        {
            return false;
        }
        vector<int>freq(26,0);
        for(auto i :s)
        {
            int num=(int)i -97;
            freq[num]++;
        }

        for(auto i :t)
        {
            int num=(int)i -97;
            if(freq[num]==0)
            {
                return false;
            }
            else
            {
                freq[num]--;
            }
        }
        return true;
    }
};