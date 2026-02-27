unordered_map <int,int> freq;
class compare {
    public: 
        bool operator()(int a,int b)
        {
            return freq[a]>freq[b];
        }
};
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //unordered_map <int,int> freq;
        freq.clear();
        unordered_map <int,bool> vis;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
            
        }
        
        priority_queue<int ,vector<int>,compare> pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(vis[nums[i]]==false)
            {
                vis[nums[i]]=true;
                if(pq.size()<k)
                {
                    pq.push(nums[i]);
                }
                else
                {
                    if(freq[pq.top()] > freq[nums[i]])
                    {
                        //cout<<"h"<<endl;
                        //cout<<freq[pq.top()]<<" "<<freq[nums[i]]<<endl;
                        continue;
                    }
                    else
                    {
                        pq.pop();
                        pq.push(nums[i]);
                    }
                }
                cout<<pq.top()<<endl;
            }
            
        }
        //cout<<pq.size();
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};