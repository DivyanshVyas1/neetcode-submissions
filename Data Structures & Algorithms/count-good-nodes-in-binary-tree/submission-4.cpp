class Solution {
public:
    void dfs(TreeNode* root, int maxi, int& ans) {
        if(root == NULL) {
            return;
        }

        if(root->val >= maxi) {
            ans++;
        }

        maxi = max(maxi, root->val);

        dfs(root->left, maxi, ans);
        dfs(root->right, maxi, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, ans);
        return ans;
    }
};