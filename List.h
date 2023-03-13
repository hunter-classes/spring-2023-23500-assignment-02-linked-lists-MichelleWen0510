#pragma once
#include <iostream>
#include "Node.h"

class List
{
private:
	Node *head;
public:
	List();
	~List();
  	void insert(std::string data);
  	void insert(int loc, std::string data);
	std::string toString();
	bool contains(std::string item);
	void remove(int loc);
	int length();
  
  

};
