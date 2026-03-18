class Solution {
public:
    void dfs(unordered_map <int,list<int>> &g,unordered_map <int,bool> &vis,unordered_map <int,int> &par,bool &ans,int cur)
    {
        if(vis[cur]==true)
        {
            return;
        }

        vis[cur]=true;
        for(auto nbr : g[cur])
        {
            if(vis[nbr]==false)
            {
                par[nbr]=cur;
                
                dfs(g,vis,par,ans,nbr);
            }
            else if(par[cur] != nbr)
            {
                ans=true;
            }
        }
    }
    bool iscycle(unordered_map <int,list<int>> &g,int cur)
    {
        unordered_map <int,bool> vis;
        unordered_map <int,int> par;
        bool ans=false;
        //int cur=1;
        dfs(g,vis,par,ans,cur);
        return ans;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();   
        unordered_map <int,list<int>> g;
        for(int i=0;i<n;i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);

            bool status=iscycle(g,edges[i][0]);
            if(status)
            {
                return edges[i];
            }
        }
        return edges[0];
    }
};