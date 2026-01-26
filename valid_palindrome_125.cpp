class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end)
        {
            
            if(!((s[start]>='a'  && s[start]<='z')||(s[start]>='A'  && s[start]<='Z')||(s[start]>='0'  && s[start]<='9') ) )
            {
                start++;
                continue;
            }
            else if(!((s[end]>='a'  && s[end]<='z')||(s[end]>='A'  && s[end]<='Z')||(s[end]>='0'  && s[end]<='9') ) )
            {
                //cout<<start<<" "<<end<<endl;
                end--;
                continue;
            }
            else 
            {
                
                if((s[start]>='A'  && s[start]<='Z'))
                {
                    s[start]=s[start]+32;
                }
                if((s[end]>='A'  && s[end]<='Z'))
                {
                    s[end]=s[end]+32;
                }

                if(s[start]==s[end])
                {
                    start++;
                    end--;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};