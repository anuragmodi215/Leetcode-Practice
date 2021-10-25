class MinStack {
public:
    int stack[10000];
    int min[10000];
    int topptr;
    int minptr;
    MinStack() {
        topptr=-1;
        minptr=-1;
    }
    
    void push(int val) {
        if(topptr>=10000) return;
        stack[++topptr]=val;
        if(minptr>=0){
            if(min[minptr]<val){
                min[minptr+1]=min[minptr];
                minptr++;
            }
            else{
                min[++minptr]=val;
            }
        }
        else min[++minptr]=val;
    }
    
    void pop() {
        if(topptr<0) return;
        topptr--;
        minptr--;
    }
    
    int top() {
        return stack[topptr];
    }
    
    int getMin() {
        return min[minptr];
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