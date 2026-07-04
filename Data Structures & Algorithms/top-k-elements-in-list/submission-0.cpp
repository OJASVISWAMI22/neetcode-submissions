class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        vector<int>ans;
        vector<pair<int,int>>temp;
        for(auto it:hash){
            temp.push_back(it);
        }
        sort(temp.begin(),temp.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
