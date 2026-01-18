class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        else if(n==2)
        {
            return "11";
        }
        else if(n==3)
        {
            return "21";
        }
        else if(n==4)
        {
            return "1211";
        }
        else 
        {
            string temp=countAndSay(n-1);
            char cur=temp[0];
            int count=1;
            string ans;
            for(int i=1;i<temp.length();i++)
            {
                if(temp[i]==cur)
                {
                    count++;
                }
                else
                {
                    ans=ans+to_string(count);
                    ans.push_back(cur);
                    
                    cur=temp[i];
                    count=1;
                    //cout<<ans<<endl;
                }
            }
            ans=ans+to_string(count);
            ans.push_back(cur);
            
            return ans;
        }

        
    }
};