class Solution {
    public:
        int solve(string &s1,string &s2,int i, int j)
        {
            if(i==s1.size())
            {
                return s2.size()-j;
            }
            if(j==s2.size())
            {
                return s1.size()-i;
            }
            if(s1[i]==s2[j])
            {
                return solve(s1,s2,i+1,j+1);
            }
            int insert = 1+solve(s1,s2,i,j+1);
            int del = 1+solve(s1,s2,i+1,j);
            int rep = 1+solve(s1,s2,i+1,j+1);
    
            int ans=min(insert, min(del,rep));
            return ans;
        }
        int solveMem(string &s1,string &s2,int i, int j,vector<vector<int>>&dp)
        {
            if(i==s1.size())
            {
                return s2.size()-j;
            }
            if(j==s2.size())
            {
                return s1.size()-i;
            }
            if(dp[i][j]!=-1)
            {
                return dp[i][j];
            }
            int ans=0;
            if(s1[i]==s2[j])
            {
                ans= solveMem(s1,s2,i+1,j+1,dp);
            }
            int insert = 1+solveMem(s1,s2,i,j+1,dp);
            int del = 1+solveMem(s1,s2,i+1,j,dp);
            int rep = 1+solveMem(s1,s2,i+1,j+1,dp);
    
            ans=min(insert, min(del,rep));
            return dp[i][j]=ans;
        }
        int solveTab(string &s1,string &s2)
        {
            vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    
            for(int i=0;i<s1.size();i++)
            {
                dp[i][s2.size()]= s1.size()-i;
            }
            for(int j=0;j<s2.size();j++)
            {
                dp[s1.size()][j]= s2.size()-j;
            }
    
            for(int i=s1.size()-1;i>=0;i--)
            {
                for(int j=s2.size()-1;j>=0;j--)
                {
                    int ans=0;
                    if(s1[i]==s2[j])
                    {
                        ans=dp[i+1][j+1];  //not return
                    }
                    else
                    {
                        int insert = 1+ dp[i][j+1];
                        int del = 1+ dp[i+1][j];
                        int rep = 1+ dp[i+1][j+1];
    
                        ans=min(insert, min(del,rep));
                    
                    }
                    dp[i][j]=ans;
                }
            }
            return dp[0][0];
        }
        int minDistance(string word1, string word2) {
            // return solve(word1,word2,0,0);
    
            // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
            // return solveMem(word1,word2,0,0,dp);
    
            return solveTab(word1,word2);
        }
    };