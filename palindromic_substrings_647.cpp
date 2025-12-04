class Solution {
public:
    int countSubstrings(string s) {
        //odd
        int odd_count=0;
        for(int i=0;i<s.length();i++)
        {
            
            int j=i;
            int k=j;
            while(i>=0 && k>=0 && j<s.length() && k<s.length() && k>=j)
            {
                if(s[j]==s[k])
                {
                    odd_count++;
                    //cout<<j<<" "<<odd_count<<endl;
                    j--;
                    k++;
                }
                else
                {
                    break;
                }
            }
        }

        //even
        int even_count=0;
        for(int i=0;i<s.length();i++)
        {
            int j=i;
            int k=j+1;
            while(j>=0 && k>=0  && k<s.length() && k>=j)
            {
                if(s[j]==s[k])
                {
                    even_count++;
                    j--;
                    k++;
                }
                else
                {
                    break;
                }
            }
        }

        return odd_count+even_count;

    }
};