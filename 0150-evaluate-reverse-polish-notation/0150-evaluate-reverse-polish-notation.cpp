class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;

        for(const string& ch : tokens){
            // Case 1: If token is an operator
            if(ch == "+"){
                int a = Stack.top(); Stack.pop();
                int b = Stack.top(); Stack.pop();
                Stack.push(b + a);
            }
            else if(ch == "-"){
                int a = Stack.top(); Stack.pop();
                int b = Stack.top(); Stack.pop();
                Stack.push(b - a);
            }
            else if(ch == "*"){
                int a = Stack.top(); Stack.pop();
                int b = Stack.top(); Stack.pop();
                Stack.push(b * a);
            }
            else if(ch == "/"){
                int a = Stack.top(); Stack.pop();
                int b = Stack.top(); Stack.pop();
                Stack.push(b / a);
            }
            // Case - 2: If token is a operand -> Integer
            else{
                Stack.push(stoi(ch));
            }
        }
        return Stack.top(); // return final output which is TOS
    }
};