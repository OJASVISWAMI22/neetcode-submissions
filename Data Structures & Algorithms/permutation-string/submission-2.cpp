class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int s=s1.size();
        unordered_map<char,int>hash1;
        for(auto it:s1){
            hash1[it]++;
        }
        for(int l=0;l<=s2.size()-s;l++){
            int r=l+s;
            unordered_map<char,int>hash2;
            for(int i=l;i<r;i++){
                hash2[s2[i]]++;
            }
            if(hash1==hash2){
                return true;
            }
        }
        return false;
    }
};
