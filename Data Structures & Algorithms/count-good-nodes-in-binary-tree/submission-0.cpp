/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
void countGoodNodes(TreeNode* root, int& c,int m){
    if(root){
        if(root->val >= m){
            c++;
            m=root->val;
        }
    }
    else{
        return ;
    }
    countGoodNodes(root->left,c,m);
    countGoodNodes(root->right,c,m);

}
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        int maxi=INT_MIN;
        countGoodNodes(root,count,maxi);
        return count;
    }
};
