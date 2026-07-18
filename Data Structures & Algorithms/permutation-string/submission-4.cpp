class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2=s2.size();
        int n1=s1.size();
        if(n2<n1){
            return false;
        }
        unordered_map<char,int>hash1,hash2;

        for(char c:s1){
            hash1[c]++;
        }

        for(int i=0;i<=n2-n1;i++){
            hash2=hash1;
            for(int j=i;j<i+n1;j++){
                hash2[s2[j]]--;
            }
            bool found=true;
            for(auto it:hash2){
                if(it.second!=0){
                    found=false;
                    break;
                }
            }

            if(found){
                return true;
            }
        }

        return false;
    }
};
