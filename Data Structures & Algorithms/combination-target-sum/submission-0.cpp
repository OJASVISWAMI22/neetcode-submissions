class Solution {
    private:
    void backtrack(vector<vector<int>>&ans,vector<int>&temp,
    vector<int>nums,int target, int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        else if(target<0|| index>=nums.size()){
            return;
        }
        temp.push_back(nums[index]);
        backtrack(ans,temp,nums,target-nums[index],index);
        temp.pop_back();
        backtrack(ans,temp,nums,target,index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtrack(ans,temp,nums,target,0);
        return ans;
    }
};
