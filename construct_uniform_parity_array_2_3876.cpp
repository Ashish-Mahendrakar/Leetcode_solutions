class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd=INT_MAX;
        int min_even=INT_MAX;

        for(int i=0;i<nums1.size();i++)
            {
                if((nums1[i] & 1)  == 1)
                {
                    if(nums1[i] < min_odd)
                    {
                        min_odd=nums1[i];
                    }
                }
                else
                {
                    if(nums1[i] < min_even)
                    {
                        min_even=nums1[i];
                    }
                }
            }

        if(min_even == INT_MAX || min_odd == INT_MAX)
        {
            return true;
        }

        if(min_even - min_odd < 1)
        {
            return false;
        }

        return true;
    }
};