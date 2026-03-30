class Solution {
public:
    int countCommas(int n) {
        if(n<1000)
        {
            return 0;
        }
        n=n-1000;
        return n+1;
    }
};