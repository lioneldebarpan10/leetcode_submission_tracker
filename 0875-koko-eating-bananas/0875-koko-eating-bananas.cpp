class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            // ceil(bananas / k) -> time for this pile
            hours += (bananas + k - 1) / k; 
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;                      // minimum possible speed
        int right = *max_element(piles.begin(), piles.end()); // maximum possible speed
        int ans = right;                   // store best answer

        while (left <= right) {
            int mid = left + (right - left) / 2; // try middle speed
            if (canEatAll(piles, h, mid)) {
                ans = mid;        // possible answer -> try to minimize
                right = mid - 1;  // search on the left side
            } else {
                left = mid + 1;   // need to increase speed
            }
        }
        return ans;
    }
};