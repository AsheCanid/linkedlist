#include <string>
#include <iostream>

class link;

   

class link
{
    
    
    public:
    std::string data;
    link* next;
    link* previous;
    
    link(std::string d, link* n, link* p)
    {
        data = d;
        next = n;
        previous = p;
    }
    ~link()
    {
        std::cout << "Link Deleted Successfully";
    }
     void editor(std::string d, link* n, link* p)
    {
        data = d;
        next = n;
        previous = p;
    }
    
    void linkDelete() // Call this fucntion when deleting a link to automatically restructure list
    {
        if (previous != nullptr && next != nullptr)
        {
            linkadjust(previous, next);
            delete this;
        }
        else if (previous == nullptr && next != nullptr)
        {
            linkadjustp(*next, nullptr);
            delete this;
        }
        else if (previous != nullptr && next == nullptr)
        {
            linkadjust(previous, nullptr);
            delete this;
        }
        else
        {
            delete this;
        }
    }
    
    void linkadjust(link* p, link* n)
    {
        next = n;
        previous= p;
    }
    void linkadjust( link* n)
    {
        next = n;
    }
    void linkadjustp(link ths, link* p)
    {
        ths.previous = p;
    }
};    


void editor(link tbe, std::string d, link* next, link* previous)
{
    tbe.editor(d, next, previous);
}
void printLinks(link start)
    {
    if (start.next != nullptr)
        {
            std::cout << start.data << std::endl;
            printLinks(*(start.next));
        }
    }

