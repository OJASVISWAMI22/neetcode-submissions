class MinStack {
    stack<int>s;
    stack<int>minis;
public:
    MinStack() {
    }
    
    void push(int val) {
        this->s.push(val);
        if(minis.empty()){
            minis.push(val);
        }
        else{
            int t=this->minis.top();
            if(t>val){
                minis.push(val);
            }
            else{
                minis.push(t);
            }
        }
    }
    
    void pop() {
        this->s.pop();
        this->minis.pop();
    }
    
    int top() {
        return this->s.top();
    }
    
    int getMin() {
        return this->minis.top();
    }
};
