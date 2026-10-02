class Solution {
public:
    int dfs(TreeNode* root, bool& ans) {
        if(root==NULL){
            return 0;
        }

        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);

        if(abs(left-right)>1){
            ans=false;
        }

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        dfs(root,ans);
        return ans;
    }
};