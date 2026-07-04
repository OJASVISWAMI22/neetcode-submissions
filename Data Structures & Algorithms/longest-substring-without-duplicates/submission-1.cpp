class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hash;
        int n=s.size();
        int maxi=0,l=0;
        for(int i=0;i<n;i++){
            if(hash.find(s[i])!=hash.end()){
                l=max(l,hash[s[i]]+1);
            }
            hash[s[i]]=i;
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};
