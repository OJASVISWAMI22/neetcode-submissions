class Solution {
private:
void backtrace(int index, vector<int>&temp,vector<int>&nums,
vector<vector<int>>&ans){
    if(index==nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    backtrace(index+1,temp,nums,ans);
    temp.pop_back();
    backtrace(index+1,temp,nums,ans);
}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>temp;
        backtrace(0,temp,nums,ans);
        return ans;
    }
};
