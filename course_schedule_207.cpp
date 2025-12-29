class graph{
    public:
        unordered_map <int,list<int>> adjlist;
        void insert(int a,int b)
        {
            adjlist[b].push_back(a);
        }
        void printt()
        {
            for(auto i : adjlist)
            {
                cout<<i.first<<"->";
                for(auto j : i.second)
                {
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }
        void bfs(int &numCourses,vector<int> &topsort)
        {
            unordered_map <int,int> indegree;
            queue <int> q;
            for(int i=0;i<numCourses;i++)
            {
                indegree[i]=0;
            }
            for(auto i : adjlist)
            {
                
                for(auto j :i.second)
                     indegree[j]++;
            }

            for(auto i :indegree)
            {
                if(i.second == 0)
                    q.push(i.first);

            }
            while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                topsort.push_back(cur);
                for(auto nebr: adjlist[cur])
                {
                    indegree[nebr]--;
                    if(indegree[nebr]==0)
                    {
                        q.push(nebr);
                    }
                }
            }
        }

};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g;
        if(prerequisites.empty())
        {
            return true;
        }
        for(auto i : prerequisites)
        {
            g.insert(i[0],i[1]);
            
        }
        //g.printt();
        vector <int> topsort;
        g.bfs(numCourses,topsort);
        
        cout<<topsort.size();
        if(topsort.size()==numCourses)
            return true;

        return false;

    }
};