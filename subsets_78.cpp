class Solution {
public:
    void rr(vector<int>& nums,vector<int> &temp,vector<vector<int>> &ans,int i)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[i]);
        rr(nums,temp,ans,i+1);

        //exclude
        temp.pop_back();
        rr(nums,temp,ans,i+1);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int>temp;
        vector <vector<int>> ans;
        //ans.push_back(temp);
        int i=0;
        rr(nums,temp,ans,i);
        return ans;
    }
};