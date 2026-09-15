class MinStack {
public:
    stack<int> stk; // to store all values
    stack<int> minstk; // to store minimum values only
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        // if minstk is empty or curr val <= curr mini
        if(minstk.empty() || val <= minstk.top()){
            minstk.push(val);
        }
    }
    
    void pop() {
        // pop from minstk too if curr top is equal to curr mini
        if(stk.top() == minstk.top()){
            minstk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();    
    }
    
    int getMin() {
        return minstk.top();  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */