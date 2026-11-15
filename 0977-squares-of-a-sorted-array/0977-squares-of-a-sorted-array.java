class Solution {
    public int[] sortedSquares(int[] nums) {
        int [] li=new int[nums.length];
        int l=0,r=nums.length-1;
        int i=nums.length-1;
        while(l<=r){
            if(Math.abs(nums[l])>Math.abs(nums[r])){
                li[i--]=nums[l]*nums[l];
                l++;
            }else{
                li[i--]=nums[r]*nums[r];
                r--;
            }
        }
        return li;
    }
}