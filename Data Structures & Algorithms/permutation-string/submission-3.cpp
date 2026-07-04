class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a=s1.size();
        int b=s2.size();
        vector<int>freq1(26,0),freq2(26,0);
        if(a>b){
            return false;
        }
        for(int i=0;i<a;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)
        return true;
        for(int i=a;i<b;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-a]-'a']--;
            if(freq2==freq1){
                return true;
            }
        }
        return false;
    }
};
