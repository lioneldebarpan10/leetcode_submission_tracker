class Solution {
public:
    bool checkValidString(string s) {
        
        int low = 0; // 'low' = minimum number of open brackets we might have
        int high = 0; // 'high' = maximum number of open brackets we might have
        for(char ch : s){
            // A '(' always increases both low and high
            if(ch == '('){
                low++;
                high++;
            }// A ')' decreases high (we're closing an open bracket)
            // If low > 0, decrease low (because we could close one open '(')
            else if(ch == ')'){
                if(low > 0) low--;
                high--;
            }
            else{ // ch == '*'
            // '*' can act as '(', ')' or empty
            // So: - we decrease 'low' (if possible) to simulate it as ')'
            // - we increase 'high' to simulate it as '('
                if(low > 0) low--;
                high++;
            }
            if(high < 0) return false;// If high becomes negative, we have too many ')' to balance
        }
        return low == 0; // If low == 0, we have a valid expression
        
    }
};