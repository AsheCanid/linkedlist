#include <string>
#include <iostream>


class link
{
   
    private:
		link * head; // First link in list
		link * previous; // Link before the current link (if none, nullptr)
		link * next; // Link after this (if none, nullptr)
		link * tail; // Last link in list
		int data;
	public:
    link() // Create link with no data value
    {
	next = nullptr;
	previous = nullptr;	
	}
	link(int val) // Create link with value
	{
		next = nullptr;
		previous = nullptr;	
		data = val;
	}
	link(int val, link * prev) // Create link with previous link provided
	{
		data = val;
		previous = prev;
    }
	link(int val, link* prev, link * nxt) // Create link with previous and next link provided
	{
		data = val;
		previous = prev;
		next = nxt;
	}
	~link()
	{
		
	}
	void createLink(int data) // Creates linnks dynamically
	{
		link* temp = new link;
		temp->data = data;
		temp->next = nullptr;
		if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {   
            tail->next = temp;
            tail = temp;
        }	
	}
	void printLinks() // Prints values in list from lowest to highest index
	{
		link * temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
            temp = temp->next;
		}
	}
	void newStartLink(int val) // Creates a new start/head link
	{
		link * newLink;
		newLink = new link;
		newLink->data = val;
		newLink->next = head;
		head = newLink;

	}
	void insertLink(int pos, int val) // Insert a link at any given position, save beginning of the list
	{
		link * prev;
		link * temp = new link(val);
		link * thisLink = head;
		prev = head;
		if (pos <= 0)
		throw std::invalid_argument("Invalid Input, Must be greater than 0"); // A pos of <= 0 causes an endless loop
		for (int i = 0; i < pos; i++)
		{
			prev = thisLink;
			try
			{thisLink = thisLink->next;}
			catch(...)
			{
				thisLink = prev;
				thisLink->next = nullptr;
			}
		}
		prev->next = temp; 
		temp->next = thisLink;
	}
	void newEndLink(int val) // Insert link at the end of the list
	{
		link * newLink;
		link * prev;
		prev = tail;
		newLink = new link;
		newLink->previous = tail;
		newLink->data = val;
		prev->next = newLink;
		tail = newLink;
	}
	void deleteLink(int pos)
	{
		link * prev =  nullptr;
		link * thisLink = head;
		int val = 0;
		for (int i = 0; i < pos; i++){
		if (pos == 0){
			head = head->next;
			free(thisLink);}
		else{
			if (i == pos - 1 && thisLink)
			{
				prev->next = thisLink->next;
				free(thisLink);
			}
			else{
				prev = thisLink;
				if(prev == NULL)
					break;
				thisLink = thisLink->next;
			}
		}
		}
	}
	
	
}; 

