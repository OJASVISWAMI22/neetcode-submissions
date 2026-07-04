class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<=farthest){
                farthest=max(farthest,nums[i]+i);
            }
            else
            return false;
            if(farthest>=n-1)
            return true;
        }
        return false;
    }
};
