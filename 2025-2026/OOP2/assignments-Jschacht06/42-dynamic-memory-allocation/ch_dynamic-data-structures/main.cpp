#include <iostream>
using namespace std;

struct node {
    char data;
    struct node* nextNode;
};

void appendNode(node*& head, char data);
void printNodes(node* head);
void removeNode(node*& head, char value);
void insertNode(node*& head, char value, int index);

int main() {
    struct node* headPtr = nullptr;

    // 1. Build initial list
    appendNode(headPtr, 'A');
    appendNode(headPtr, 'B');
    appendNode(headPtr, 'C');
    printNodes(headPtr);

    // 2. Add more nodes
    appendNode(headPtr, 'D');
    appendNode(headPtr, 'E');
    appendNode(headPtr, 'F');
    appendNode(headPtr, 'B'); 
    printNodes(headPtr);

    // 3. Insert nodes
    insertNode(headPtr, 'Z', 0); 
    insertNode(headPtr, 'X', 3); 
    printNodes(headPtr);

    // 4. Remove nodes
    removeNode(headPtr, 'B');
    printNodes(headPtr);

    // Clean up memory
    node* current = headPtr;
    while (current != nullptr) {
        node* temp = current;
        current = current->nextNode;
        delete temp;
    }

    return 0;
}

void appendNode(node*& head, char data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->nextNode = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->nextNode != nullptr) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}

void printNodes(node* head) {
    cout << "headPtr --> ";
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " --> ";
        temp = temp->nextNode;
    }
    cout << "NULL" << endl;
}

void removeNode(node*& head, char value) {
    // Remove from start
    while (head != nullptr && head->data == value) {
        node* temp = head;
        head = head->nextNode;
        delete temp;
    }

    if (head == nullptr) return;

    // Remove from rest
    node* current = head;
    while (current->nextNode != nullptr) {
        if (current->nextNode->data == value) {
            node* temp = current->nextNode;
            current->nextNode = temp->nextNode;
            delete temp;
        } else {
            current = current->nextNode;
        }
    }
}

void insertNode(node*& head, char value, int index) {
    node* newNode = new node;
    newNode->data = value;
    newNode->nextNode = nullptr;

    if (index == 0) {
        newNode->nextNode = head;
        head = newNode;
        return;
    }

    node* temp = head;
    int count = 0;
    while (temp != nullptr && count < index - 1) {
        temp = temp->nextNode;
        count++;
    }

    if (temp != nullptr) {
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    } else {
        delete newNode; 
    }
}