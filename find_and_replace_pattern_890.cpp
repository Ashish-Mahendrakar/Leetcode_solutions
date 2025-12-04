class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;//97->a
        for(auto i : words)
        {
            vector<char> map(26,'@');
            vector<char> rmap(26,'@');
            ans.push_back(i);
            for(int j=0;j<i.length();j++)
            {
                if(map[(int)pattern[j]  - 97] == '@'  && rmap[(int)i[j] - 97]=='@')
                {
                    map[(int)pattern[j]  - 97] =i[j];
                    rmap[(int)i[j] - 97]=pattern[j];
                }
                else if(map[(int)pattern[j]  - 97] !=i[j] && rmap[(int)i[j] - 97]!=pattern[j] )
                {
                    ans.pop_back();
                    break;
                }

            }
        }
        
        return ans;
    }
};