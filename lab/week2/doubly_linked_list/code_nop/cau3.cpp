template<class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
    this->pList = pList;
    if (begin) {
        this->current = pList->head;
        this->index = 0;
    }
    else {
        this->current = NULL;
        this->index = pList->count;
    }
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template<class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    this->current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
 if (current == nullptr) {
        return;
    }
    
    Node* temp = current;
    current = current->previous;
    
    if (current == nullptr) {
        pList->head = temp->next;
    } else {
        current->next = temp->next;
    }
    
    if (temp->next != nullptr) {
        temp->next->previous = current;
    } else {
        pList->tail = current;
    }
    
    delete temp;
    pList->count--;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    return this->current != iterator.current;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (this->current == NULL) {
        this->current = this->pList->head;
        this->index = 0;
    }
    else {
        this->current = this->current->next;
        this->index++;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator iterator = *this;
    ++(*this);
    return iterator;
}
