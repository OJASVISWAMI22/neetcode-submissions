class Solution {
    private:
    void dfs(int i,vector<vector<int>>&e,vector<int>&visited){
        visited[i]=1;
        for(int j=0;j<e.size();j++){
            if(e[j][0]==i){
                if(!visited[e[j][1]])
                dfs(e[j][1],e,visited);
            }
            else if(e[j][1]==i){
                if(!visited[e[j][0]])
                dfs(e[j][0],e,visited);
            }
            else{
                continue;
            }
        }
        return ;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited);
                count++;
            }
        }
        return count;
    }
};
