class Solution {
    public:
        // int l=cost.size();
        // vector<int>dp(-1);
        int solve(vector<int>cost,int n,vector<int>&dp)
        {
            if(n<=1) return 0;
            if(dp[n]!=-1) return dp[n];
            int d1=cost[n-1]+solve(cost,n-1,dp);
            int d2=cost[n-2]+solve(cost,n-2,dp);
            dp[n]=min(d1,d2);
            return dp[n];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            vector<int>dp(cost.size()+1,-1);
            int ans=solve(cost,cost.size(),dp);
            return ans;
        }
    };