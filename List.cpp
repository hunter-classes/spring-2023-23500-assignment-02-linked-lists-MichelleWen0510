#include <iostream>
#include "Node.h"
#include "List.h"

List::List()
{
	head = nullptr;
}

void List::insert(std::string data)
{
	Node *tmp = new Node(data);
	tmp->setNext(head);
	head = tmp;
}

void List::insert(int loc, std::string data)
{
	Node *walker, *trailer;
	walker = this->head; // start of the list
	trailer = nullptr; // one behind
	
	while(loc>0 && walker != nullptr)
	{
		loc=loc-1;
		trailer=walker;
		walker = walker->getNext();
	}

	if (loc > 0)
	{
    		throw std::out_of_range("Our insert is out of range");
	}

	Node *newNode = new Node(data);
  	if (trailer == nullptr)
	{
   		newNode->setNext(head);
		head = newNode;
	} else {
		newNode->setNext(walker);
		trailer->setNext(newNode);
	}
}

int List::length()
{
	int count = 0;
	Node *walker = head;
	while (walker != nullptr)
	{
		count++;
		walker = walker->getNext();
  	}
  	return count;
}

std::string List::toString()
{
	Node *tmp = this->head;
	std::string result = "";
	while (tmp != nullptr)
	{
    		result = result + tmp->getData();
		result = result + "-->";
		tmp = tmp->getNext();
	}
	result = result + "nullptr";
	return result;
}

bool List::contains(std::string item)
{
	Node *temp = this->head;
	bool val = false;
	while(temp != nullptr)
	{
		if(temp->getData() == item)
		{
			val = true;
		}
		temp = temp->getNext();
	}
	return val;
}

void List::remove(int loc)
{
	Node *walker, *trailer;
	walker = this->head;
	trailer = nullptr;
	for(int i=0; i<loc; i++)
	{
		trailer = walker;
		walker = walker->getNext();
	}
	trailer->setNext(walker->getNext());
	walker->setNext(nullptr);
	walker->setData("");
}

List::~List()
{
	delete head;
}



