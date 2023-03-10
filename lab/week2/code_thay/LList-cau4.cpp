

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
  this->pList = pList;
  if (begin)
  {
    if (this->pList)
    {
      current = pList->head;
      index = 0;
    }
    else
    {
      current = NULL;
      index = -1;
    }
  }
  else
  {
    current = NULL;
    if (this->pList)
    {
      index = pList->size();
    }
    else
    {
      index = 0;
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
  current = iterator.current;
  index = iterator.index;
  pList = iterator.pList;
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
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  else if (index != 0)
  {
    current = pList->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    Node *del = current->next;
    current->next = current->next->next;
    delete del;
    index--;
    pList->count--;
  }
  else
  {
    Node *temp = pList->head;
    pList->head = pList->head->next;
    delete temp;
    index = -1;
    current = NULL;
    pList->count--;
  }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
  /*
      Set the new value for current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  current->data = e;
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
  /*
      Get data stored in current node
      * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
  /*
      Operator not equals
      * Returns false if two iterators points the same node and index
  */
   if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
      if (this->current == iterator.current && this->index == iterator.index)
    return false;
  return true;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
  /*
      Prefix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  if (current == NULL)
    throw std::out_of_range("Segmentation fault!");
  current = current->next;
  index++;
  return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
  /*
      Postfix ++ overload
      * Set current to the next node
      * If iterator corresponds to the previous "node" of head, set it to head
      * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
  */
  Iterator *temp = this;
  ++(*this);
  return *temp;
}