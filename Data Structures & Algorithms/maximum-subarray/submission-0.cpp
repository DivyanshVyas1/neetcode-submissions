class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        int i=0;
        int j=0;
        while (j<nums.size()) {
            if (sum<=nums[j] && sum<0) {
                sum=0;
                i=j;
            }
            sum+=nums[j];
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};
