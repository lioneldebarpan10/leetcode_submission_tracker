class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word doesn't belong to words
                if (!required.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                seen[word]++;
                count++;

                // Too many occurrences of this word
                while (seen[word] > required[word]) {
                    string leftWord = s.substr(left, wordLen);

                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found concatenation of all words
                if (count == wordCount) {
                    ans.push_back(left);
                }
            }
        }
        return ans; 
    }
};