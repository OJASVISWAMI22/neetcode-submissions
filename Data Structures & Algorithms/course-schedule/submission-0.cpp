class Solution {
private:
bool dfs(int i,const vector<vector<int>>&pre,unordered_set<int>&visiting,
vector<bool>&visited){
    if(visiting.find(i)!=visiting.end()){
        return true;
    }
    if(visited[i]){
        return false;
    }
    visiting.insert(i);

    for(auto it : pre){
        if(it[0] == i){
            int next = it[1];

            if(dfs(next, pre, visiting, visited))
                return true;
        }
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
        for(int i=0;i<n;i++){
            if(!visited[i]){
                unordered_set<int>visiting;
                ans=dfs(i,pre,visiting,visited);
                if(ans==true){
                    return false;
                }
            }
        }
        return true;
    }
};
