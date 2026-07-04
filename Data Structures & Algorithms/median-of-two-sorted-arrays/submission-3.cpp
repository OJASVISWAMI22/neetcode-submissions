class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0;
        int h = n1;

        while (l <= h) {

            int cut1 = (l + h) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int R1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int R2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (L1 <= R2 && L2 <= R1) {

                if ((n1 + n2) % 2 == 0) {
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                }

                return max(L1, L2);
            }

            else if (L1 > R2) {
                h = cut1 - 1;
            }

            else {
                l = cut1 + 1;
            }
        }

        return 0;
    }
};







    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size();
    //     int n2=nums2.size();
    //     int f=0,s=0;
    //     int target=n1+n2;
    //     vector<int>ans;
    //     double result=0.0;
    //     int toInsert=0;
    //     while(f<n1 && s<n2){
    //         if(nums1[f]<=nums2[s]){
    //             toInsert=nums1[f];
    //             f++;
    //         }
    //         else{
    //             toInsert=nums2[s];
    //             s++;
    //         }
    //         int final=f+s;
    //         if(target%2==0){
    //             if(ans.size()>=2)break;
    //             if(final==target/2 || final==(target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         } 
    //         else{
    //             if(ans.size()>=1)break;
    //             if(final == (target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         }       
    //     }
    //     while(f<n1){
    //         toInsert=nums1[f];
    //         f++;
    //         int final=f+s;
    //         if(target%2==0){
    //             if(ans.size()>=2)break;
    //             if(final==target/2 || final==(target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         } 
    //         else{
    //             if(ans.size()>=1)break;
    //             if(final == (target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         } 
    //     }
    //     while(s<n2){
    //         toInsert=nums2[s];
    //         s++;
    //         int final=f+s;
    //         if(target%2==0){
    //             if(ans.size()>=2)break;
    //             if(final==target/2 || final==(target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         } 
    //         else{
    //             if(ans.size()>=1)break;
    //             if(final == (target/2)+1){
    //                 ans.push_back(toInsert);
    //             }
    //         } 
    //     }
    //     for(auto it:ans){
    //         result+=it;
    //     }
    //     return result/ans.size();
    // }