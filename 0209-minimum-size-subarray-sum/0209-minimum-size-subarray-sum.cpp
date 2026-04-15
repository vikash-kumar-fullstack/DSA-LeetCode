class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0,right=0;
        int win=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                win=min(win,right-left+1);
                sum-=nums[left];
                left++;
            }

        }
        if(win==INT_MAX)return 0;
        return win;
    }
};