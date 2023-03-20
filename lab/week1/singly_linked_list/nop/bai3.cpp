template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
      if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }

    Node* prev = nullptr;
    Node* curr = head;

    for (int i = 0; i < index; ++i) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    if (curr->next == nullptr) {
        tail = prev;
    }

    T data = curr->data;
    delete curr;
    count--;

    return data;
}


template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->data == item) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (tail == curr) {
                tail = prev;
            }
            delete curr;
            count--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
     Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

