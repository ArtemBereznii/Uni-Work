#include <iostream>

struct Node {
    int data;
    Node* next;
};

inline void addToFront(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

inline void addToEnd(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

inline void removeFromFront(Node** head) {
    if (*head != nullptr) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

inline void removeFromEnd(Node** head) {
    if (*head == nullptr) return;

    if ((*head)->next == nullptr) {
        delete* head;
        *head = nullptr;
    }
    else {
        Node* current = *head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

inline Node* searchElement(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) return current;
        current = current->next;
    }
    return nullptr;
}

inline void reverseList(Node** head) {
    Node* prev = nullptr;
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

inline void sortList(Node* head) {
    if (head == nullptr) return;

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

inline void clearList(Node** head) {
    while (*head != nullptr) {
        removeFromFront(head);
    }
}

inline void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "null" << std::endl;
}

// Structure for a doubly linked list node (used in toTwoWayList)
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

// Inline function to convert the singly linked list to a two-way circular linked list
inline DNode* toTwoWayList(Node* head) {
    if (head == nullptr) return nullptr;

    DNode* newHead = new DNode{ head->data, nullptr, nullptr };
    DNode* tail = newHead;
    head = head->next;

    while (head != nullptr) {
        DNode* newNode = new DNode{ head->data, nullptr, tail };
        tail->next = newNode;
        tail = newNode;
        head = head->next;
    }

    // Making the list circular
    newHead->prev = tail;
    tail->next = newHead;

    return newHead;
}

int main() {
    Node* head = nullptr;

    addToFront(&head, 10);
    addToFront(&head, 20);
    addToEnd(&head, 5);
    addToEnd(&head, 15);

    std::cout << "List after adding elements: ";
    printList(head);

    // Searching for an element
    int valueToSearch = 10;
    Node* found = searchElement(head, valueToSearch);
    if (found) {
        std::cout << "Element " << valueToSearch << " found." << std::endl;
    }
    else {
        std::cout << "Element " << valueToSearch << " not found." << std::endl;
    }

    // Reversing the list
    reverseList(&head);
    std::cout << "List after reversing: ";
    printList(head);

    // Sorting the list
    sortList(head);
    std::cout << "List after sorting: ";
    printList(head);

    // Removing elements from front and end
    removeFromFront(&head);
    std::cout << "List after removing from front: ";
    printList(head);

    removeFromEnd(&head);
    std::cout << "List after removing from end: ";
    printList(head);

    // Converting to two-way circular linked list
    DNode* circularList = toTwoWayList(head);
    std::cout << "Two-way circular linked list created." << std::endl;

    // Clearing the original list
    clearList(&head);

    return 0;
}
