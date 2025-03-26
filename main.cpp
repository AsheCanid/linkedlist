// THIS IS FOR DEBUGGING


#include "expHeader.hpp"

int main()
{
    Node* head = nullptr;

    newEnd(head, "first");
    printFromHead(head);
    printFromEnd(head);
    newEnd(head, "second");
    printFromHead(head);

    newHead(head, "third");
    printFromHead(head);

    nodeAtPos(head, 2, "fourth");

    printFromHead(head);
    printFromEnd(head);

    deleteEnd(head);
    deleteHead(head);
    deleteAtPos(head, 2);

    printFromEnd(head);
    printFromHead(head);
}
