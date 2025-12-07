class Solution {
public:

    static bool my_com(int &a,int &b)
    {
        string tempa=to_string(a);
        string tempb=to_string(b);
        string c=tempa+tempb;
        string d=tempb+tempa;
        return c>d;
    }
    bool all_zero(vector<int> &nums)
    {
        for(auto i : nums)
        {
            if(i !=0)
            return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        if(all_zero(nums))
        {
            return "0";
        }
        sort(nums.begin(),nums.end(),my_com);
        string ans="";
        for(auto i :nums)
        {
            //cout<<i<<" ";
            string temp=to_string(i);
            
            ans=ans+temp;
            
        }
        
        
        return ans;
    }
};