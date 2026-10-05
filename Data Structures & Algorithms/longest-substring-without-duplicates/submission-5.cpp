class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        for(int j = 0; j < s.size(); j++) {
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }

            mp[s[j]] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};