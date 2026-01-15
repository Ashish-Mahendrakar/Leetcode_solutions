class Solution {
public:
    void sum2(vector<int> &nums,int i,int j,long target,set <vector<int>> &s)
    {
        int start=j+1;
        int end=nums.size()-1;
        while(start < end)
        {
            if(nums[start]+nums[end]==target)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[start]);
                temp.push_back(nums[end]);
                s.insert(temp);
                start++;
                end--;
            }
            else if(nums[start]+nums[end]<target)
            {
                start++;

            }
            else
            {
                end--;
            }
        }
    }
    void sum3(vector<int> &nums,int i,long target,set <vector<int>> &s)
    {
        //i+1 to end 3 sum target
        for(int j=i+1;j<nums.size();j++)
        {
            sum2(nums,i,j,target-nums[j],s);
        }
        
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
        {
            return ans;
        }
        set <vector<int>> s;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            sum3(nums,i,target-nums[i],s);
        }

        for(auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
//same idea without recursion will give u better time complexity ansd space as well