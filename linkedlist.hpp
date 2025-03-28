#include <iostream>
#include <string>


class Node // Node def for a doubly linked list
{
    public:
    Node* next; // Next item in list
    Node* prev; // Previous item in list
    const char* data; // String storage
    public:
    Node(const char* data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void newHead(Node*& head, const char* val) // New starting Node insertion
{
    Node* newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode; // redef new Node as start Node
}


void newEnd(Node*& head, const char* val) // New final Node insertion
{
    Node* newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


void nodeAtPos(Node*& head, int pos, const char* val)
{
    if (pos < 1)
    {
        std::cout << "Position must be >= 1" << std::endl;
        return;
    }

    if (pos == 1)
    {
        newHead(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;

    for (int i = 1; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Position out of bounds" << std::endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteHead(Node*& head)
{
    if(head == nullptr)
    {
        std::cout << "List already empty" << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteEnd(Node*& head)
{
    if (head == nullptr)
    {
        std::cout << "The list is already empty" << std::endl;
        return;
    }

    Node* temp = head;

    if (temp->next == nullptr)
    {
        head = nullptr;
        delete temp;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPos(Node*& head, int pos)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    if (pos == 1)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < pos; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Position out of bounds" << std::endl;
        return;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void printFromHead(Node* head)
{
    Node* temp = head;
    std::cout << "List forward: ";
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data;
    std::cout << std::endl;
}

void printFromEnd(Node* head)
{
    Node* temp = head;
    if (temp == nullptr)
    {
        std::cout << "List is empty" << std::endl; return;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    std::cout << "Reversed List: ";
    while (temp->prev != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << temp->data;
    std::cout << std::endl;
}
