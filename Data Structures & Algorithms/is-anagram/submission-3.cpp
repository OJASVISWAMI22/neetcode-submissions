class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        unordered_map<char,int>hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(hash.find(t[i])==hash.end())
            return false;
            hash[t[i]]--;
        }

        for(auto it:hash){
            if(it.second!=0)
            return false;
        }

        return true;
    }
};
