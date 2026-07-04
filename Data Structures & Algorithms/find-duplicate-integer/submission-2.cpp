class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(i<n && j<n){
            i=nums[i];
            j=nums[nums[j]];
            if(i==j){
                i=0;
                while(i!=j){
                    i=nums[i];
                    j=nums[j];
                }
                return i;
            }
        }

        return 1;
    }
};
