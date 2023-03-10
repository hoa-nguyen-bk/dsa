template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};


template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, NULL);
    if(count == 0) {
        head = tail = newNode;
        count++;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node* newNode = new Node(e, NULL);
    //TH1: list rong && TH3: add vao cuoi
    if(count == 0 || index >= count) {
        add(e);
        return;
    }
    //TH2: add vao dau
    if(index == 0 ) {
        newNode->next = head;
        head = newNode;
        count++;
        return;
    }
    //TH4: add o giua
    Node *p = head;
    while(index > 1 && p != NULL){
        p = p->next;
        index--;
    }
    newNode->next = p->next;
    p->next = newNode;
    count++;

}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    Node* p = head;
    int count = 0;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    return count;
}
