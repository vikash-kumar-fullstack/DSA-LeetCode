class Solution {
    public int missingNumber(int[] nums) {
        int x=nums.length;
        int n=x;
        for(int i=0;i<n;i++){
            x=x^i^nums[i];
        }
        return x;
    }
}