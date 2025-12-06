class Solution {
public:
    int myAtoi(string s) {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                s.erase(i,1);
                i--;
            }
            else
            {
                break;
            }
        }
       // cout<<s;
        int sign=1;

        if(s[0]=='-')
        {
            sign=-1;
            s.erase(0,1);
            if(!(s[0]>='0' && s[0]<='9'))
            {
                return 0;
            }
        }
        //cout<<s[0];
        cout<<INT_MIN<<" "<<INT_MAX;

        if(s[0]=='+')
        {
            s.erase(0,1);
        }

        long ans=0;
        int len=s.length();
        int index;
        for(int i=0;i<len;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                continue;
            }
            else
            {
                index=i;
                break;
            }
        }

        s.erase(index,len-index);
        len=s.length();
        int i=0;
        while(i<len)
        {
            ans=(ans*10)+((int)s[i] - 48);
            if(ans>INT_MAX)
            {
                if(sign ==1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            
            i++;
        }

        return sign*ans;


    }
};