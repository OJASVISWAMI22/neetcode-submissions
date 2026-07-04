class Solution {
private:
bool dfs(int i,const vector<vector<int>>&adj,unordered_set<int>&visiting,
vector<bool>&visited){
    if(visiting.find(i)!=visiting.end()){
        return true;
    }
    if(visited[i]){
        return false;
    }
    visiting.insert(i);

    for(auto it : adj[i]){
        if(dfs(it,adj,visiting,visited))
        return true;
    }

    visiting.erase(i);
    visited[i]=true;
    return false;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<bool>visited(n,false);
        bool ans;
        vector<vector<int>>adj(n);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                unordered_set<int>visiting;
                ans=dfs(i,adj,visiting,visited);
                if(ans==true){
                    return false;
                }
            }
        }
        return true;
    }
};
