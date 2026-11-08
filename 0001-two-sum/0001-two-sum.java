class Solution {
    public int[] twoSum(int[] nums, int target) {
       Map<Integer,Integer>li=new HashMap<>();
       for(int i=0;i<nums.length;i++){
        int need=target-nums[i];
        if(li.containsKey(need))return new int[]{li.get(need),i};
        li.put(nums[i],i);
       }
       return new int[]{};
    }
    
}