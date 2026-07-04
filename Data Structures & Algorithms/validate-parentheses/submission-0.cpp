class Solution {
public:
    bool isValid(string s) {
        stack <char>t;
        for(char c:s){
            if(c == ')' || c == '}' || c == ']'){
                if(t.empty()) return false;

                if(c == ')' && t.top() != '(') return false;
                if(c == '}' && t.top() != '{') return false;
                if(c == ']' && t.top() != '[') return false;

                t.pop();
            }
            else{
                t.push(c);
            }
        }

        return t.empty();
    }
};
