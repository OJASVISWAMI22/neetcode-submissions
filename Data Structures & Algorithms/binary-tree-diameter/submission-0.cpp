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
    int maxi=0;
    int diameter(TreeNode* temp,int d){
        if(temp==nullptr)
        return 0;
        d++;
        int ld=0,rd=0;
        if(temp->left)ld=diameter(temp->left,d);
        if(temp->right)rd=diameter(temp->right,d);
        maxi=max(maxi,ld+rd);
        return max(ld,rd)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root,0);
        return maxi;
    }
};
