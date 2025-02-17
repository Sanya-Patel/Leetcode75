class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n=rooms.size();
            vector<bool>vis(n,false);
            queue<int>q;
            q.push(0);
            vis[0]=true;
            while(!q.empty())
            {
                int roomKey=q.front();
                q.pop();
                for(int i:rooms[roomKey])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        vis[i]=true;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(vis[i]==false)
                {
                    return false;
                }
            }
            return true;
        }
    };