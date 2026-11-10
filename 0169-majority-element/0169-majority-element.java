class Solution {
    public int majorityElement(int[] nums) {
        // Map<Integer,Integer>mp=new HashMap<>();
        // for(int i=0;i<nums.length;i++){
        //     mp.put(nums[i],mp.get(nums[i]++));
        // }

        // Collections.reverse(mp);

        int cand=0;
        int count=0;
        for(int x:nums){
            if(count==0)cand=x;
            count+=(x==cand)?1:-1;
        }
        return cand;
    }
}