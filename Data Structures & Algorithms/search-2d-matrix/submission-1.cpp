class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st=0,ed=matrix.size()-1;
        int n=matrix[0].size();
        while(st<=ed){
            int mid=st+(ed-st)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1] >=target){
                int s=0,e=n-1;
                while(s<=e){
                    int m=s+(e-s)/2;
                    if(matrix[mid][m]==target){
                        return true;
                    }
                    else if (matrix[mid][m]<target){
                        s++;
                    }
                    else{
                        e--;
                    }
                }
                return false;
            }
            else if (matrix[mid][0]>target){
                ed=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return false;
    }
};
