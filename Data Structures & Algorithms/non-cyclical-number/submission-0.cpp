class Solution {
    int calc(int i){
        string s=to_string(i);
        int ans=0;
        for(int i=0;i<s.size();i++){
            int temp=s[i]-'0';
            ans+=temp*temp;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        set<int>s;
        while(s.find(n)==s.end()){
            s.insert(n);
            n=calc(n);
            if(n==1)
            return true;
        }
        return false;
    }
};
