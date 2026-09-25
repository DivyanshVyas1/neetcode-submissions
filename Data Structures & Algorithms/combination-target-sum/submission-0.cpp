class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, int i,vector<int>& curr,int sum){
        if(i==nums.size() || sum>target){
            return;
        }
        if(sum==target){
            if(find(ans.begin(), ans.end(), curr) != ans.end()) {
                return;
            }
            ans.push_back(curr);
        }
        curr.push_back(nums[i]);
        sum+=nums[i];
        solve(nums,target,ans,i,curr,sum);
        curr.pop_back();
        sum-=nums[i];
        solve(nums,target,ans,i+1,curr,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(nums,target,ans,0,curr,0);
        return ans;
    }
};
