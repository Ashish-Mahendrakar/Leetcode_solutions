class Solution {
public:
    string removeDuplicates(string s) {
        int len=s.length();
        if(len==1)
        {
            return s;
        }
        else if(len==2)
        {
            if(s[0] == s[1])
            {
                return "";
            }
            else
            {
                return s;
            }
        }


        int i=0;
        int j=1;

        while(i>=0 && i<s.length() && j>=0 && j<s.length() && j==i+1 )
        {
            if(s[i]==s[j])
            {
                s.erase(i,2);
                //cout<<s<<endl;
                i--;j=i+1;
                if(i<0)
                {
                    i=0;
                    j=1;
                }
            }
            else
            {
                i++;
                j++;
            }
        }
        return s;
    }
};