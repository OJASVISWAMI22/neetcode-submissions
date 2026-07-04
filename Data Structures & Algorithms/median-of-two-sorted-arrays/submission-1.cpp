class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int f=0,s=0;
        int target=n1+n2;
        vector<int>ans;
        double result=0.0;
        int toInsert=0;
        while(f<n1 && s<n2){
            if(nums1[f]<=nums2[s]){
                toInsert=nums1[f];
                f++;
            }
            else{
                toInsert=nums2[s];
                s++;
            }
            int final=f+s;
            if(target%2==0){
                if(ans.size()>=2)break;
                if(final==target/2 || final==(target/2)+1){
                    ans.push_back(toInsert);
                }
            } 
            else{
                if(ans.size()>=1)break;
                if(final == (target/2)+1){
                    ans.push_back(toInsert);
                }
            }       
        }
        while(f<n1){
            toInsert=nums1[f];
            f++;
            int final=f+s;
            if(target%2==0){
                if(ans.size()>=2)break;
                if(final==target/2 || final==(target/2)+1){
                    ans.push_back(toInsert);
                }
            } 
            else{
                if(ans.size()>=1)break;
                if(final == (target/2)+1){
                    ans.push_back(toInsert);
                }
            } 
        }
        while(s<n2){
            toInsert=nums2[s];
            s++;
            int final=f+s;
            if(target%2==0){
                if(ans.size()>=2)break;
                if(final==target/2 || final==(target/2)+1){
                    ans.push_back(toInsert);
                }
            } 
            else{
                if(ans.size()>=1)break;
                if(final == (target/2)+1){
                    ans.push_back(toInsert);
                }
            } 
        }
        for(auto it:ans){
            result+=it;
        }
        return result/ans.size();
    }
};
