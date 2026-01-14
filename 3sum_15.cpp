class Solution {
public:
    void rr(vector<int> &num,int i,set <vector<int>> &s)
    {
        int start=0;
        int end=num.size()-1;
        while(start<end)
        {
            if(num[start]+num[end]+num[i] == 0)
            {
                if(start != i && end != i)
                {
                    vector<int> temp;
                    temp.push_back(num[start]);
                    temp.push_back(num[end]);
                    temp.push_back(num[i]);
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                start++;
                end--;
            }
            else if(num[start]+num[end]+num[i] < 0)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> num;
        vector<vector<int>> ans;
        set <vector<int>> s;
        unordered_map <int,int> mp;
        for(auto i : nums)
        {
            if(mp[i]==0)
            {
                num.push_back(i);
                mp[i]++;
            }
            else if(mp[i]<3)
            {
                mp[i]++;
            }
        }
        //cout<<num.size();
        sort(num.begin(),num.end());

        for(int i=0;i<num.size();i++)
        {
            //cout<<num[i]<<endl;
            if(num[i] == 0)
            {
                //cout<<"g"<<endl;
                if(mp[num[i]]==3)
                {
                    vector<int> temp(3,0);
                    s.insert(temp);
                }
                
            }
            else if((num[i]&1)==0)
            {
                //cout<<"*"<<endl;
                
                if(mp[(-1)*(num[i]/2)]>=2)
                {
                    vector<int> temp(3,(-1)*(num[i]/2));
                    temp[2]=num[i];
                    s.insert(temp);

                }
            }


            if(num.size()>=3)
            {
                rr(num,i,s);
            }
        }
        //cout<<(-4 & 1)<<endl;
        for(auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};