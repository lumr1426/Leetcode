class MyQueue {
public:
    
    stack<int> instack, outstack;
    
    MyQueue(){};
    
    /** Push element x to the back of queue. */
    void push(int x) {
        instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int insize=instack.size();
        for(int i=0;i<insize;i++)
        {
            outstack.push(instack.top());
            instack.pop();
        }
        
        int peek=outstack.top();
        outstack.pop();
        
        for(int i=0;i<insize-1;i++)
        {
            instack.push(outstack.top());
            outstack.pop();
        }
        return peek;
    }
    
    /** Get the front element. */
    int peek() {
        int insize=instack.size();
        for(int i=0;i<insize;i++)
        {
            outstack.push(instack.top());
             instack.pop();
        }
        
        int peek=outstack.top();
        
        for(int i=0;i<insize;i++)
        {
            instack.push(outstack.top());
            outstack.pop();
        }
        return peek;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        cout<<instack.empty();
        if(instack.size()==0)
            return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
