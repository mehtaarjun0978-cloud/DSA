// class MinStack {
// private: 
//         long long min ;
//         std::stack<int> s;  
// public:
//     MinStack() {
//         // ust for the object creation 
//     }
    
//     void push(int value) {
//         long long val = value; // Cast to long long to prevent overflow
        
//         if (s.empty()) {
//             s.push(val);
//             min = val;
//         } 
//         else if (val < min) { // Only encode when the NEW value is the smallest
//             s.push(2 * val - min);
//             min = val; // Update min to the new smallest value
//         } 
//         else {
//             s.push(val); // Otherwise, just push the normal value
//         }      
//     }
    
//     void pop() {
//         if( s.empty() ) return ;

//         long long top_element = s.top();
//         s.pop();

//         if(top_element < min){
//             // roll back min 
//             min = 2*min - top_element;
//         }       
//     }
    
//     int top() {
//         if( s.empty() ) return -1;

//         long long top_element = s.top();

//         // If the top element is less than min, it is an encoded value.
//         // The actual unencoded value is stored in our 'min' variable.
//         if(top_element < min ) return min; 

//         return s.top();
//     }
    
//     int getMin() {
//         return min ;
//     }
// };

#include <stack>

class MinStack {
private: 
    long long min;
    std::stack<long long> s;  
    
public:
    MinStack() {
        // Constructor
    }
    
    void push(int value) {
        long long val = value; // Cast to long long to prevent overflow
        
        if (s.empty()) {
            s.push(val);
            min = val;
        } 
        else if (val < min) { // Only encode when the NEW value is the smallest
            s.push(2 * val - min);
            min = val; // Update min to the new smallest value
        } 
        else {
            s.push(val); // Otherwise, just push the normal value
        }        
    }
    
    void pop() {
        if (s.empty()) return;
        
        long long topElement = s.top();
        s.pop();
        
        // If the element we just popped is less than our current min,
        // it means this element was an encoded value, and removing it 
        // means we must rollback our min to the previous minimum.
        if (topElement < min) {
            min = 2 * min - topElement; 
        }
    }
    
    int top() {
        if (s.empty()) return -1;
        
        long long topElement = s.top();
        
        // If the top element is less than min, it is an encoded value.
        // The actual unencoded value is stored in our 'min' variable.
        if (topElement < min) {
            return min;
        } else {
            return topElement;
        }
    }
    
    int getMin() {
        // Simply return the tracked minimum
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */