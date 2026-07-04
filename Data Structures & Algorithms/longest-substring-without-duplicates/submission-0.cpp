class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.size();
        int l=0,maxi=0;
        for(int i=0;i<n;i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            maxi=max(maxi,i-l+1);
            st.insert(s[i]);
        }
        return maxi;
    }
};
