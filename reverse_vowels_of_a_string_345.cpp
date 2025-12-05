class Solution {
public:
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end)
        {
            if(!(s[start]=='a' || s[start]=='A' || s[start]=='e' || s[start]=='E' || s[start]=='i' || s[start]=='I' || s[start]=='o' || s[start]=='O' || s[start]=='u' || s[start]=='U' )  )
            {
                start++;
            }
            else if(!(s[end]=='a' || s[end]=='A' || s[end]=='e' || s[end]=='E' || s[end]=='i' || s[end]=='I' || s[end]=='o' || s[end]=='O' || s[end]=='u' || s[end]=='U' ))
            {
                end--;
            }
            else
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
        }

        return s;
    }
};