class Solution {
public:
    int MOD = 1e9 + 7;

//using recursion
    int solveUsingRecurr(int n,int k,int target){
        if(target==0 && n ==0){
            return 1;
        }
        if(target!=0 && n ==0)return 0;
        if(target==0 && n !=0)return 0;
        int ans=0;
        for(int i=0;i<k;i++){
            ans=(ans+solveUsingRecurr(n-1,k,target-i))%MOD;
        }
        return ans;
    }

//using Memoization
    
    int solveUsingMemoization(vector<vector<int>>&dp,int n,int k,int target){
        if(target==0 && n ==0){
            return 1;
        }
        if(target!=0 && n ==0)return 0;
        if(target==0 && n !=0)return 0;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            if(target-i>=0){
                ans=(ans+solveUsingMemoization(dp,n-1,k,target-i))% MOD;
            }
        }
        
        return dp[n][target]=ans;
    }

//using Tabulation
    //using Tabulation
    
    int solveUsingTabulation(int n,int k,int target){
        vector<vector<int>>dp(n+2,vector<int>(target+2,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int l=1;l<=k;l++){
                    if(j-l>=0){
                        ans=(ans+dp[i-1][j-l])% MOD;
                        dp[i][j]=ans%MOD;
                    }
                    
                }
            }
        } 
        return dp[n][target];
    }


    //optimisation
    int solveUsingOptimisation(int n,int k,int target){
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int l=1;l<=k;l++){
                    if(j-l>=0){
                        ans=(ans+prev[j-l])% MOD;
                        curr[j]=ans%MOD;
                    }
                    
                }
            }
            prev=curr;
        } 
        return prev[target];
    }


    int numRollsToTarget(int n, int k, int target) {
        
        // return solveUsingRecurr(n,k,target);

        //using memoization
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solveUsingMemoization(dp,n,k,target);
        
        // return solveUsingTabulation(n,k,target);
        return solveUsingOptimisation(n,k,target);
    }
};