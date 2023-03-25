template <class T>
void DLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list. */
  Node *newNode = new Node(e);
  if (this->count != 0)
  {
    this->tail->next = newNode;
    newNode->previous = this->tail;
  }
  else
  {
    this->head = newNode;
  }
  // cout<<"this->tail = "<<this->tail<<"; this->he = " << this->head << " ->" <<this->count<<endl;
  this->tail = newNode;
  this->count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index. */
  if (index > this->count)
  {
    return;
  }

  Node *newNode = new Node(e);
  // if there were nothing
  if (this->count == 0)
  {
    this->head = newNode;
    this->tail = newNode;
    this->count++;
    return;
  }

  // case 1: insert at index = 0, beginner of the list
  if (index == 0)
  {
    newNode->next = this->head;
    if (this->head != nullptr)
    {
      this->head->previous = newNode;
    }
    this->head = newNode;
    this->count++;
    return;
  }
   // case 2: insert at the end of the list
  if (index == this->count)
  {
    if (this->tail != nullptr)
    {
      this->tail->next = newNode;
      newNode->previous = tail;
    }
    this->tail = newNode;
    this->count++;
    return;
  }


  // case 3: insert in the middle of the list
  Node *currentNode = this->head;

  // với điểm dừng index - 1 thì cục current node sẽ
  for (int i = 0; i < index - 1; i++)
  {
    currentNode = currentNode->next;
  }
  newNode->next = currentNode->next;
  currentNode->next = newNode;
  newNode->previous = currentNode;
  if (newNode->next != nullptr)
  {
    newNode->next->previous = newNode;
  }
  this->count++;
}

template <class T>
int DLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}