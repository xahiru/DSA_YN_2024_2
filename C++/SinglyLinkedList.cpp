#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert an element at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Delete the first occurrence of an element
    void deleteElement(int data) {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Element not found\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Traverse and print the elements of the list
    void traverse() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free the allocated memory
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;

    // Insert elements
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    std::cout << "List after insertion:\n";
    list.traverse();

    // Delete an element
    list.deleteElement(3);
    std::cout << "List after deletion:\n";
    list.traverse();

    return 0;
}
