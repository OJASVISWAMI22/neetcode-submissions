class Solution {
private:
    int fun(vector<int>&dp, int amount , vector<int>&coins){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return 1e9;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=1e9;
        for(auto it:coins){
            ans=min(ans,1+fun(dp,amount-it,coins));
        }
        return dp[amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans=fun(dp,amount,coins);
        if(ans==1e9)
        return -1;
        return ans;
    }
};
