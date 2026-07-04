class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[n]=true;

        for(int i=n-1;i>=0;i--){
            for(string it:wordDict){
                int length=it.size();

                if(i+length<=n && s.substr(i,length)==it
                && dp[i+length]){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
