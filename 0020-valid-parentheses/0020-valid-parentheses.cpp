class Solution {
public:
    bool isValid(string s) {
        stack<int>stk;
        for(char curr : s){
            if(!stk.empty()){
                int tos = stk.top();
                if(checkValid(tos , curr)){
                    stk.pop();
                    continue;
                }
            }
            stk.push(curr);
        }
        return stk.empty();
        
    }
    bool checkValid(char tos , char curr){
        return (tos == '(' && curr == ')') ||
        (tos == '{' && curr == '}') ||
        (tos == '[' && curr == ']');
    }
};