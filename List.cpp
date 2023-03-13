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
	walker = this->head;
	trailer = nullptr;
	
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
	while(loc>0 && walker != nullptr)
	{
		loc=loc-1;
		trailer = walker;
		walker = walker->getNext();
	}
	if(walker == nullptr)
	{
		throw std::out_of_range("Tried to remove out of range");
	}
	if(trailer == nullptr)
	{
		head = walker->getNext();
		delete walker;
	} else {
		trailer->setNext(walker->getNext());
		delete walker;
	}
}

List::~List()
{
	std::cerr << "Calling the destructor\n";
	Node *walker = head;
	Node *trailer = nullptr;
	while(walker != nullptr)
	{
		trailer = walker;
		walker = walker->getNext();
		delete trailer;
	}
}



