class Solution {
public:
    // int summ(vector<int>&nums){
    //   int curr=nums[0];
    //   int start=0;
    //   int maxSum=nums[0];
    //   for(int i=1;i<nums.size();i++){
    //     curr=max(nums[i],curr+nums[i]);
    //     maxSum=max(curr,maxSum);
    //   }
    //   return maxSum;
    // }
    // int maxSubArray(vector<int>& nums) {
    //     return summ(nums);
    // }
    // int summ(vector<int>&nums,int index){
    //   if(index>=nums.size())return ;
    //   int include=nums
    // }

    int summ(vector<int>&nums){
        int curr=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            curr=max(nums[i],curr+nums[i]);
            ans=max(ans,curr);
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        return summ(nums);
    }
};