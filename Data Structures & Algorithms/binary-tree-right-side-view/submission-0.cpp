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
    void dfs(TreeNode* root,int d,vector<int>&ans){
        if(!root){
            return;
        }
        if(d==ans.size()){
            ans.push_back(root->val);
        }
        else{
            ans[d]=root->val;
        }
        dfs(root->left,d+1,ans);
        dfs(root->right,d+1,ans);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,0,ans);
        return ans;
    }
};
