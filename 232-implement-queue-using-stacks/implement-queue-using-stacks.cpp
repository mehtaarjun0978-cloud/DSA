class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;

    // this is the helper fuction to move  the content of s1 -> s2 // for queue implementation 
    void moveS1toS2(){
        if(s2.empty()){ //only runs when s2 is empty -> if not htne it will cause problem 
            while(!s1.empty()){
                // runs till s1 is not empty 
                s2.push(s1.top());         // push element from s1 to s2 
                s1.pop();                  // delete element from s1 
            }
        }
    }
public:
    MyQueue() {} //only for initialisation 

    void push(int x) {
        // nothing input array ->  s1 hai usme push krdo directly 
        s1.push(x);
    }

    int pop() {
        // move elements from s1 to s2 
        moveS1toS2() ;

        //if queue is still empty (s2) then return -1 
        if(s2.empty()) return -1 ;

        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        moveS1toS2() ;

        // if( s2 is empty return -1)
        if(s2.empty()) return -1;

        int val = s2.top();
        return val;
    }

    bool empty() {
        if(s1.empty() && s2.empty()) return 1;
        return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 *; int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty()
 */