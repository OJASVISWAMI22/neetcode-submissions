class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>> adj(n);

        for(auto pre : prerequisites){
            int course = pre[0];
            int prerequisite = pre[1];

            indegree[course]++;
            adj[prerequisite].push_back(course);
        }
        bool found=false;
        queue<int>q;
        for( int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                found=true;
            }
        }
        if(!found){
            return false;
        }

        while(!q.empty()){
            int id=q.front();
            q.pop();
            for(int course : adj[id]){
                indegree[course]--;

                if(indegree[course] == 0){
                    q.push(course);
                }
            }
        }

        for(auto it:indegree){
            if(it>0){
                return false;
            }
        }
        return true;
    }
};
