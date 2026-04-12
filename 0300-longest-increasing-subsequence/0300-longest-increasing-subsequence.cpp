class Solution {
public:
//using recursion
    int solveUsingRecursion(vector<int>&nums,int index,int prev){
        if(index>=nums.size()){
            return 0;
        }
        //include
        int ans1=0;
        if(prev==-1 || nums[index]>nums[prev]){
            ans1=1+solveUsingRecursion(nums,index+1,index);
        }
        //exclude
        int ans2=solveUsingRecursion(nums,index+1,prev);
        return max(ans1,ans2);
    }

//using memoization
        int solveUsingMemoization(vector<vector<int>>&dp,vector<int>&nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
        //index shifting
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //include
        int ans1=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            ans1=1+solveUsingMemoization(dp,nums,curr+1,curr);
        }
        //exclude
        int ans2=solveUsingMemoization(dp,nums,curr+1,prev);
        dp[curr][prev+1]=max(ans1,ans2);
        return dp[curr][prev+1];
    }

//using tabulation
        int solveUsingTabulation(vector<int>&nums){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int ans1=0;
                if(j==-1 || nums[i]>nums[j]){
                    ans1=1+dp[i+1][i+1];
                }
                //exclude
                int ans2=dp[i+1][j+1];
                dp[i][j+1]=max(ans1,ans2);
            }
        }
        
        return dp[0][0];
    }


//space Optimisation
        int solveUsingOptimisation(vector<int>&nums){
        vector<int>prev(nums.size()+1,0);
        vector<int>curr(nums.size()+1,0);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int ans1=0;
                if(j==-1 || nums[i]>nums[j]){
                    ans1=1+prev[i+1];
                }
                //exclude
                int ans2=prev[j+1];
                curr[j+1]=max(ans1,ans2);
            }
            prev=curr;
        }
        
        return curr[0];
    }

//using binarySearch
    int solveUsingBS(vector<int>&nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
    // int curr=0;
    // int prev=-1;
    // int ans=solveUsingRecursion(nums,curr,prev);
    // return ans;

    //using Memoization
    // int ans=solveUsingTabulation(nums);
    // return ans;

    //using Optimisation
    // int ans=solveUsingOptimisation(nums);
    // return ans;

    //using binary Search
    int ans=solveUsingBS(nums);
    return ans;
    }
};