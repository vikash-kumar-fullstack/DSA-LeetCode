class Solution {
public:

//rec+memoization
    // int ans(vector<int>&dp,vector<int>&nums,int num){
    //     if(num>=nums.size()){
    //         return 0;
    //     }
    //     if(dp[num]!=-1){
    //         return dp[num];
    //     }
    //     //exclude
    //     int exclude=0+ans(dp,nums,num+1);
    //     //include
    //     int include=nums[num]+ans(dp,nums,num+2);
    //     dp[num]=max(exclude,include);
    //     return dp[num];
    // }

    //tabulation method
    // int solveUsingTabulation(vector<int>&nums,int index){
    //     //step1- creation of dp
    //     int n=nums.size();
    //     vector<int>dp(n,-1);

    //     //filling the base case
    // // step:-2
    //     dp[n-1]=nums[n-1];

    // //step3:-
    // for(int i=n-2;i>=0;i--){
    //     //exclude
    //     int exclude=0+dp[i+1];
    //     //include
    //     int temp=0;
    //     if(i+2<n){
    //         temp=dp[i+2];
    //     }
    //     int include=nums[i]+temp;
    //     dp[i]=max(include,exclude);
    // }
    //     return dp[0];

    // }

//space optimisation
    int solveUsingSpaceOp(vector<int>&nums,int index){
    int n=nums.size();
    if(n==1){
        return nums[n-1];
    }
    int prev=0;
    int next=nums[n-1];
    int ans=-1;
    int exclude;
    int include;
    for(int i=n-2;i>=0;i--){
        exclude=0+next;
        include=nums[i]+prev;
        ans=max(exclude,include);
        prev=next;
        next=ans;
    }
        return ans;
    }
    int rob(vector<int>& nums) {
        //method1:-
        // vector<int>dp(nums.size(),-1);
        // return ans(dp,nums,0);

        //tabulation method
        // return solveUsingTabulation(nums,0);


        //space optimisation
        return solveUsingSpaceOp(nums,0);
    }
};