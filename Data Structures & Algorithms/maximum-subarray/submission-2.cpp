class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0],currsum=0;
        for(auto it:nums){
            currsum+=it;
            maxi = max(maxi,currsum);
            if(currsum <0){
                currsum = 0;
            }
        }
        return maxi;
    }
};
