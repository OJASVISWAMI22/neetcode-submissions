class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int majEl=nums[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==majEl){
                count++;
            }
            else{
                count--;
                if(count==0){
                    majEl=nums[i];
                    count++;
                }
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majEl){
                count++;
            }
        }
        if(count>n/2)
        return majEl;

        return -1;
    }
};