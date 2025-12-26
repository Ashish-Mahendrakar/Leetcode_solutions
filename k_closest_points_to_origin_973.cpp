class compare{
    public:
        bool operator()(pair<int,float> a,pair<int,float> b)
        {
            return a.second < b.second;
        }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue <pair<int,float>,vector<pair<int,float>>,compare> pq;
       for(int i=0;i<k;i++) 
       {
        float x=points[i][0];
        float y=points[i][1];

        float distance=(x*x + y*y);
        pair<int,float> temp;
        temp.first=i;
        temp.second=distance;
        pq.push(temp);
       }
       //cout<<pq.size();

       for(int i=k;i<points.size();i++)
       {
        float x=points[i][0];
        float y=points[i][1];

        float distance=(x*x + y*y);
        if(pq.top().second > distance)
        {
            pq.pop();
            pair<int,float> temp;
            temp.first=i;
            temp.second=distance;
            pq.push(temp);
        }
       }

       vector<vector<int>> ans;
       while(!pq.empty())
       {
        ans.push_back(points[pq.top().first]);
        pq.pop();
       }
       return ans;
    }
};