class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res = ""; 

        for(int i = 0 ; i < n ; i++){
            int l = i , r = i;

            while(l >= 0 && r < n && s[l] == s[r]){
                if((r - l + 1) > maxlen){
                    maxlen = (r - l  + 1);
                    res = s.substr(l , (r - l + 1));
                }
                l--;
                r++;
            }
            
            l = i , r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if((r - l + 1) > maxlen){
                    maxlen = (r - l + 1);
                    res = s.substr(l , (r - l + 1));
                }
                l--;
                r++;    
            }
        }
        return res;
        
    }
};