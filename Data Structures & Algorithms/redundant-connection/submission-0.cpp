class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    bool unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb){
            return false;
        }
        if(rank[pa]>=rank[pb]){
            rank[pa]+=rank[pb];
            parent[pb]=pa;
        }else{
            rank[pb]+=rank[pa];
            parent[pa]=pb;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU *d= new DSU(n+1);
        for(auto  it:edges){
            if(!d->unite(it[0],it[1])){
                delete d;
                return it;
            }
        }
        delete d;
        return {};
    }
};
