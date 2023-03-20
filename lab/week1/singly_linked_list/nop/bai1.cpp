template <class T>
void SLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list */
  Node *newElement = new Node(e, nullptr);
  if (this->head == nullptr)
  {
    this->head = newElement;
    this->tail = newElement;
  }
  else
  {
    this->tail->next = newElement;
    this->tail = newElement;
  }
  this->count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index */
  if (index < 0 || index > this->count)
  {
    cout << "Index out of range" << endl;
    return;
  }
  Node *newElement = new Node(e, nullptr);
  if (index == 0)
  {
    if (this->head == nullptr) {
        this->head = newElement;
        this->tail = newElement;
    } else {
        newElement->next = this->head;
        this->head = newElement;
    }
  }
  else
  {
    Node *current = this->head;
    for (int i = 0; i < index - 1; i++)
    {
      current = current->next;
    }
    newElement->next = current->next;
    current->next = newElement;
    if (index == this->count) {
        this->tail = newElement;
    }
  }
  this->count++;
}

template <class T>
int SLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}