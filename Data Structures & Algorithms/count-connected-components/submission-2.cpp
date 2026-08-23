class dsu {
private:
    vector<int>parent,size;
public:
    dsu(int n){
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        size.resize(n,1);
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb){
            return false;
        }
        if(size[pa]<size[pb]){
            size[pb]+=size[pa];
            parent[pa]=pb;
        }else{
            size[pa]+=size[pb];
            parent[pb]=pa;
        }
        return true;
    }

};
class Solution {
    // void dfs(int i,vector<bool>&visited,vector<vector<int>>&adj){
    //     visited[i]=true;
    //     for(auto  it:adj[i]){
    //         if(!visited[it]){
    //             dfs(it,visited,adj);
    //         }
    //     }
    // }
private:

public:
    // int countComponents(int n, vector<vector<int>>& edges) {
    //     int count=0;
    //     vector<vector<int>>adj(n);
    //     for(auto it:edges){
    //         adj[it[0]].push_back(it[1]);
    //         adj[it[1]].push_back(it[0]);
    //     }
    //     vector<bool>visited(n,false);
    //     for(int i=0;i<n;i++){
    //         if(!visited[i]){
    //             dfs(i,visited,adj);
    //             count++;
    //         }
    //     }

    //     return count;
    // }
    //using dsu 
    int countComponents(int n, vector<vector<int>>& edges) {
        dsu d(n);
        int count=n;
        for(auto it:edges){
            if(d.unite(it[0],it[1])){
                count--;
            }
        }
        return count;
    }
};

