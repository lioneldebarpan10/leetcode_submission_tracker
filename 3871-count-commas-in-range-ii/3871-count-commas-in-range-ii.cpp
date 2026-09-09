using ll = long long;
class Solution {
public:
    long long countCommas(long long n) {
        string str = to_string(n);
        if(str.size() < 4) return 0;

        ll count = 0 , start = 1000;
        int comma = 1;
        while(start <= n){
            ll end = start * 1000 - 1;
            count += (min(n , end) - start + 1) * comma;
            start = start * 1000; 
            comma++;  
        }
        return count;
    }
};