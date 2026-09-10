class Solution {
public:
    int helper(int k, vector<int>& piles) {
        int hours = 0;

        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = (low + high) / 2;

            int hours = helper(mid, piles);

            if(hours <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};