class Solution {
public:
    void val(TreeNode* root, long long low, long long high, bool& ans){
        if(root == NULL){
            return;
        }

        if(root->val <= low || root->val >= high){
            ans = false;
            return;
        }

        val(root->left, low, root->val, ans);
        val(root->right, root->val, high, ans);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        val(root, LLONG_MIN, LLONG_MAX, ans);
        return ans;
    }
};