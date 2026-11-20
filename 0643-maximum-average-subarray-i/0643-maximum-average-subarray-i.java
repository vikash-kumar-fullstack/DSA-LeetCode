class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int sum=0;int best =0;
        for(int i=0;i<k;i++)sum+=nums[i];
        best=sum;
        for(int i=k;i<nums.length;i++){
            sum+=nums[i]-nums[i-k];
            best=Math.max(sum,best);

        }
        return (double) best/k;
    }
}