class Solution {
    int calc(vector<int>&cost, int i, vector<int>&dp){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=cost[i]+min(calc(cost,i+1,dp),calc(cost,i+2,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        int ans=min(calc(cost, 0, dp1), calc(cost, 1, dp2));

        return ans;
    }
};
