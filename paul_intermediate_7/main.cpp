@@ -6,10 +6,224 @@
//  Copyright © 2017 Tse Jen Lu. All rights reserved.
//


/*
 
 Linked List In-Place Reverse Challenge
 
 This challenge, similar to the last linked list challenge, involves reversing a singly linked list--but this time, you must not out the list but actually reverse the entire list in place. By in-place, I mean that no memory can be allocated. The resulting code should be function that takes the head of a list and returns a the new head of the reversed list.
 
 */

#include <iostream>
using namespace std;

class LinkedList;

class ListNode
{
public:
    int data;
    ListNode *next;
    // public:
    ListNode(): data(0), next(0){};
    ListNode(int a):data(a),next(0){};
    
    friend class Linklist;
};

class LinkedList
{
public:
    ListNode *first;
public:
    LinkedList():first(0){};
    void Reverse();
    void Push_back(int x);
    void PrintList();
    
};

void LinkedList::Push_back(int x){
    
    ListNode *newNode = new ListNode(x);   // 配置新的記憶體
    
    if (first == 0) {                      // 若list沒有node, 令newNode為first
        first = newNode;
        return;
    }
    
    ListNode *current = first;
    while (current->next != 0) {           
        current = current->next;
    }
    current->next = newNode;               
}

void LinkedList::PrintList(){
    
    if (first == 0) {                      
        cout << "List is empty.\n";
        return;
    }
    
    ListNode *current = first;             
    while (current != 0) {                 
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void LinkedList::Reverse() {
    if (first == 0 || first->next == 0) {
        return ;
    }
    
    ListNode *previous = nullptr;
    ListNode *current = first;
    ListNode *preceding = first->next;
    
    while(preceding != 0) {
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }
    
    current->next = previous;
    first = current;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
int main() {
    LinkedList list;
    
    list.Push_back(1);
    list.Push_back(2);
    list.Push_back(3);
    list.Push_back(4);
    
    list.PrintList();
    list.Reverse();
    list.PrintList();
    
    return 0;
}
