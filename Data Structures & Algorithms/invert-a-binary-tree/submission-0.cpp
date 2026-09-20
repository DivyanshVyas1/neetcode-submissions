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
public:
    TreeNode* dfs(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* a=dfs(root->left);
        TreeNode* b=dfs(root->right);
        TreeNode* temp=a;

        root->left=b;
        root->right=a;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        root=dfs(root);
        return root;
    }
};
