// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int hR(Node * root) {
    if (root == NULL) {
        return 0;
    }
    return max(hR(root->pLeft), hR(root->pRight)) + 1;
}
int getHeight() {
    // TODO: return height of the binary tree.
    return hR(this->root);
}

string preOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << root->value << " ";
    ss << preOrder(root->pLeft);
    ss << preOrder(root->pRight);
    return ss.str();
}

string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    return preOrder(this->root);
}

string inOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << inOrder(root->pLeft);
    ss << root->value << " ";
    ss << inOrder(root->pRight);
    return ss.str();
}

string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    return inOrder(this->root);
}

string postOrder(Node * root) {
    // TODO: return the sequence of values of nodes in pre-order.
    if (root == NULL) {
        return "";
    }

    stringstream ss;
    ss << postOrder(root->pLeft);
    ss << postOrder(root->pRight);
    ss << root->value << " ";
    return ss.str();
}

string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    return postOrder(this->root);
}

// STUDENT ANSWER END

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int size = end - start;
    int * arr = start;

    for (int sorting_idx = 0; sorting_idx < size - 1; ++sorting_idx) {
        int min_idx = sorting_idx;
        for (int i = min_idx + 1; i < size; ++i) {
            if (arr[min_idx] > arr[i]) {
                min_idx = i;
            }
        }
        swap(arr[sorting_idx], arr[min_idx]);
        printArray(start, end);
    }
}

void bfs(vector<vector<int>> graph, int start) {
    queue<int> q;
    vector<bool> visit(graph.size(), false);

    q.push(start); visit[start] = true;

    while (!q.empty()) {
        int curV = q.front();
        q.pop();
        cout << curV << " ";

        for (int adjV: graph[curV]) {
            if (! visit[adjV]) {
                q.push(adjV); visit[adjV] = true;
            }
        }
    }
}

bool isValidParentheses (string str){
    /*TODO*/
    stack<char> s;

    for (char c: str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            if (s.empty()) {
                return false;
            }
            if (c == ')' && s.top() == '(') {
                s.pop();
            }
            else if (c == ']' && s.top() == '[') {
                s.pop();
            }
            else if (c == '}' && s.top() == '{') {
                s.pop();
            }
            else {
                return false;
            }
        }
    }

    return s.empty();
}


// Recursion
// Question 1
void printArray(int n)
{
    /*  
     * STUDENT ANSWER
     */
    if (n == 0) {
        cout << 0;
    }
    else {
        printArray(n-1);
        cout << ", " << n;
    }
}

// Question 4
bool isPalindrome(string str) 
{

    int len = str.length();
    if (len <= 1) {
        return true;
    }
    else {
        if (str[0] == ' ') return isPalindrome(str.substr(1, len-1));
        else if (str[len-1] == ' ') return isPalindrome(str.substr(0, len-1));
        else return (str[0] == str[len-1]
            && isPalindrome(str.substr(1, len-2)));
    }
}

// Singly Linked List
template <typename T>
class SLinkedList {
private:
    Node * head, tail;
    int count;

public:
    class Node {
    private:
        T data;
        Node * next;
    public:
        Node(const T & data, Node * next=NULL) {
            this->data = data;
            this->next = next;
        }
    };
public:
    int size() const {
        return this->count;
    }
    void add(const T & data) {
        Node * pN = new Node(data);
        if (count == 0) {
            head = tail = pN;
            ++count;
        }
        else {
            tail->next = pN;
            tail = pN;
            ++count;
        }
    }

    void add(int index, const T & data);
};