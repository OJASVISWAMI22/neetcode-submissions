class Solution {
    bool validate(int m,vector<int>& p,int h){
        int total=0;
        for(int i:p){
            total+=ceil((double)i/m);
        }
        if(total<=h)
{
    return true;
}    
return false;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i:piles){
            maxi=max(maxi,i);
        }
        int mini=INT_MAX;
        int s=1,e=maxi;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(validate(mid,piles,h)){
                mini=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return mini;
    }
};
