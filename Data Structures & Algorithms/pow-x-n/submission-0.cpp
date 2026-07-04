class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        for(int i=1;i<=abs(n);i++){
            ans*=x;
        }
        double result=1;
        if(n<0){
            return result/ans;
        }
        if(n==0)
        return 1;
        return ans;
    }
};
