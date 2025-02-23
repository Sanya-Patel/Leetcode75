class Solution {
    public:
        // bool check(int i,int j,int &m,int &n)
        // {
        //     if(i<0 || j<0 || i>=m || j>=n)
        //     {
        //         return false;
        //     }
        //     return true;
        // }
        // void solve(int i,int j,int &m,int &n,int &c)
        // {
        //     if(i==m-1 && j==n-1)
        //     {
        //         c++;
        //         return;
        //     }
        //     if(check(i,j+1,m,n))
        //     {
        //         solve(i,j+1,m,n,c);
        //     }
        //     if(check(i+1,j,m,n))
        //     {
        //         solve(i+1,j,m,n,c);
        //     }
        // }
        int solveMem(int i,int j,int &m,int &n,vector<vector<int>>&dp)
        {
            if(i==m-1 && j==n-1)
            {
                return 1;
            }
            if(i<0 || j<0 || i>=m || j>=n)
            {
                return 0;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            
            int r=solveMem(i,j+1,m,n,dp);
            int d=solveMem(i+1,j,m,n,dp);
    
            dp[i][j]=r+d;
            return dp[i][j];
        }
        int uniquePaths(int m, int n) {
            int c=0;
            vector<vector<int>>dp(m,vector<int>(n,-1));
            // solve(0,0,m,n,c);
            c=solveMem(0,0,m,n,dp);
            return c;
        }
    };