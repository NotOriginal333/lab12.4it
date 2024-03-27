#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head; 
    }
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; 
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << std::endl;
}

void deleteNext(Node*& head, int targetValue) {
    if (head == nullptr || head->next == head) {
        return; 
    }
    Node* current = head;
    Node* nextNode = head->next;
    do {
        if (current->data == targetValue && nextNode != head) {
            Node* temp = nextNode;
            current->next = nextNode->next;
            delete temp;
            nextNode = current->next;
        }
        else {
            current = current->next;
            nextNode = nextNode->next;
        }
    } while (nextNode != head);
}

int main() {
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    std::cout << "Initial List: ";
    printList(head);

    deleteNext(head, 3);

    std::cout << "List after deletion: ";
    printList(head);

    return 0;
}
