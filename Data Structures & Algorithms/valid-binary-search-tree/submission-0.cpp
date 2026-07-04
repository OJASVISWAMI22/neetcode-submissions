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
    bool valid(TreeNode* temp, int mini,  int maxi){
        if(!temp)
        return true;
        if(temp->val >=maxi || temp->val <= mini)
        return false;

        return valid(temp->left,mini,temp->val) &&
        valid(temp->right,temp->val,maxi);

    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MIN,INT_MAX);
    }
};
