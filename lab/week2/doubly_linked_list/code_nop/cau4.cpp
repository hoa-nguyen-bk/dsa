template <class T>
T DLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= count) throw std::out_of_range("Index is out of range");
    Node* current = head;
    for (int i = 0; i < index; i++) current = current->next;
    T value = current->data;
    if (current->previous) current->previous->next = current->next;
    else head = current->next;
    if (current->next) current->next->previous = current->previous;
    else tail = current->previous;
    delete current;
    count--;
    return value;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item) {
    Node* current = head;
    while (current && current->data != item) current = current->next;
    if (!current) return false;
    if (current->previous) current->previous->next = current->next;
    else head = current->next;
    if (current->next) current->next->previous = current->previous;
    else tail = current->previous;
    delete current;
    count--;
    return true;
}

template<class T>
void DLinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}