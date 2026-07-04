class Solution {
private:
    void backtrack(vector<string>&ans,string &s,int n,int open, int close){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n){
        s+='(';
        open++;
        backtrack(ans,s,n,open,close);
        s.pop_back();
        open--;
        }
        if(close < open){
        s+=')';
        close++;
        backtrack(ans,s,n,open,close);
        s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        int o=0,c=0;
        backtrack(ans,s,n,o,c);
        return ans;
    }
};
