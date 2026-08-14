class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int freq = 0;
        int left = 0;
        unordered_map<char , int> mpp;

        for(int right = 0; right < s.length() ; right++){
            mpp[s[right]]++;

            freq = max(freq , mpp[s[right]]);

            while((right - left + 1) - freq > k){
                mpp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen , (right - left + 1));
        }
        return maxlen;
    }
};