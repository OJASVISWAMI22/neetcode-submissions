class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;

        for(string s:strs){
            string key=s;
            sort(s.begin(),s.end());
            hash[s].push_back(key);
        }
        vector<vector<string>>ans;
        for(auto& [f,s]:hash){
            ans.push_back(s);
        }

        return ans;
    }
};
