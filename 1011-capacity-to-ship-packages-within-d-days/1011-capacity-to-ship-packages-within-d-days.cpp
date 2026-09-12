class Solution {
public:
    bool canShip(vector<int>& weights , int days , int capacity){
        int daysNeeded = 1;
        int currentWeight = 0;

        for(int weight : weights){
            if(weight + currentWeight > capacity){
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }
        return daysNeeded <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin() , weights.end() , 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canShip(weights , days , mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};