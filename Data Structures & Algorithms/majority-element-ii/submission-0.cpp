class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        vector<int>ans;
        for(int i:nums){
            hash[i]++;
            if(hash[i] > n/3){
                if(find(ans.begin(),ans.end(),i)==ans.end())
                ans.push_back(i);
            }
        }

        return ans;
    }
};