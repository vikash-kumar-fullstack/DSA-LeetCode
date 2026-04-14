class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            mn=min(mn,prices[i]);
            int new_profit=prices[i]-mn;
            profit=max(profit,new_profit);
        }
        return profit;
    }
};