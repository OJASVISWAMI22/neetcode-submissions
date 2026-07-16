class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftProd(n,1);
        vector<int>rightProd(n,1);
        int left=1;
        int right=1;
        for(int i=1;i<n;i++){
            int prod=left*nums[i-1];
            left=prod;
            leftProd[i]=prod;
        }
        for(int j=n-2;j>=0;j--){
            int prod=right*nums[j+1];
            right=prod;
            rightProd[j]=prod;
        }

        for(int i=0;i<n;i++){
            leftProd[i]*=rightProd[i];
        }

        return leftProd;
    }
};
