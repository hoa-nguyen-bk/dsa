vector<int> nextGreater(vector<int>& arr){
    stack<int> st;
    int arrSz = arr.size();
    for (int i = 0 ; i < arrSz ; i ++ ) {
        if (st.empty()) 
        {
            st.push(i);
            continue;
        }
        while (!st.empty()  && arr[st.top()] < arr[i]) {
            arr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        arr[st.top()] = -1;
        st.pop();
    }
    return arr;
}