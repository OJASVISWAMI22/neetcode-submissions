class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i:nums){
            hash[i]++;
            if(hash[i]>1){
                return true;
            }
        }
        return false;
    }
};