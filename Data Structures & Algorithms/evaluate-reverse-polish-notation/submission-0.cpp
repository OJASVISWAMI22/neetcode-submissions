class Solution {
    private:
    int eval(int a,int b,char operation){
        if(operation == '+'){
            return a+b;
        }
        if(operation =='-'){
            return a-b;
        }
        if(operation =='*'){
            return a*b;
        }
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        string hardcoded="+-*/";
        for(string c:tokens){
            if(c.size()==1 && hardcoded.find(c[0])!=string::npos){
                int one=s.top();
                s.pop();
                int two=s.top();
                s.pop();
                s.push(eval(two,one,c[0]));
            }
            else{
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
