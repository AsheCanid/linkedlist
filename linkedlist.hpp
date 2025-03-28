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

Node* newEndret(Node*& head, const char* val) // New final Node insertion
{
    Node* newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return newNode;
}

void nodeAtPos(Node*& head, int pos, const char* val) // Index starts at 1
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

void deleteEndFast(Node*& endNode)
{
    Node* temp = endNode;
    if (endNode == nullptr)
    {
        std::cout << "The list is already empty" << std::endl;
        return;
    }
    temp->prev->next = nullptr;
    delete temp;
    return;
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

void printFromEndFast(Node* endNode)
{
    Node* temp = endNode;
    std::cout << "List reverse: ";
    while (temp->prev != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    std::cout << temp->data;
    std::cout << std::endl;
}

void editNode(Node* head, int pos, char* val)
{
    Node* temp = head;
    if (pos < 1)
    {
        std::cout << "Position must >= 1" << std::endl;
        return;
    }
    for (int i = 1; i < pos && (temp->next != nullptr); i++)
    {
        temp = temp->next;
    }
    temp->data = val;
    return;
}

void findNode(Node* head, char* val)
{
    Node* temp = head;
    int pos = 1;
    while (temp->next != nullptr && temp->data != val)
    {
        temp = temp->next;
        pos++;
    }
    if (temp->data == val)
    {
        std::cout << "Node with value " << val << " found at position " << pos << std::endl;
    }
    else
    {
        std::cout << "No node with value " << val << " found in list" << std::endl;
    }
    return;
}

Node* getEnd(Node* head)
{
    Node* endNode;
    Node* temp = head;
    if (head == nullptr)
    {
        std::cout << "The list is empty" << std::endl;
        return nullptr;
    }
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    endNode = temp;
    return endNode;
}

int getListSize(Node* head)
{
    int sizeList = 1;
    if (head == nullptr)
    {
        std::cout << "The list is empty" << std::endl;
        return 0;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        sizeList++;
    }
    return sizeList;
}
