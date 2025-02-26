class MyStack {
public:
    queue<int> queue;

    MyStack() {
        
    }
    
    void push(int x) {
        queue.push(x);
        int n = queue.size(); 

        for(int i = 0; i < n-1; i++){
            queue.push(queue.front());
            queue.pop();
        }
    }
    
    int pop() {
        int result = queue.front();
        queue.pop();

        return result;
    }
    
    int top() {
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
};