class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(),n2=num2.size();
        if(num1=="0" || num2=="0")
        return "0";
       vector<int>ans(n1+n2,0);

       for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            int pos1=i+j;
            int pos2=i+j+1;
            int mul = (num1[i]-'0') * (num2[j] -'0');
            mul += ans[pos2];
            ans[pos2]=mul%10;
            ans[pos1]+=mul/10;
        }
       }

       string s;
       int ptr=0;
       while(ptr<ans.size() && ans[ptr]==0){
        ptr++;
       }
       while(ptr<ans.size()){
        s.push_back(ans[ptr]+'0');
        ptr++;
       }

       return s;
    }
};
