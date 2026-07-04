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
        vector<int>dp(n+2,0);
        int prev1=0,prev2=0;
        for(int i=n-1;i>=0;i--){
            int curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
