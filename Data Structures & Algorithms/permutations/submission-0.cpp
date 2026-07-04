class Solution {
    private :
    void backtrack(vector<int>& nums,vector<bool>&used,
    vector<vector<int>>&ans,vector<int>&temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            temp.push_back(nums[i]);
            backtrack(nums,used,ans,temp);
            temp.pop_back();
            used[i]=false;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>temp;
        vector<bool>used(n,false);
        backtrack(nums,used,ans,temp);
        return ans;
    }
};
