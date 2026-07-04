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
TreeNode* build(int ins,int ine,int prs,int pre,
vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>&hash){
    if(ins>ine || prs>pre){
        return nullptr;
    }
    if(pre==prs){
        return new TreeNode(preorder[pre]);
    }
    if(ins==ine){
        return new TreeNode(inorder[ins]);
    }

    int rootVal=preorder[prs];
    int rootIndex=hash[rootVal];
    TreeNode* root=new TreeNode(rootVal);
    int leftsize=rootIndex-ins;
    root->left=build(ins,rootIndex-1,prs+1,prs+leftsize,preorder,inorder,hash);
    root->right=build(rootIndex+1,ine,prs+leftsize+1,pre,preorder,inorder,hash);
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
       unordered_map<int,int>hash;
       for(int i=0;i<inorder.size();i++){
        hash[inorder[i]]=i;
       }

       return build(0,inorder.size()-1,0,preorder.size()-1,
       preorder,inorder,hash);
    }
};
