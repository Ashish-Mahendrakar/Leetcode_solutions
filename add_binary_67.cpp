#include <iostream>
class Solution {
public:
    string add(string a, string b)
    {
        if(a.length() != b.length())
        {
            string temp(a.length()-b.length(),'0');
            //cout<<temp<<endl;
            b=b+temp;
            //cout<<b<<endl;
        }
        //cout<<a<<" "<<b<<endl;
        int carry=0;
        for(int i=0;i<a.length();i++)
        {
            int n1=(int)a[i] - ((int)'0');
            
            int n2=(int)b[i] - ((int)'0');
            int xr=n1^n2^carry;
            //xr=xr^carry;

            if(n1==1 && n2==1)
            {
                carry=1;
            }
            else if(carry==1 && n1==1)
            {
                carry=1;
            }
            else if(carry==1 && n2==1)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            a[i]=(char)(xr+48);

            
        }
        
        if(carry !=0)
        {
            a.push_back((char)(carry+48));
        }
        
        reverse(a.begin(),a.end());
        //a.push_back((char)(carry+48));
        //cout<<a;
        return a;
    }
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        if(a.length()>=b.length())
        {
            return add(a,b);
        }
        else
        {
            return add(b,a);
        }

    }
};