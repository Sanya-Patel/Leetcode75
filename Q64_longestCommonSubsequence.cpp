class Solution {
    public:
        int solve(int i,int j,string s1,string s2)
        {
            if(i==s1.size()) return 0;
            if(j==s2.size()) return 0;
            if(s1[i]==s2[j])
            {
                return 1+solve(i+1,j+1,s1,s2);
            }
            else
            {
                return max(solve(i,j+1,s1,s2),solve(i+1,j,s1,s2));
            }
        }
        int solveMem(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
        {
            if(i==s1.size()) return 0;
            if(j==s2.size()) return 0;
            if(dp[i][j]!=-1)
                return dp[i][j];
    
            if(s1[i]==s2[j])
            {
                dp[i][j]= 1+solveMem(i+1,j+1,s1,s2,dp);
            }
            else
            {
                dp[i][j]= max(solveMem(i,j+1,s1,s2,dp),solveMem(i+1,j,s1,s2,dp));
            }
            return dp[i][j];
        }
    
        int solveTab(string &s1,string &s2)
        {
            vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
            for(int i=s1.size()-1;i>=0;i--)
            {
                for(int j=s2.size()-1;j>=0;j--)
                {
                    if(s1[i]==s2[j])
                    {
                        dp[i][j]= 1+ dp[i+1][j+1];
                    }
                    else
                    {
                        dp[i][j]= max(dp[i][j+1],dp[i+1][j]);
                    }
                }
            }
            return dp[0][0];
        }
    
    
        int longestCommonSubsequence(string text1, string text2) {
            // return solve(0,0,text1,text2);
    
            // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
            // return solveMem(0,0,text1,text2,dp);
    
            return solveTab(text1,text2);
            
        }
    };