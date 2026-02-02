
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(auto i: nums)
        {
            if(i>0)
            {
                mp[i]=true;
            }
        }

        for(int i=1;i<=10e5;i++)
        {
            if(mp[i]==false)
            {
                return i;
            }
        }

        return 0;
    }
};