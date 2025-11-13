class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len=nums.size();
        double  ksum=0;
        for(int i=0;i<k;i++)
        {
            ksum=ksum+nums[i];

        }
        double  max_avg=ksum/k;

        for(int i=k;i<len;i++)
        {
            ksum=ksum+nums[i]-nums[i-k];
            double  avg=ksum/k;
            if(avg>max_avg)
            {
                max_avg=avg;
            }
        }
        return max_avg;
    }
};