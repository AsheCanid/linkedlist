#include <iostream>
#include <string>


class Node // Node def for a doubly linked list
{
    public:
    Node* next; // Next item in list
    Node* prev; // Previous item in list
    const char* data; // String storage
    public:
    Node()
    {
        this->next = nullptr;
        this->prev = nullptr;
    }
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

Node* newEndRet(Node*& head, const char* val) // New final Node insertion and returns its address
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

void deleteHead(Node*& head) // Deletes and reassigns starting node
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

void deleteEnd(Node*& head) // Deletes and reassigns final node
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

void deleteEndFast(Node*& endNode) // Same as delete end but directly accesses endnode
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

void deleteAtPos(Node*& head, int pos) // Deletes at given position
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

void deleteAtPosReverse(Node*& endNode, int pos, int listSize) // Deletes at position but indexes from final position
{
    if (endNode == nullptr)
    {
        std::cout << "Invalid or missing end node" << std::endl;
        return;
    }
    if (pos = listSize)
    {
        deleteEndFast(endNode);
        return;
    }

    int navigate = listSize - (listSize - pos);
    Node* temp = endNode;

    for (int i = 1; temp != nullptr && i < navigate; i++)
    {
        temp = temp->prev;
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

void printFromHead(Node* head) // Prints from starting node
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

void printFromEnd(Node* head) // Iterates through list and then prints in reverse
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

void printFromEndFast(Node* endNode) // Prints from reverse from end node directly
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

void swapNode(Node* head, int swapPos1, int swapPos2) // Swaps data from 2 given nodes via position
{
    Node* temp = head;
    const char* data1;
    const char* data2;

    if (swapPos1 == swapPos2)
    {
        std::cout << "Nothing to swap" << std::endl;
    }

    if (swapPos1 > swapPos2)
    {
        int i = 1;
        for (i; i < swapPos2 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        data2 = temp->data;
        for (i; i < swapPos1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        data1 = temp->data;
        temp = head;
        i = 1;
        for (i; i < swapPos2 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        temp->data = data1;
        for (i; i < swapPos1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        temp->data = data2;
        return;
    }
    else
    {
        int i = 1;
        for (i; i < swapPos1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        data1 = temp->data;
        for (i; i < swapPos2 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        data2 = temp->data;
        temp = head;
        i = 1;
        for (i; i < swapPos1 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        temp->data = data2;
        for (i; i < swapPos2 && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        temp->data = data1;
        return;
    }
    return;
}

void editNode(Node* head, int pos, char* val) // Changes data of node at position
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

void findNode(Node* head, char* val) // Find node by data value
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

void findNode(Node* head, int pos) // Find node value at position
{
    Node* temp = head;
    const char* val;
    if (pos < 1)
    {
        std::cout << "Position must be greater than 1" << std::endl;
        return;
    }
    int i = 1;
    while (i < pos && temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == nullptr && i < pos)
    {
        std::cout << "Position out of bounds" << std::endl;
        return;
    }
    val = temp->data;
    std::cout << "Node at position " << pos << " contains value " << val << std::endl;
    return;
}

void findNodeReverse(Node* endNode, char* val, int listSize) // Find node by data value but starts searching from end of list
{
    Node* temp = endNode;
    int pos = listSize;
    while (temp->prev != nullptr && temp->data != val)
    {
        temp = temp->prev;
        pos--;
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

int findNodeReverseRet(Node* endNode, char* val, int listSize) // Find node by data value but starts searching from end of list and return its position as int
{
    Node* temp = endNode;
    int pos = listSize;
    while (temp->prev != nullptr && temp->data != val)
    {
        temp = temp->prev;
        pos--;
    }
    if (temp->data == val)
    {
        std::cout << "Node with value " << val << " found at position " << pos << std::endl;
    }
    else
    {
        std::cout << "No node with value " << val << " found in list" << std::endl;
    }
    return pos;
}

int findNodeRet(Node* head, char* val) // Find node by data value and return position as int
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
    return pos;
}

Node* getEnd(Node* head) // Finds end node and returns its address
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

int getListSize(Node* head) // Iterates through and returns list size
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
