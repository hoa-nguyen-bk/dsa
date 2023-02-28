#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class SLL
{
private:
    Node<T>* head;
public:
    SLL()
    {
        head = nullptr;
    }
    void insertT(T *arrD, int size)
    {
        for(int i = 0; i < size; i++)
        {
            Node<T>* node = new Node<T>(arrD[i]);
            if(head == nullptr)
            {
                head = node;
            }
            else
            {
                Node<T>* tmp = head;
                while(tmp->next != nullptr)
                {
                    tmp = tmp->next;
                }
                tmp->next = node;
            }
        }
    }
    //insertH, insertM, insertT;
    void del(T data);
    void print()
    {
        Node<T>* tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{
    int arr[5] = {1,2,3,4,5};
    SLL<int> sll;
    sll.insertT(arr,5);
    sll.print();
    return 0;
}