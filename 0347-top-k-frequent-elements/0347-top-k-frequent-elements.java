class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp=new HashMap<>();
        for(int num:nums){
            int count=mp.getOrDefault(num,0);
            mp.put(num,count+1);
        }
        List<Integer>li=new ArrayList<>(mp.keySet());
        li.sort((a,b)->mp.get(b)-mp.get(a));
        int [] res=new int[k];
        for(int i=0;i<k;i++){
            res[i]=li.get(i);
        }
        return res;
    }
}