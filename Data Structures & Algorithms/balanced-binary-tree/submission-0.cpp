class Solution {
public:
    int dfs(TreeNode* root, bool& ans) {
        if (root == NULL) {
            return 0;
        }

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);

        if (abs(l - r) > 1) {
            ans = false;
        }

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};