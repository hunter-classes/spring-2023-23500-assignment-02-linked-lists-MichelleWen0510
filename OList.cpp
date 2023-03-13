#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList()
{
	head = nullptr;
}

OList::~OList()
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

void OList::insert(std::string data)
{
	Node *tmp = new Node(data);
	tmp->setNext(head);
	head = tmp;
}

std::string OList::toString()
{
	Node *tmp = this->head;
	std::string result = "";
	while(tmp != nullptr)
	{
		result = result + tmp->getData();
		result = result + "-->";
		tmp = tmp->getNext();
	}
	result = result + "nullptr";
	return result;
}

bool OList::contains(std::string data)
{
	Node *tmp = this->head;
	bool val = false;
	while(tmp != nullptr)
	{
		if(tmp->getData() == data)
		{
			val = true;
		}
		tmp = tmp->getNext();
	}
	return val;
}

std::string OList::get(int loc)
{
	Node *tmp = this->head;
	while(loc > 0 && tmp != nullptr)
	{
		loc--;
		tmp = tmp->getNext();
	}
	if(tmp == nullptr)
	{
		return "nullptr";
	}
	return tmp->getData();
}

void OList::remove(int loc)
{
	Node *walker, *trailer;
	walker = this->head;
	trailer = nullptr;
	while(loc > 0 && walker != nullptr)
	{
		loc = loc-1;
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

void OList::reverse()
{
	Node *walker, *trailer;
	walker = this->head;
	trailer = nullptr;
	while(walker != nullptr)
	{
		Node *tmp = walker->getNext();
		walker->setNext(trailer);
		trailer = walker;
		walker = tmp;
	}
	head=trailer;
}


