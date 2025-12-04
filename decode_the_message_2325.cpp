class Solution {
public:
    string decodeMessage(string key, string message) {
        string arr ;
        set<char> s;
        for(int i=0;i<key.length();i++)
        {
            if(key[i]==' ')
            {
                continue;
            }
            else
            {
               auto flag=s.find(key[i]);
               if(flag == s.end())
               {
                s.insert(key[i]);
                arr.push_back(key[i]);
               }
               
            }
        }
        string ans;
        for(auto i :message)
        {
            if(i == ' ')
            {
                ans.push_back(i);
            }
            else
            {
                int temp=arr.find(i);
                //cout<<temp<<endl;
                ans.push_back((char)(97+temp));
            }
        }

        //cout<<arr;
        return ans;
    }
};