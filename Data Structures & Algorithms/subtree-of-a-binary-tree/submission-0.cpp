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
    bool isequal(TreeNode* root,TreeNode* sub){
        if(root && sub){
            if(root ->val != sub->val){
                return false;
            }
            else{
                bool le=isequal(root->left,sub->left);
                bool ri=isequal(root->right,sub->right);
                return le && ri;
            }
        }
        else if(root || sub){
            return false;
        }
        else{
            return true;
        }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root ==nullptr)
        return false;
        if(root->val == subRoot -> val && isequal(root,subRoot)){
            return true;
        }
        return
            isSubtree(root->left,subRoot)||
            isSubtree(root->right,subRoot);
    }
};
