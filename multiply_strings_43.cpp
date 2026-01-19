class Solution {
public:
    string add(string ans,string temp,int s)
    {
        int carry=0;
        for(int i=0;i<temp.length();i++)
        {
            if((i+s) < ans.length())
            {
              int n1=(int)ans[i+s] -48; 
              int n2=(int)temp[i] -48; 
              //cout<<n1<<" "<<n2<<endl;
              int n=(n1+n2)+carry;
              
              carry=n/10;
              n=n%10;

              
              ans[i+s]=(char)(n+48); 
            }
            
            else
            {
                  int n1=0; 
                  int n2=(int)temp[i] -48; 
                  int n=(n1+n2)+carry;
                  carry=n/10;
                  n=n%10;
                  ans.push_back((char)(n+48));
            }
        }
        
        if((s+temp.length()) < ans.length())
        {
            cout<<(s+temp.length())<<" "<<ans.length()<<endl;
        }
        if(carry !=0)
        {
            ans.push_back((char)(carry+48));
        }
        carry=0;
        //cout<<ans<<endl;
        return ans;

    }
    string multiply(string num1, string num2) {
        string ans;
        for(int i=num1.length()-1;i>=0;i--)
        {
            int n1=(int)num1[i] -48;
            int carry=0;
            string temp;
            for(int j=num2.length()-1;j>=0;j--)
            {
                int n2=(int)num2[j] -48;

                int n=(n1*n2)+carry;
                carry=n/10;
                n=n%10;
                temp.push_back((char)(n+48));

            }
            if(carry != 0)
            {
               temp.push_back((char)(carry+48)); 
            }
            //cout<<temp<<" "<<num1.size()-i-1<<endl;

            int s=num1.size()-i-1;
            if(s==0)
            {
                ans=temp;
            }
            else
            {
                ans=add(ans,temp,s);
            }
        }

        int start=0;
        int end=ans.length()-1;
        while(start < end)
        {
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            {
                return ans;
            }
        }
        return "0";
    }
};