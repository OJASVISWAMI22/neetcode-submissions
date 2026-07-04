class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }

        for(const auto& it:hash){
            if(it.second >n/2){
                return it.first;
            }
        }

        return -1;
    }
};