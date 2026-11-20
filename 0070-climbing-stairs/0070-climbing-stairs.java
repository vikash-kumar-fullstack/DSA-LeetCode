class Solution {
    public int climbStairs(int n) {
        int [] dp=new int[n+1];
        return sta(n,dp);  
    }
    public int sta(int n,int []dp){
        if(n==1|| n==2){
            return n;
        }
        if(dp[n]!=0)return dp[n];
        
        return dp[n]=sta(n-1,dp)+sta(n-2,dp);
    }
}