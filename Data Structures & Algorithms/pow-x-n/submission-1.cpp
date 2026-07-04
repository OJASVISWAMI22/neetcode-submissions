class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0,result=1.0;
        if(n==0)
        return 1;
        long long l=n;
        l=abs(l);
        double base=x;
        while(l>0){
            if(l%2!=0){
                ans*=base;
            }
            base*=base;
            l=l/2;
        }
        if(n<0){
            return result/ans;
        }
        return ans;
    }
};
