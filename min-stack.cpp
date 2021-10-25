//https://leetcode.com/problems/min-stack/
class MinStack {
public:
    /** initialize your data structure here. */
    /*   
        -3 , -3
         0 , -2
        -2 , -2
    
    
    
    */
     MinStack() {
        
    }
   
    
    void push(int x) {
        if(!stack.empty()){
            stack.push({x,min(x,stack.top().second)});
        }
        else
            stack.push({x,x});
    }
    
    void pop() {
        if(!stack.empty())
            stack.pop();
    }
    
    int top() {
        if(!stack.empty()){
            auto t = stack.top();
            return t.first;
        }
        else
            return 0;
        
    }
    
    int getMin() {
        if(!stack.empty()){
            auto t = stack.top();
            return t.second;
        }
        return 0;
    }
    
private : 
    stack<pair<int,int>> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
