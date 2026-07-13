class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            switch (nums[i]){
                case 0:
                c0++;
                break;
                case 1:
                c1++;
                break;
                default:
                c2++;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(c0){
                nums[i]=0;
                c0--;
            }
            else if(c1){
                nums[i]=1;
                c1--;
            }
            else{
                c2--;
                nums[i]=2;
            }
        }
    }
};