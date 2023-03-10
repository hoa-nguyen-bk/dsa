
// template <class T>
// void DLinkedList<T>::add(int index, const T &e)
// {
//   /* Insert an element into the list at given index. */
//   Node *newNode = new Node(e);
//   // lần đầu khi mảng chưa có gì thì zô đây
//   if (this->count == 0)
//   {
//     this->head = newNode;
//     this->tail = newNode;
//   }
//   // lần 2 sẽ là zô đít
//   else if (this->count == index)
//   {
//     this->tail->next = newNode;
//     newNode->previous = this->tail;
//   }
//   // lần 3 zô khi mảng đã có hàng họ đủ rồi
//   else
//   {
//     int i = 0;

//     Node *tmp = this->head;
//     while (tmp != nullptr)
//     {

//       if (i == index)
//       {
//         newNode->next = tmp->next;
//         tmp->next = newNode;
//         newNode->previous = tmp;
//         if (newNode->next != nullptr)
//         {
//           newNode->next->previous = newNode;
//         }
//         break;
//       }
//       i++;
//       tmp = tmp->next;
//     }
//   }
//   this->count++;
// }