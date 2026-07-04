class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        unordered_map<char,int>hash;
        int n=s.size();
        int maxlen=0;
        int maxi=0;
        for(int r=0;r<n;r++){
            hash[s[r]]++;
            maxi=max(maxi,hash[s[r]]);
            while((r-l+1) - maxi >k){
                hash[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
    return maxlen;
    }
};
