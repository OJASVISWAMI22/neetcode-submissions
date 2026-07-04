class MinStack {
    stack<int>s;
public:
    MinStack() {
        stack<int>s;
        this->s=s;
    }
    
    void push(int val) {
        this->s.push(val);
    }
    
    void pop() {
        this->s.pop();
    }
    
    int top() {
        return this->s.top();
    }
    
    int getMin() {
        stack<int>temp(this->s);
        int mini=INT_MAX;
        while(!temp.empty()){
            int t=temp.top();
            mini=min(mini,t);
            temp.pop();
        }

        return mini;
    }
};
