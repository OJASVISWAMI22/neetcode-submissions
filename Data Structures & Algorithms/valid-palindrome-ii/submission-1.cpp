class Solution {
private:
bool check(string s, int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        r--;
        l++;
    }
    return true;
}
public:
    bool validPalindrome(string s) {
        int count =0;
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                return (check(s,l+1,r) || check(s,l,r-1));
            }
            else{
            l++;
            r--;
            }
        }

        return true;
    }
};