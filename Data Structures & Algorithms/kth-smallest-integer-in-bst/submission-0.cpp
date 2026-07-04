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
    void dfs(TreeNode* root, priority_queue<int,vector<int>,greater<int>>&q){
        if(!root){
            return;
        }
        q.push(root->val);
        dfs(root->left,q);
        dfs(root->right,q);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        dfs(root,q);
        while(k>1){
            q.pop();
            k--;
        }
        return q.top();
    }
};
