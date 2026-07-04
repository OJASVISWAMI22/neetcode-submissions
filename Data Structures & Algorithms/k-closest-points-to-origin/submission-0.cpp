class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<
        pair<int, vector<int>>,
        vector<pair<int, vector<int>>>,
        greater<pair<int, vector<int>>>
    > q;
        for(int i=0;i<points.size();i++){
            q.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            vector<int>temp=q.top().second;
            q.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
