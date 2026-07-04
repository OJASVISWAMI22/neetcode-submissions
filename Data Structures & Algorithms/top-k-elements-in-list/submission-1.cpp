class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        for(int i:nums){
            hash[i]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto& [f,s]:hash){
            bucket[s].push_back(f);
        }
        vector<int>ans;
        for(int i=nums.size();i>=0 && ans.size()<k;i--){
            for(int x:bucket[i]){
                ans.push_back(x);
            }
        }
        return ans;
    }
};
