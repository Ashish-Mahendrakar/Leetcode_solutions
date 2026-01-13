class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(s=="")
        {
            return 0;
        }
        int start=0;
        int end=0;
        int ans=0;
        vector<int> last(255,-1);
        vector<int> temp(255,-1);
        for(int i=0;i<len;i++)
        {
            cout<<start<<endl;
            if(last[(int)s[i]] == -1 ||last[(int)s[i]]<start )
            {
                last[(int)s[i]]=i;
                if(ans< i-start+1)
                {
                    ans=i-start+1;
                }
            }
            else
            {
                
                start=last[(int)s[i]]+1;
                last[(int)s[i]]=i;

            }
        }
        return ans;
    }
};