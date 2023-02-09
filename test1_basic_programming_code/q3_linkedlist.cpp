// ref https://www.geeksforgeeks.org/create-linked-list-from-a-given-array/
#include <iostream>
using namespace std;

// biểu diễn 1 node
struct Node
{
  int data;
  Node *next;
};

// hàm thêm node
void insert(Node **root, int item)
{
  Node *temp = new Node;
  // This statement creates a new pointer to a Node object and assigns it to the temp variable.The Node object is allocated on the heap and the pointer to it is stored in temp.Node *ptr;
  Node *ptr;
  temp->data = item;
  temp->next = NULL;

  if (*root == NULL)
  {
    *root = temp;
  }
  else
  {
    ptr = *root;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

void display(Node *root)
{
  while (root != NULL)
  {
    cout << root->data << " -> ";
    root = root->next;
  }
}

Node *arrayToList(int arr[], int n)
{
  Node *root = NULL;
  for (int i = 0; i < n; i++)
  {
    insert(&root, arr[i]);
  }
  return root;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *root = arrayToList(arr, n);
  display(root);
  return 0;
}
