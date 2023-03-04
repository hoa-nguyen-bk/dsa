// start of iterator implementation
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
  /*
      Constructor of iterator
      * Set pList to pList
      * begin = true:
      * * Set current (index = 0) to pList's head if pList is not NULL
      * * Otherwise set to NULL (index = -1)
      * begin = false:
      * * Always set current to NULL
      * * Set index to pList's size if pList is not NULL, otherwise 0
  */
  this->pList->toString();
  this->pList = pList;
  this->pList->toString();

  if (begin)
  {
    if (pList != nullptr)
    {
      this->current = pList->head;
      this->index = 0;
    }
    else
    {
      this->current = nullptr;
      this->index = -1;
    }
  }
  else
  {
    this->current = nullptr;
    if (this->pList != nullptr)
    {

      this->index = pList->size();
    }
    else
    {
      this->index = 0;
    }
  }
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
  /*
      Assignment operator
      * Set this current, index, pList to iterator corresponding elements.
  */
  this->current = iterator.current;
  this->index = iterator.index;
  this->pList = iterator.pList;
  // theo cái ở trên thì ở dưới phải trả về Iterator
  return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
  /*
      Remove a node which is pointed by current
      * After remove current points to the previous node of this position (or node with index - 1)
      * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
      * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
  */
  typename SLinkedList<T>::Node *deleteNode = new typename SLinkedList<T>::Node();
  if (this->current == nullptr)
  {
    throw std::out_of_range("Segmentation fault!");
  }
  else
  {
    // if remove at front current points to previous "node" of head (current = NULL, index = -1)
    if (this->current == this->pList->head)
    {
      this->pList->head = this->current->next;
      deleteNode = this->current;
      this->current = nullptr;
      this->index = -1;
      delete deleteNode;
    }
    // After remove current points to the previous node of this position (or node with index - 1)
    else
    {

      typename SLinkedList<T>::Node *temp = this->current;

      while (temp->next != this->current)
      {
        temp = temp->next;
      }
      temp->next = this->current->next;
      deleteNode = this->current;
      this->current = temp;
      this->index--;
      delete deleteNode;
    }
  }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
  /*
      Set the new value for current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (this->current == nullptr)
  {
    throw std::out_of_range("Segmentation fault!");
  }
  else
  {
    this->current->data = e;
  }
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
  /*
      Get data stored in current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (this->current == nullptr)
  {
    return throw std::out_of_range("Segmentation fault!");
  }
  else
  {
    return this->current->data;
  }
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
  /*
      Operator not equals
      * Returns false if two iterators points the same node and index
  */
  if (this->current == iterator.current && this->index == iterator.index)
    return false;
  return true;