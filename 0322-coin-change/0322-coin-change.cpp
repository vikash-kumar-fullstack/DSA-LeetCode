class Solution {
public:
//using recursion
    // int usingRecursion(vector<int>& coins, int amount){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int res=usingRecursion(coins,amount-coins[i]);
    //         if(res!=INT_MAX){
    //         int ans=1+res;
    //         mini=min(mini,ans);
    //         }
    //     }
    //     return mini;
    // }

//using memoization
    // int usingMemoization(vector<int>&dp,vector<int>& coins, int amount){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }
    //     if(dp[amount]!=-1){
    //         return dp[amount];
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int res=usingMemoization(dp,coins,amount-coins[i]);
    //         if(res!=INT_MAX){
    //         int ans=1+res;
    //         mini=min(mini,ans);
    //         }
    //     }
    //     dp[amount]=mini;
    //     return dp[amount];  
    // }


//tabulation
        int solveUsingTabulation(vector<int>& coins, int amount){
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            int mini = INT_MAX;

            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                    int ans = 1 + dp[i - coins[j]];
                    mini = min(mini, ans);
                }
            }

            dp[i] = mini;
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // int ans=usingRecursion(coins,amount);
        // return ans==INT_MAX?-1:ans;


//memoization
    //step1:-
    //     vector<int>dp(amount+1,-1);
    //     int ans=usingMemoization(dp,coins,amount);
    //     return ans==INT_MAX?-1:ans;


//tabulation
        int ans=solveUsingTabulation(coins,amount);
        return ans==INT_MAX?-1:ans;
}
};