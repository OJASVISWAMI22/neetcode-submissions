class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int>ans;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:prereq){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            int it=indegree[i];
            if(it==0){
            q.push(i);
            ans.push_back(i);
            }
        }

        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(auto it:adj[course]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }

        for(int it:indegree){
            if(it!=0){
                return {};
            }
        }

        return ans;
    }
};
