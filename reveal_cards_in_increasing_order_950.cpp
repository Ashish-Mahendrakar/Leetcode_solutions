class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> order;
        vector<int>ans(deck.size(),0);
        queue <int> q;
        for(int i=0;i<deck.size();i++)
        {
            q.push(i);
        }
        while(!q.empty())
        {
            order.push_back(q.front());
            q.pop();
            if(!q.empty())
            {
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
        }
        for(int i=0;i<order.size();i++)
        {
            ans[order[i]]=deck[i];
        }


        return ans;
    }
};