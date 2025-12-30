class compare{
    public: 
        bool operator()(pair<int,int> a,pair <int,int> b)
        {
            return a.second>b.second;
        }
};
class graph{
    public:
        unordered_map <int,list<pair<int,int>>> adjlist;
        void insert(int a,int b,int weight)
        {
            pair<int,int> temp;
            temp.first=b;
            temp.second=weight;
            adjlist[a].push_back(temp);
        }
        void printt()
        {
            
            for(auto i: adjlist)
            {
                cout<<i.first<<"->";
                for(auto h :i.second)
                {
                    cout<<h.first<<"-"<<h.second<<" ";
                }
                cout<<endl;
            }
        }
        void dijstra(vector<int> &dis,priority_queue <pair<int,int>,vector<pair<int,int>>,compare> &pq)
        {
            //initial
            pq.push({0,0});
            dis[0]=0;

            while(!pq.empty())
            {
                pair<int,int> cur=pq.top();
                pq.pop();
                for(auto nebr : adjlist[cur.first])
                {
                    //cout<<cur.second<<" "<<nebr.second<<endl;
                    int distance=max(nebr.second,cur.second);
                    if(distance < dis[nebr.first])
                    {
                        dis[nebr.first]=distance;
                        pair<int,int> temp={nebr.first,dis[nebr.first]};
                        pq.push(temp);

                    }
                    
                }
            }
        }
        
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        graph g;
        int m=heights.size();
        int n=heights[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++ )
            {
                //cout<<i<<" "<<j;
                //top
                if(i>=1)
                {
                    
                    g.insert((i*n)+j,((i-1)*n)+j,abs(heights[i][j] -heights[i-1][j]) );
                }

                //down
                if(i<=m-2)
                {
                    g.insert((i*n)+j,((i+1)*n)+j,abs(heights[i][j] -heights[i+1][j] ));
                }

                //left
                if(j>=1)
                {
                    g.insert((i*n)+j,((i)*n)+j-1,abs(heights[i][j] -heights[i][j-1] ));
                }

                //right
                if(j<=n-2)
                {
                    //cout<<i<<" "<<j<<" "<<(i*n)+j<<" "<<((i)*n)+j+1<<" "<<abs(heights[i][j] -heights[i][j+1])<<endl;
                    g.insert((i*n)+j,((i)*n)+j+1,abs(heights[i][j] -heights[i][j+1]) );
                }
            }
        }
        g.printt();
        vector<int> dis(m*n,INT_MAX);
        priority_queue <pair<int,int>,vector<pair<int,int>>,compare> pq;
        g.dijstra(dis,pq); 
        // for(auto i : dis)  
        // {
        //     cout<<i<<" ";
        // }     
        return dis[(m*n)-1];
    }
};