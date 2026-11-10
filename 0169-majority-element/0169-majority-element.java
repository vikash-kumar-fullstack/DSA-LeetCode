class Solution {
    public int majorityElement(int[] nums) {
        int max=nums.length/2;
        Map<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int count=mp.getOrDefault(nums[i],0)+1;
            mp.put(nums[i],count);
            if(count>max)return nums[i];
        }


        // int cand=0;
        // int count=0;
        // for(int x:nums){
        //     if(count==0)cand=x;
        //     count+=(x==cand)?1:-1;
        // }
        // return cand;
        return -1;
    }
}