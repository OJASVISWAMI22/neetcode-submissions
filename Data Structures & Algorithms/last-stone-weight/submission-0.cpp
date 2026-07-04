class Solution {
    
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;

        for(int st:stones){
            q.push(st);
        }
        while(q.size()>1){
        int first=q.top();
        q.pop();
        int second=q.top();
        q.pop();
        if(first!=second){
            q.push(abs(second-first));
        }
    }
    return q.empty()?0:q.top();
    }
};
