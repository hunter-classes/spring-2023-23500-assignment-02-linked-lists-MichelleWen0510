#include <iostream>
#include "List.h"

int main()
{
	List *l = new List();
	std::cout << l->toString() << " " << l->length() << "\n";
	l->insert(0,"a");
	std::cout << l->toString() << " " << l->length() << "\n";
	l->insert(0,"b");
	l->insert(0,"c");
	l->insert(0,"d");
	try {
		l->insert(10,"x");
	} catch (std::exception e){
	std::cout << "Insert x didn't work\n";
	}
	std::cout << l->toString() << "\n";
	l->insert(2,"inserted at 2");
	std::cout << l->toString() << "\n";
	l->insert(5,"inserted at end");
	std::cout << l->toString() << " " << l->length() << "\n";

	std::cout << "Does it contain c: " << l->contains("c") << "\n";
	std::cout << "Does it contain z: " << l->contains("z") << "\n";
	l->remove(2);
	std::cout << "Removed second item: " <<  l->toString() << l->length() << "\n";

	delete l; //Uses deconstructor and then deletes the list

	return 0;
}
