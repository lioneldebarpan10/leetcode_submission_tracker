class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = p.length();
        int n2 = s.length();

        vector<int>ans;
        if(n1 > n2) return ans;

        vector<int>freqP(26 , 0);
        vector<int>freqS(26 , 0);

        for(int i = 0 ; i < n1 ; i++){
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }
        if(freqS == freqP){
            ans.push_back(0);
        }
        for(int i = n1 ; i < n2 ; i++){
            freqS[s[i] - 'a']++;
            freqS[s[i - n1] - 'a']--;

            if(freqS == freqP){
                ans.push_back(i - n1 + 1);
            }
        }
        return ans;
        
    }
};