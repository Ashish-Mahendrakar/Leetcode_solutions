class compare{
    public:
        bool operator()(int a,int b)
        {
            return a<b;
        }
};
class Solution {
public:
    
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>,compare>pq;
        for(auto i : piles)
        {
            pq.push(i);
        }
        while(k!=0)
        {
            k--;
            int temp=pq.top();
            pq.pop();
            temp=temp-temp/2;
            pq.push(temp);
        }
        int ans=0;
        while(!pq.empty())
        {
            int temp=pq.top();
            pq.pop();
            ans=ans+temp;
        }
        return ans;
    }
};