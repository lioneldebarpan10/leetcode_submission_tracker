class Solution {
public:
    string decodeString(string s) {
        stack<int>numStk;
        stack<string>strStk;

        int num = 0;
        string curr = "";

        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            else if(ch == '['){
                numStk.push(num);
                strStk.push(curr);

                num = 0;
                curr = "";
            }
            else if(ch == ']'){
                int repeat = numStk.top();
                numStk.pop();

                string prev = strStk.top();
                strStk.pop();

                while(repeat--){
                    prev += curr;
                }
                curr = prev;
            }
            else{
                curr += ch;
            }
        }
        return curr;
        
    }
};