

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int count0=0;
        int count1=0;

        for(int i=0;i<len;i++)
        {
            if(nums[i] == 0)
            {
                count0++;
            }
            else if(nums[i]== 1)
            {
                count1++;
            }
        }
        

        int i=0;
        while(count0 >= 1 && i<len)
        {
            count0--;
            nums[i]=0;
            i++;
        }

        while(count1 >= 1 && i < len)
        {
            count1--;
            nums[i]=1;
            i++;
        }
        while(i<len)
        {
           nums[i]=2;
           i++; 
        }
        
    }
};