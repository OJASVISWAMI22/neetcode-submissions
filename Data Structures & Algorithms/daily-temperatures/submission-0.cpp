class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
