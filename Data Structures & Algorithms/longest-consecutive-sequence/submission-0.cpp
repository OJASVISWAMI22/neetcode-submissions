class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hash(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0;
        for(int num:nums){
            if(!hash.count((num-1))){
                int len=1;
                while(hash.count(num+len))
                len++;
                maxi=max(len,maxi);
                
            }
        }
        return maxi;

    }
};
