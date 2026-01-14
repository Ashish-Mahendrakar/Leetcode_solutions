class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['M']=1000;
        mp['D']=500;
        mp['C']=100;
        mp['L']=50;
        mp['X']=10;
        mp['V']=5;
        mp['I']=1;
        int i=0;
        int ans=0;
        while(i<s.length())
        {
            if(s[i]=='M' ||s[i]=='D' ||s[i]=='L' ||s[i]=='V')
            {
                ans=ans+mp[s[i]];
                i++;
            }
            else if(s[i]=='I')
            {
                if(i+1<s.length())
                {
                    if(s[i+1]=='V' )
                    {
                        ans=ans+4;
                        i=i+2;
                        continue;
                    }
                    else if(s[i+1]=='X')
                    {
                        ans=ans+9;
                        i=i+2;
                        continue;
                    }
                    else
                    {
                        ans=ans+mp[s[i]];
                        i++;
                        continue;
                    }
                }
                else
                {
                    ans=ans+mp[s[i]];
                    i++;
                    continue;
                }
            }

            else if(s[i]=='X')
            {
                if(i+1<s.length())
                {
                    if(s[i+1]=='L' )
                    {
                        ans=ans+40;
                        i=i+2;
                        continue;
                    }
                    else if(s[i+1]=='C')
                    {
                        ans=ans+90;
                        i=i+2;
                        continue;
                    }
                    else
                    {
                        ans=ans+mp[s[i]];
                        i++;
                        continue;
                    }
                }
                else
                {
                    ans=ans+mp[s[i]];
                    i++;
                    continue;
                }
            }


            else if(s[i]=='C')
            {
                if(i+1<s.length())
                {
                    if(s[i+1]=='D' )
                    {
                        ans=ans+400;
                        i=i+2;
                        continue;
                    }
                    else if(s[i+1]=='M')
                    {
                        ans=ans+900;
                        i=i+2;
                        continue;
                    }
                    else
                    {
                        ans=ans+mp[s[i]];
                        i++;
                        continue;
                    }
                }
                else
                {
                    ans=ans+mp[s[i]];
                    i++;
                    continue;
                }
            }
        }
        return ans;
    }
};