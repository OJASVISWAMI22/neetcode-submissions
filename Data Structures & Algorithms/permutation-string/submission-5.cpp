class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2=s2.size();
        int n1=s1.size();
        if(n2<n1){
            return false;
        }
        vector<int>needed(26,0);
        vector<int>present(26,0);
        for(char c:s1){
            needed[c-'a']++;
        }

        for(int i=0;i<n1;i++){
           present[s2[i]-'a']++;
        }
        if(present==needed)
        return true;

        for(int i=n1;i<n2;i++){
            present[s2[i-n1]-'a']--;
            present[s2[i]-'a']++;
            if(needed==present){
                return true;
            }
        }

        return false;
    }
};
