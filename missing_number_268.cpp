class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int temp=((n*(n+1))/2);
        for( auto i : nums)
        {
            sum=sum+i;
        }
        return temp-sum;
    }
};