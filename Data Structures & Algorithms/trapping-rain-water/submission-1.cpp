class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int s=0,e=n-1;
        int leftMax=height[0],rightMax=height[n-1];
        while(s<e){
            if(height[s] < height[e]){
                leftMax=max(leftMax,height[s]);
                if((leftMax-height[s])>0){
                    ans+=leftMax-height[s];
                }
                s++;
            }
            else{
                rightMax=max(rightMax,height[e]);
                if((rightMax-height[e])>0){
                    ans+=rightMax-height[e];
                }
                e--;
            }
        }

        return ans;
    }
};
