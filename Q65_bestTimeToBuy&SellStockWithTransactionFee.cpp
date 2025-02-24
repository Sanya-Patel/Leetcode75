class Solution {
    public:
        int solve(vector<int>& prices,int i,int buy,int fee)
        {
            if(i==prices.size())
            {
                return 0;
            }
            int profit1=0,profit2=0;
            if(buy)
            {
                int buy_profit=-prices[i]+solve(prices,i+1,0,fee);
                int ignore=0+solve(prices,i+1,1,fee);
                profit1=max(buy_profit,ignore);
            }
            else
            {
                int sell_profit=prices[i]+solve(prices,i+1,1,fee)-fee;
                int ignore=0+solve(prices,i+1,0,fee);
                profit2=max(sell_profit,ignore);
            }
            return max(profit1,profit2);
        }
        int solveMem(vector<int>& prices,int i,int buy,vector<vector<int>>&dp,int fee)
        {
            if(i==prices.size())
            {
                return 0;
            }
            if(dp[i][buy]!=-1)
            {
                return dp[i][buy];
            }
            int profit1=0,profit2=0;
            if(buy)
            {
                int buy_profit=-prices[i]+solveMem(prices,i+1,0,dp,fee);
                int ignore=0+solveMem(prices,i+1,1,dp,fee);
                profit1=max(buy_profit,ignore);
            }
            else
            {
                int sell_profit=prices[i]+solveMem(prices,i+1,1,dp,fee)-fee;
                int ignore=0+solveMem(prices,i+1,0,dp,fee);
                profit2=max(sell_profit,ignore);
            }
            dp[i][buy]= max(profit1,profit2);
            return dp[i][buy];
        }
        int solveTab(vector<int>& prices,int fee)
        {
            vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
            for(int i=prices.size()-1;i>=0;i--)
            {
                for(int buy=0;buy<2;buy++)
                {
                    int profit1=0,profit2=0;
                    if(buy)
                    {
                        int buy_profit=-prices[i]+dp[i+1][0];
                        int ignore=0+dp[i+1][1];
                        profit1=max(buy_profit,ignore);
                    }
                    else
                    {
                        int sell_profit=prices[i]+dp[i+1][1]-fee;
                        int ignore=0+dp[i+1][0];
                        profit2=max(sell_profit,ignore);
                    }
                    dp[i][buy]= max(profit1,profit2);
                }
            }
            return dp[0][1];
            
        }
    
        int maxProfit(vector<int>& prices,int fee) {
            // return solve(prices,0,1,fee);
    
            // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
            // return solveMem(prices,0,1,dp,fee);
    
            return solveTab(prices,fee);
        }
    };