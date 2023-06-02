#include <string>
#include <iostream>


struct link
{
    std::string data;
    link* next;
    link* previous;
}; 


void editLink(link l, std::string data, link* n, link* p) // Adjust all data about the link
{
    l.data = data;
    l.next = n;
    l.previous = p;
}

void editLink(link l, std::string data) // Adjust only stored data
{
    l.data = data;
}

void linkadjust(link l, link* n, link* p) // Adjusts both the link to the previous and next link
{
    l.next = n;
    l.previous = p;
}

void linkadjust(link l, link* n) // Adjusts only the pointer to the next link
{
    l.next = n;
}

void linkadjustprev(link l, link* p) // Adjusts the pointer to the link before this link
{
    l.previous = p;
}

void linkdelete(link l) // Deletes a link and adjusts the pointers of the next and previous link's pointers, use instead of free(link)
{
    if (l.previous != NULL && l.next != NULL) // A link before and a link after exist
    {
        l.previous->next = l.next;
        l.next->previous = l.previous;
        free(&l);
        std::cout << "Link Deleted Successfully";
    }
    else if (l.previous != NULL && l.next == NULL) // A link before exists, but no link after
    {
        l.previous->next = NULL;
        free(&l);
        std::cout << "Link Deleted Successfully";
    }
    else if (l.previous == NULL && l.next != NULL) // No link before, but a link after exists
    {
        l.next->previous = NULL;
        free(&l);
        std::cout << "Link Deleted Successfully";
    }
    else // Neither a link before or after exists
    {
        std::cout << "Link Deleted Successfully";
    }
}

void printLinks(link start)
{
    if (start.next != NULL)
    {
    std::cout << start.data << " - ";
    printLinks(*start.next);
    }
    else
    {
        std::cout << start.data << "\n Print complete";
    }

}
