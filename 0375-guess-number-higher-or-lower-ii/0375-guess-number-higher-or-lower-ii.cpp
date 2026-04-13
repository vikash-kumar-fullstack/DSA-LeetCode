class Solution {
public:

//using recursion
    int solveUsingRecurr(int start,int end){
        if(start>=end){
            return 0;
        }
        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            maxi=min(maxi,i+max(solveUsingRecurr(start,i-1),solveUsingRecurr(i+1,end)));

        }
        return maxi;
    }

//using Memoization
    int solveUsingMemoization(vector<vector<int>>&dp,int start,int end){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=0){
            return dp[start][end];
        }
        int maxi=INT_MAX;
        for(int i=start;i<=end;i++){
            maxi=min(maxi,i+max(solveUsingMemoization(dp,start,i-1),solveUsingMemoization(dp,i+1,end)));

        }
        dp[start][end]=maxi;
        return dp[start][end];
    }


//using Tabulation
        int solveUsingTabulation(int n) {
        vector<vector<int> > dp(n+2, vector<int>(n+1, 0));
        for(int start_index = n-1; start_index>=1; start_index--) {
            for(int end_index = 1; end_index<=n; end_index++) {

                if(start_index >= end_index) {
                    //invalid range
                    continue;
                }
                int ans = INT_MAX;
                for(int i=start_index; i<=end_index; i++) {
                    ans = min(ans, i + max(dp[start_index][i-1], dp[i+1][end_index] ) );
                }
                dp[start_index][end_index] = ans;
                
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // return solveUsingrecurr(1,n);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return solveUsingMemoization(dp,1,n);

        return solveUsingTabulation(n);
    }
};