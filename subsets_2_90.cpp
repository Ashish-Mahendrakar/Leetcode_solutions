class Solution {
public:
    void rr(vector<int>& nums,vector<int>& temp,set<vector<int>> &s,int i)
    {
        if(i==nums.size())
        {
            s.insert(temp);
            return;
        }

        //include
        temp.push_back(nums[i]);
        rr(nums,temp,s,i+1);
        temp.pop_back();

        //exclude
        rr(nums,temp,s,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        rr(nums,temp,s,0);
        //cout<<s.size()<<endl;
        vector<vector<int>> ans;
        for(auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};