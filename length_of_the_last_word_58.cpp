class Solution {
public:
    int lengthOfLastWord(string s) {
        int last=-1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] != ' ')
            {
                last=i;
                //cout<<i<<endl;
                break;
            }
        }
        
        cout<<last<<" "<<s.length();
        //for(int k=s.length()-1)
        int count=0;
        while(last>=0 && s[last]!=' ')
        {
            count++;
            last--;
        }
        return count;
    }
};