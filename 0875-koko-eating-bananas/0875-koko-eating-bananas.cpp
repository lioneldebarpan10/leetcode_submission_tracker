class Solution {
public:
    bool canEat(vector<int>&piles , int h , int speed){
        long long hours = 0;
        for(int bananas : piles){
            // hours += ceil(piles / speed)
            hours += (bananas + speed - 1) / speed;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin() , piles.end());
        
        while(low <= high){
            int mid = low + (high - mid) / 2;

            if(canEat(piles , h , mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    
    }
};