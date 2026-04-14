class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum=0;
        double maxWin=0;
        for(int i=0;i<k;i++){
            maxSum+=nums[i];
        }
        maxWin=maxSum;
        for(int i=k;i<nums.size();i++){
            maxWin+=nums[i];
            maxWin-=nums[i-k];
            maxSum=max(maxWin,maxSum);
        }
        return maxSum/k;
    }
};