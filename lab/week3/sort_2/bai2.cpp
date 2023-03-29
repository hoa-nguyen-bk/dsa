#include <unordered_map>
#include <iostream>
using namespace std;
//copy chatgpt
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    if (a->val <= b->val) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    tail = head;
    
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    
    if (a) tail->next = a;
    else tail->next = b;
    
    return head;
}

ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* mid = slow->next;
    slow->next = nullptr;
    
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(mid);
    
    return mergeLists(left, right);
}

void freeMem(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* init(int arr[], int size, unordered_map<ListNode*, int>& nodeAddr) {
    if (size == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    nodeAddr[head] = arr[0];
    
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
        nodeAddr[temp] = arr[i];
    }
    
    return head;
}

void printList(ListNode* head, unordered_map<ListNode*, int>& nodeAddr) {
    int count = 0;
    while (head) {
        cout << head->val;
        count++;
        head = head->next;
        if (head) cout << " ";
        if (count > 1000) throw "ERROR: Too many nodes!";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* a = init(arr1, sizeof(arr1) / 4, nodeAddr);
    ListNode* b = init(arr2, sizeof(arr2) / 4, nodeAddr);
    ListNode* merged = mergeLists(a, b);
    try {
        printList(merged, nodeAddr);
    }
    catch(char const* err) {
        cout << err << '\n';
    }
    freeMem(merged);
    
    int size;
    cin >> size;
    int* array = new int[size];
    for(int i = 
