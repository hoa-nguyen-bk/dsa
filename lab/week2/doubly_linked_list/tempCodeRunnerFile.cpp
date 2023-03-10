template <class T>
T DLinkedList<T>::removeAt(int index)
{
  /* Remove element at index and return removed value */
  if (this->count == 0 || index < 0 || index >= count)
  {
    throw std::out_of_range("Index out of range");
  }

  Node *previousNode = nullptr;
  Node *currentNode = this->head;

  for (int i = 0; i < index; ++i)
  {
    previousNode = currentNode;
    currentNode = currentNode->next;
    currentNode->previous = previousNode;
  }
  // if index = 0, chỉ có 1 thằng là tại vị trí đầu
  if (previousNode == nullptr)
  {
    // cho thằng head là node tiếp theo
    this->head = currentNode->next;
    // vị trí đầu thì dĩ nhiên next prev null rồi
    currentNode->next->previous = nullptr;
  }
  // còn nếu là vị trí còn lại
  else
  {
    // cho node trước bằng với node sau của sau luôn, dán liền 2 nốt cách 1 cục current head lại

    Node *nextNode = currentNode->next;
    if (nextNode == nullptr)
    {
      previousNode->next = nullptr;
      this->tail = previousNode;
    }
    else
    {
      previousNode->next = nextNode;
      // còn node sau nối bằng node trước, chỗ này tách node cho dễ hiểu thôi
      nextNode->previous = previousNode;
    }
  }

  T data = currentNode->data;
  delete currentNode;
  this->count--;

  return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
  /* Remove the first apperance of item in list and return true, otherwise return false */
  if (this->count == 0)
  {
    throw std::out_of_range("Index out of range");
  }
  Node *previousNode = NULL;
  Node *currentNode = this->head;
  while (currentNode != NULL)
  {
    // nếu tìm được node để xóa
    if (currentNode->data == item)
    {
      // TH1: nếu đó vẫn là node đầu tiên
      if (previousNode == nullptr)
      {
        this->head = currentNode->next;
        // vị trí đầu thì dĩ nhiên next prev null rồi
        currentNode->next->previous = nullptr;
      }
      else
      {
        Node *nextNode = currentNode->next;
        // TH3: và cuối cùng là ở cuối
        if (nextNode == nullptr)
        {
          previousNode->next = nullptr;
          this->tail = previousNode;
        }
        // TH2: nếu đó là vị trí ở giữa
        else
        {
          previousNode->next = nextNode;
          // còn node sau nối bằng node trước, chỗ này tách node cho dễ hiểu thôi
          nextNode->previous = previousNode;
        }
      }

      delete currentNode;
      count--;
      return true;
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
    currentNode->previous = previousNode;
  }
  return false;
}

template <class T>
void DLinkedList<T>::clear()
{
  /* Remove all elements in list */
  Node *currentNode = this->head;
  while (currentNode != nullptr)
  {
    Node *temp = currentNode;
    currentNode = currentNode->next;
    delete temp;
  }
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}