class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hash;
        int l=0,maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(hash.find(s[i])!=hash.end()){
                l=max(l,hash[s[i]]+1);
            }
            hash[s[i]]=i;
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};
