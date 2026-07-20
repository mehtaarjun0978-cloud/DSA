class MyStack {
private: 
    std::queue<int> q;
public:
    MyStack() {
        //nothing to do 
    }
    
    void push(int x) {
        //push the new element at the end of the queue
        q.push(x);

        // move all the element ahead of x => to behind of x 
        int n = q.size();
        for(int i = 0 ; i < n-1 ; i++){
            q.push(q.front());                 // add the front element to the back 
            q.pop();                            // remove the front element 
        }
    }
    
    int pop() {
        // get the stack pop element directly from front 
        if(q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */