class Solution {
public:
    bool palindrone(string s){

        int start=0;
        int end=s.length()-1;
        while(start <end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start ++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int count=0;
        int start=0;
        int end=s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                string temp1=s;
                string temp2=s;
                bool state1=palindrone(temp1.erase(start,1));
                bool state2=palindrone(temp2.erase(end,1));
                cout<<state1<<" "<<state2<<endl;
                if(state1 == false && state2 == false)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            start ++;
            end--;
        }
        return true;
    }
};