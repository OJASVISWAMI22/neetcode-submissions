class Solution {
    int better(const vector<int>&nums,vector<int>& dp,int i,int end){
        if(i>=end){
            return 0;
        }
        if(dp[i]!=-5)
        return dp[i];
        return dp[i]=max(nums[i]+better(nums,dp,i+2,end),better(nums,dp,i+1,end));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp1(n+1,-5);
        vector<int>dp2(n+1,-5);
        int onechoosen=better(nums,dp1,0,n-1);
        int lastchoosen=better(nums,dp2,1,n);
        return max(onechoosen,lastchoosen);
    }
};
