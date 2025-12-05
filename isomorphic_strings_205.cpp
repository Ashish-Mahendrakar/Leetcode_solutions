class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char>map(300,'@');
        vector<char>rmap(300,'@');
        int s_len=s.length();
        int t_len=t.length();
        if(s_len != t_len)
        {
            return false;
        }

        int i=0;
        while(i<s_len)
        {
            if(map[s[i] ] == '@' && rmap[t[i] ]=='@')
            {
                map[s[i]]=t[i];
                rmap[t[i]]=s[i];
                i++;
            }
            else if(map[s[i]] == t[i] && rmap[t[i]]== s[i])
            {
                i++;
            }
            else
            {
                return false;
            }
        }

        return true;

    }
};