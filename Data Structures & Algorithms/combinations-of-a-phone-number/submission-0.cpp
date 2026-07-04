class Solution {
void backtrack(int i,string& digits,string& s,vector<string>&mp,vector<string>&ans){
    if(i==digits.size()){
        ans.push_back(s);
        return;
    }
    int digit=digits[i]-'0';
    for(char c:mp[digit]){
        s.push_back(c);
        backtrack(i+1,digits,s,mp,ans);
        s.pop_back();
    }

}
public:
    vector<string> letterCombinations(string digits) {
        vector<string>mp={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        if(digits.empty())
    return {};
        vector<string>ans;
        string s="";
        backtrack(0,digits,s,mp,ans);
        return ans;
    }
};
