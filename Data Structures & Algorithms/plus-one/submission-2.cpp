class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        long long result=0;
        for(int i:digits){
            result=result*10+i;
        }
        result+=1;
        int i=0;
        while(result){
            ans.insert(ans.begin(),result%10);
            result/=10;
        }

        return ans;
    }
};
