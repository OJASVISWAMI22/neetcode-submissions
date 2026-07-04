class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k =k;
        for(int it: nums){
            if(pq.size()<k){
                pq.push(it);
            }
            else if(it>pq.top()){
                pq.pop();
                pq.push(it);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<this->k){
                pq.push(val);
            }
            else if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }

            return pq.top();
    }
};
