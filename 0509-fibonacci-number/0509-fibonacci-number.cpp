class Solution {
public:

    //normal recursion solution
    // int answer(int n){
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n==1)return 1;
    //     return answer(n-1)+answer(n-2);
    // }

    //top-buttom approach
    // recursion + memoization
    int solveUsingDp(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }

        // step 3:if result is already present in dp , use it do not recalculate
        if(dp[n]!=-1){
            return dp[n];
        }

        // step 2: return or store the result in dp
        dp[n]=solveUsingDp(n-1,dp)+solveUsingDp(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        // return answer(n);

        // step 1:dp creation
        vector<int>dp(n+1,-1);
        return solveUsingDp(n,dp);
    }
};