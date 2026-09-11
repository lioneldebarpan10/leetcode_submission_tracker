class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map<char , int> need;

        for(char ch : t){
            need[ch]++;
        }
        int left = 0 , minLen = INT_MAX , required = t.length(), start = 0;

        for(int right = 0 ; right < s.length() ; right++){

            // Updating the map with current element and it's need
            if(need[s[right]] > 0){
                required--;
            }
            need[s[right]]--;

            // a valid window
            while(required == 0){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                
                // Remove left character
                need[s[left]]++;
                if(need[s[left]] > 0){
                    required++;
                }
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start , minLen);
    }
};