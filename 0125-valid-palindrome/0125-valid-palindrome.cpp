class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(char ch : s){
            if(isalnum(ch)){
                res += tolower(ch);
            }
        }

        int l = 0 , r = res.size() - 1;
        while(l < r){
            if(res[l] != res[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};