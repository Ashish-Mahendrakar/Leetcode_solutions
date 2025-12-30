class Solution {
public:
    void dfs(int cur,unordered_map <int,bool> &visited,vector<vector<int>>& isConnected)
    {
        visited[cur]=true;
        for(int i=0;i<isConnected[cur].size();i++)
        {
            if(isConnected[cur][i] == 1)
            {
                if(visited[i] == false)
                {
                    dfs(i,visited,isConnected);

                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        ///o to n-1 vertecies
        unordered_map <int,bool> visited;

        //initializing
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};