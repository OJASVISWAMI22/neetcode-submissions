class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        if(n){
            ans.push_back(intervals[0]);
        }
        int pos=0;
        for(int i=1;i<n;i++){
            if(ans[pos][1] < intervals[i][0]){
                ans.push_back(intervals[i]);
                pos++;
            }
            else{
                ans[pos][1] = max(ans[pos][1], intervals[i][1]);
            }
        }
        return ans;
    }
};
