class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX;
        int max_profit=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            max_profit=max(max_profit,prices[i]-mini);
        }
        return  max_profit;
    }
};
