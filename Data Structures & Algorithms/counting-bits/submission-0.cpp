class Solution {
    int calculate(int i){
        int count=0;
        while(i){
            count+=i&1;
            i>>=1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i]=calculate(i);
    }
    return ans;
    }
};
