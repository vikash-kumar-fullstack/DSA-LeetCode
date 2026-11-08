class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;int minP=Integer.MAX_VALUE;
        for(int p:prices){
            minP=Math.min(minP,p);
            profit=Math.max(profit,p-minP);
        }
        return profit;
    }
}