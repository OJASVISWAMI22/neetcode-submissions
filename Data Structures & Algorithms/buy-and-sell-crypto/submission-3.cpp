class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            mini=min(prices[i],mini);

            maxi=max(prices[i]-mini,maxi);
        }
        return maxi;
    }
};
