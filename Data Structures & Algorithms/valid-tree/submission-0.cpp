class DSU {
    vector<int> parent, size;

public:
    DSU(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;

        if (size[pa] < size[pb]) {
            swap(pa, pb);
        }

        parent[pb] = pa;
        size[pa] += size[pb];

        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        DSU d(n);
        for(auto it:edges){
            if(!d.unite(it[0],it[1])){
                return false;
            }
        }
        return true;
    }
};
