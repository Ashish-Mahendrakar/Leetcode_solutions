class Solution {
public:
    void rr(string &s,string &temp,vector<string> & ans,int i,int count)
    {
        //cout<<temp<<endl;
        if(i>=s.length())
        {
            return;
        }
        if(count ==3)
        {
            //cout<<s.length()-i<<endl;
            if(s.length()-i>3)
            {
                return;
            }
            if( s.length()-i == 3)
            {
                string t=s.substr(i,3);
                //cout<<t<<endl;
                int no=stoi(t);
                //cout<<no<<endl;
                if(no<100 || no>255)
                {
                    //cout<<"h"<<endl;
                    return;
                }
                else
                {
                    temp=temp+t;
                    ans.push_back(temp);
                    temp.erase(temp.length()-3,3);
                    return;
                }
            }
            else if( s.length()-i == 2)
            {
                
                string t=s.substr(i,2);
                //cout<<t<<endl;

                int no=stoi(t);
                //cout<<no<<endl;
                
                if(no<10 || no>99)
                {
                    return;
                }
                else
                {
                    temp=temp+t;
                    //cout<<temp<<endl;
                    ans.push_back(temp);
                    temp.erase(temp.length()-2,2);
                    return;
                }
            }
            else if(s.length()-i == 1)
            {
                string t=s.substr(i,1);
                int no=stoi(t);
                if( no>255)
                {
                    return;
                }
                else
                {
                    temp=temp+t;
                    ans.push_back(temp);
                    temp.erase(temp.length()-1,1);
                    return;
                }
            }
        }

        

        
        

        //3
        if(s.length()-i>=3)
        {
            string t=s.substr(i,3);
            int no=stoi(t);
            if(no>=100 && no<=255)
            {
                temp=temp+t;
                temp.push_back('.');
                rr(s,temp,ans,i+3,count+1);
                temp.pop_back();
                temp.erase(temp.length()-3,3);
            }
        }


              

        //2
        if(s.length()-i>=2)
        {
            string t=s.substr(i,2);
            int no=stoi(t);
            if(no>=10 && no<=99)
            {
                temp=temp+t;
                temp.push_back('.');
                rr(s,temp,ans,i+2,count+1);
                temp.pop_back();
                temp.erase(temp.length()-2,2);
            }
        }

        //1
        if(s.length()-i>=1)
        {
            string t=s.substr(i,1);
            int no=stoi(t);
            if(no>=0 && no<=9)
            {
                temp=temp+t;
                temp.push_back('.');
                rr(s,temp,ans,i+1,count+1);
                temp.pop_back();
                temp.erase(temp.length()-1,1);
            }
        }
        

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        rr(s,temp,ans,0,0);
        return ans;
    }
};