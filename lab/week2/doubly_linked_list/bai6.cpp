#include <iostream>
#include <unordered_map>

using namespace std;
// Example 1:
// Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
// Output: 3 6 5 4 7

// Example 2:
// Input: list = {8, 9, 10}, a = 1, b = 3
// Output: 10 9 8
struct ListNode
{
  int val;
  ListNode *left;
  ListNode *right;
  ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};
/*______________________________
________ Start Bài nộp _______
______________________________*/
ListNode* reverse(ListNode* head, int a, int b) {
    if (!head) return nullptr;
    if (a == b) return head;

     ListNode* prev_a = nullptr;
    ListNode* node_a = head;
    for (int i = 1; i < a; i++) {
        prev_a = node_a;
        node_a = node_a->right;
    }
    ListNode* prev = prev_a;
    ListNode* curr = node_a;
    ListNode* next = nullptr;
    for (int i = a; i <= b; i++) {
        next = curr->right;
        curr->right = prev;
        curr->left = next;
        prev = curr;
        curr = next;
    }
    if (prev_a != nullptr) {
        prev_a->right = prev;
    } else {
        head = prev;
    }
    node_a->right = curr;
    if (curr != nullptr) {
        curr->left = node_a;
    }
    return head;
}

/*______________________________
________ End Bài nộp _______
______________________________*/
// chat gpt func
ListNode *init(int *arr, int size, unordered_map<ListNode *, int> &nodeValue)
{
  if (size == 0)
  {
    return nullptr;
  }

  ListNode *head = new ListNode(arr[0]);
  nodeValue[head] = arr[0];
  ListNode *prev = head;
  for (int i = 1; i < size; i++)
  {
    ListNode *node = new ListNode(arr[i], prev, nullptr);
    nodeValue[node] = arr[i];
    prev->right = node;
    prev = node;
  }

  return head;
}

void freeMem(ListNode *head)
{
  ListNode *curr = head;
  while (curr)
  {
    ListNode *temp = curr;
    curr = curr->right;
    delete temp;
  }
}

void printList(ListNode *head, unordered_map<ListNode *, int> &nodeValue)
{
  if (head == nullptr)
  {
    throw "List is empty!";
  }

  ListNode *current = head;
  while (current != nullptr)
  {
    cout << nodeValue[current] << " <-> ";
    current = current->right;
  }
  cout << "NULL" << endl;
}
// end chatgpt func
int main()
{
  int size = 3;
  int *list = new int[size];
  for (int i = 0; i < size; i++)
  {
    list[i] = i + 8;
  }
  // input
  // 3
  // 8 9 10
  // 1 3
  int a = 1, b = 3;
  unordered_map<ListNode *, int> nodeValue;
  ListNode *head = init(list, size, nodeValue);
  ListNode *reversed = reverse(head, a, b);
  try
  {
    printList(reversed, nodeValue);
  }
  catch (char const *err)
  {
    cout << err << '\n';
  }
  // output
  // 8 9 10
  freeMem(head);
  delete[] list;
  return 0;
}
