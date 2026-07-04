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
    void trav(TreeNode* root, int d, vector<vector<int>>& ans){
        if(!root){
            return;
        }
        if(ans.size()==d){
            ans.push_back({});
        }
        ans[d].push_back(root->val);
        trav(root->left,d+1,ans);
        trav(root->right,d+1,ans);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
        return ans;
        trav(root,0,ans);
        return ans;
    }
};
