class Solution {
public:

//using recursion
    bool solveUsingRecurr(vector<int>& nums,int index,int size,int target,int sum){
        if(index>=size || target<sum){
            return false;
        }
        if(target==sum){
            return true;
        }
        //include
        bool include=solveUsingRecurr(nums,index+1,size,target,sum+nums[index]);
        //exclude
        bool exclude=solveUsingRecurr(nums,index+1,size,target,sum);
        return include || exclude;
    }
//using Memoization
    bool solveUsingMemoization(vector<vector<int>>&dp,vector<int>& nums,int index,int size,int target,int sum){
        if(index>=size || target<sum){
            return false;
        }
        if(target==sum){
            return true;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        //include
        bool include=solveUsingMemoization(dp,nums,index+1,size,target,sum+nums[index]);
        //exclude
        bool exclude=solveUsingMemoization(dp,nums,index+1,size,target,sum);
        dp[index][sum]=(include || exclude);
        return dp[index][sum];
    }

//using Tabulation
    bool solveUsingTabulation(vector<int>& nums,int index,int size,int target,int sum){
        vector<vector<bool>>dp(size+1,vector<bool>(target+1,false));
        for(int i=index;i<=size;i++){
            dp[i][target]=true;
        }
        for(int i=size-1;i>=0;i--){
            for(int j=target-1;j>=0;j--){
                //include
                bool include;
                if(j+nums[i]<=target){
                    include=dp[i+1][j+nums[i]];
                }
                //exclude
                bool exclude=dp[i+1][j];
                dp[i][j]=(include || exclude);
            }
        }
        return dp[0][0];
    }
//using Optimisation
    bool solveUsingOptimisation(vector<int>& nums,int index,int size,int target,int sum){
        vector<bool>prev(target+1,false);
        vector<bool>next(target+1,false);
        prev[target]=true;
        next[target]=true;
        for(int i=size-1;i>=0;i--){
            for(int j=target;j>=0;j--){
                //include
                bool include;
                if(j+nums[i]<=target){
                    include=prev[j+nums[i]];
                }
                //exclude
                bool exclude=prev[j];
                next[j]=(include || exclude);
            }
            prev=next;
        }
        return next[0];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1){
            return false;
        }else{
            int target=sum/2;
            //using recursion
            // return solveUsingRecurr(nums,0,n,target,0);

            // using Memoization
            // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
            // return solveUsingMemoization(nums,0,n,target,0);


             // using Tabulation
            // return solveUsingTabulation(nums,0,n,target,0);


             // using Optimisation
            return solveUsingOptimisation(nums,0,n,target,0);
        }
        
    }
};