class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int newSum=a^b;
            int newCarry=(a&b)<<1;
            a=newSum;
            b=newCarry;
        }
        return a;
    }
};
