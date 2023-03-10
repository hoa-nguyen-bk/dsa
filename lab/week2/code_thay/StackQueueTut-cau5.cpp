// <- [1 2 3 <-
// [3 2
class QueueS {
private:
    stack<int> st;

public:
    void enqueue(int value) {
        st.push(value);
    }
    int dequeue() {
        stack<int> temp;
        int size = st.size();
        for(int i = 0; i < size - 1; i++){
            temp.push(st.top());
            st.pop();      
        }
        int res = st.top();
        st.pop();
        for(int i = 0; i < size - 1; i++){
            st.push(temp.top());
            temp.pop();
        }
        return res;   
    }
    int front() {
        stack<int> temp;
        int size = st.size();
        for(int i = 0; i < size - 1; i++){
            temp.push(st.top());
            st.pop();      
        }
        int res = st.top();
        for(int i = 0; i < size - 1; i++){
            st.push(temp.top());
            temp.pop();
        }
        return res;
    }
    int rear() {
        return st.top();
    }
    
    string toString() {
        stringstream ss;
        ss << "FRONT|";

        stack<int> temp;
        int size = st.size();
        for(int i = 0; i < size; i++){
            temp.push(st.top());
            st.pop();      
        }
        for(int i = 0; i < size; i++){
            st.push(temp.top());
            ss << " " << temp.top();
            temp.pop();
        }
        ss << "|REAR";

        return ss.str();
    }
};