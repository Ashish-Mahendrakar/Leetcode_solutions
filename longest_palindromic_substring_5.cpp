class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        //odd
        for(int i=0;i<s.length();i++)
        {
            int start=i;
            int end=start;
            while(start>=0 && end<s.length())
            {
                if(s[start]==s[end])
                {
                    int size=end-start+1;
                    if(size>ans.length())
                    {
                        ans=s.substr(start,size);
                    }
                    start--;
                    end++;
                }
                else
                {
                    break;
                }
            }

        }

        //even
        for(int i=0;i<s.length();i++)
        {
            int start=i;
            int end=start+1;
            while(start>=0 && end<s.length())
            {
                if(s[start]==s[end] )
                {
                    int size=end-start+1;
                    if(size>ans.length())
                    {
                        ans=s.substr(start,size);
                    }
                    start--;
                    end++;
                }
                else
                {
                    break;
                }
            }

        }

        return ans;
    }
};