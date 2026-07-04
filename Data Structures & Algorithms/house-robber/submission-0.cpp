class Solution {
    int better(const vector<int>&nums,vector<int>& dp,int i){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-5)
        return dp[i];
        return dp[i]=max(nums[i]+better(nums,dp,i+2),better(nums,dp,i+1));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-5);
        return better(nums,dp,0);
    }
};
