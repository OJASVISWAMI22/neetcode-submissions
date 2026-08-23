class Solution {
    void dfs(int i,vector<bool>&visited,vector<vector<int>>&adj){
        visited[i]=true;
        for(auto  it:adj[i]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }

        return count;
    }
};
