class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int len=nums.size();
        set <pair<int,int>> ans;
        while(i>=0 && i<len  && j>=0 && j<len)
        {
            if(nums[j]-nums[i]==k )
            {
                pair<int,int>temp;
                temp.first=nums[i];
                temp.second=nums[j];
                ans.insert(temp);i++;j++;
            }
            else if(nums[j]-nums[i]<k)
            {
                j++;
            }
            else
            {
                i++;
            }

            if(i==j)
            {
                j++;
            }
        }
        return ans.size();
    }
};


//using map
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         int count=0;
//         map<int,int>freq;
//         for(auto i : nums)
//         {
//             freq[i]++;
//         }
//         if(k == 0)
//         {
//             for(auto i :freq)
//             {
//                 int temp=i.second;
//                 if(temp>1)
//                 {
//                     count++;
//                 }
//             }
//             return count;
//         }
//         else
//         {
//            for (auto i : freq)
//             {
//                  if (freq.find(i.first + k) != freq.end())
//                    {
//                        count++;
//                    }
//              }
//         }


//         return count;

//     }
// };