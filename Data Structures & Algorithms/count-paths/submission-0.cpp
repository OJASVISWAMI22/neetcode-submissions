class Solution {
    private:
    int func(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        else if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-5){
            return dp[i][j];
        }
        return dp[i][j]=func(i+1,j,m,n,dp)+func(i,j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-5));
        return func(0,0,m,n,dp);
    }
};
