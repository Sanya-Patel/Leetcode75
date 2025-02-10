class Solution {
    public:
        bool check(int i,int j,vector<vector<int>>& grid)
        {
            int n=grid.size();
            for(int k=0;k<n;k++)
            {
                if(grid[i][k]!=grid[k][j])
                {
                    return false;
                }
            }
            return true;
        }
        int equalPairs(vector<vector<int>>& grid) {
            int n=grid.size();
            int c=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(check(i,j,grid))
                    {
                        c++;
                    }
                }
            }
            return c;
        }
    };