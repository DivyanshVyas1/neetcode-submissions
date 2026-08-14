class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int right=0;
        int left=0;
        int maxi=0;
        int maxl=0;
        while(right<s.size()){
            mp[s[right]]++;
            maxi=max(maxi,mp[s[right]]);

            while(right-left+1-maxi>k){
                mp[s[left]]--;
                left++;
            }
            maxl=max(maxl,right-left+1);
            right++;
        }
        return maxl;
    }
};
