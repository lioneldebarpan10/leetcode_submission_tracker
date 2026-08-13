class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = "";
        int operations = 0;

        while(str.length() < b.length()){
            str += a;
            operations++;

            if(str.find(b) != string::npos){
                return operations;
            }
        }
        str += a;
        operations++;
        if(str.find(b) != string::npos){
            return operations;
        }
        return -1;
        
    }
};