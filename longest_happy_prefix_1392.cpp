class Solution {
public:
    string longestPrefix(string s) {
        string temp1=s.substr(0,s.length()-1);
        string temp2=s.substr(1,s.length()-1);
        
        while(temp1 != temp2)
        {
            temp1.pop_back();
            temp2.erase(0,1);
        }
        return temp1;
    }
};