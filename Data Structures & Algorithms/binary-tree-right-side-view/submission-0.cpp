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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*> temp;
        temp.push(root);
        if(root == nullptr)
            return {};

        while(!temp.empty()){
            int n=temp.size();
            for(int i=0;i<n;i++){
                TreeNode* curr = temp.front();
                temp.pop();
                if (i==n-1) ans.push_back(curr->val);
                if (curr->left) temp.push(curr->left);
                if (curr->right) temp.push(curr->right);
            } 
        }
        return ans;
    }
};
