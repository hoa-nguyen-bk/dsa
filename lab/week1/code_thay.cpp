
#include <iostream>
using namespace std;
// Recursion
// Question 1
void printArray(int n)
{
  /*
   * STUDENT ANSWER
   */
  if (n == 0)
  {
    cout << 0;
  }
  else
  {
    printArray(n - 1);
    cout << ", " << n;
  }
}

// Question 4
bool isPalindrome(string str)
{
  if (str == "")
    return true;
  if (str.length() == 1)
    return true;
  else
  {
    if (str[0] == ' ')
      return isPalindrome(str.substr(1, str.length() - 1));
    if (str[str.length() - 1] == ' ')
      return isPalindrome(str.substr(0, str.length() - 1));
    if (str[0] != str[str.length() - 1])
      return false;
    else
    {
      return isPalindrome(str.substr(1, str.length() - 2));
    }
  }
}

// Class SinglyLinkedList

template <typename T>
class SLinkedList
{
public:
  class Node
  {
  private:
    T data;
    Node *next;
    friend class SLinkedList<T>;

  public:
    Node(const T &data, Node *next = NULL)
    {
      this->data = data;
      this->next = next;
    }
  };

private:
  Node *head, tail;
  int count;

public:
  int size() const
  {
    return this->count;
  }
  void add(const T &data)
  {
    Node *pNew = new Node(data);
    if (count == 0)
    {
      head = tail = pNew;
      ++count;
    }
    else
    {
      tail->next = pNew;
      ++count;
      tail = tail->next;
    }
  }
  void add(int index, const T &data);
};