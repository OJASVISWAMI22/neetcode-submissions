class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string c:strs){
            res+=to_string(c.size())+'@'+c;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0,n=s.size();
        while(i<n){
            int j=i;
            while(s[j]!='@'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+1+len;
        }
        return ans;
    }
};
