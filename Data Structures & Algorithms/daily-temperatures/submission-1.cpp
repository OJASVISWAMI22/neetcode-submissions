class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
        s.push(0);
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            while(!s.empty() && arr[i]>arr[s.top()]){
                int j=s.top();
                ans[j]=i-j;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
