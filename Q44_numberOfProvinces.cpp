class Solution {
    public:
        void dfs(int src,vector<bool>&vis,vector<vector<int>>&adj)
        {
            vis[src]=true;
            for(int nbr:adj[src])
            {
                if(!vis[nbr])
                {
                    dfs(nbr,vis,adj);
                }
            }
        }
        void bfs(int src,vector<bool>&vis,vector<vector<int>>&adj) {
            queue<int>q;
            q.push(src);
            vis[src]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int nbr:adj[node])
                {
                    if(!vis[nbr])
                    {
                        q.push(nbr);
                        vis[nbr]=true;
                    }
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n=isConnected.size();
            vector<vector<int>>adj(n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && isConnected[i][j]==1)
                    {
                        adj[i].push_back(j);
                        // adj[j].push_back(i);
                    }
                }
            }
            vector<bool>vis(n,false);
            int c=0;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    c++;
                    // dfs(i,vis,adj);
                    bfs(i,vis,adj);
                }
            }
            return c;
        }
    };