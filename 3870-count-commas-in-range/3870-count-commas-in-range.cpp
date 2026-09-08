class Solution {
public:
    int countCommas(int n) {
        string str = to_string(n);
        if(str.size() < 4) return 0;

        int count = 0;
        for(int i = 1000 ; i <= n ; i++){
            count++;
        }
        return count;
        
    }
};