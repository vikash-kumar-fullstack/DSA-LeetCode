class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0;
        int uni=0;
        Set<Integer> ss=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            if(ss.add(nums[i])){
                nums[j++]=nums[i];
                uni++;
            }
        }
    return uni;
    }
}