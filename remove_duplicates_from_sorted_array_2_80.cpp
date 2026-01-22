class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end=nums.size()-1;
        int count=1;
        int last=nums[0];
        int j=1;
        while(j<=end)
        {
            
            // for(auto i : nums)
            // {
            //     cout<<i<<" ";
            // }

            // cout<<endl;
            // cout<<j<<" "<<count<<endl;
            if(nums[j]==last)
            {
                if(count>=2)
                {
                    //left shift
                    int k=j;
                    while(k<end)
                    {
                        nums[k]=nums[k+1];
                        k++;
                        //cout<<nums[k]<<endl;
                    }
                    //cout<<endl;
                    end--;
                    
                    continue;
                }
                else
                {
                    
                    j++;
                    count++;
                }
            }
            else
            {
                //cout<<"h"<<endl;
                last=nums[j];
                count=1;
                j++;
            }
            
        }
        return end+1;
    }
};