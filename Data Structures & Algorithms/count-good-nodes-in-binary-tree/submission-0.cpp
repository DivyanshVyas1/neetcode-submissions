class Solution {
public:

    void dfs(TreeNode* root, int maxSoFar, int &ans) {
        if (root == NULL)
            return;

        if (root->val >= maxSoFar)
            ans++;

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar, ans);
        dfs(root->right, maxSoFar, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, ans);
        return ans;
    }
};