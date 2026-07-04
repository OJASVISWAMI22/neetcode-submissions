class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(hash.find(rem)==hash.end()){
                hash[nums[i]]=i;
            }
            else{
                return {hash[rem],i};
            }
        }
        return {-1,-1};
    }
};
