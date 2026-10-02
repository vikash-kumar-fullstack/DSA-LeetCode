class Solution {
public:
    int top(int n,vector<int>&dp){
        if(n==1 ||n==2)return n;
        if(dp[n]!=-1)return dp[n];
        dp[n]=top(n-1,dp)+top(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return top(n,dp);
    }
};