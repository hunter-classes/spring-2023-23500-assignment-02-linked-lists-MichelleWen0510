#include <iostream>
#include "OList.h"

int main()
{
	OList *l = new OList();
	std::cout << l->toString() << "\n";
	l->insert("a");
	std::cout << l->toString() << "\n";
	l->insert("b");
	l->insert("c");
	l->insert("d");
	std::cout << l->toString() << "\n";
	std::cout << "Does it contain c: " << l->contains("c") << "\n";
	std::cout << "Does it contain z: " << l->contains("z") << "\n";
	l->remove(2);
	std::cout << "Removed second item: " <<  l->toString() << "\n";
	std::cout << "Pos 0: " << l->get(0) << "\n";
	std::cout << "Pos 1: " << l->get(1) << "\n";
	std::cout << "Pos 10: " << l->get(10) << "\n";


	l->reverse();
	std::cout << "Reversed: " << l->toString() << "\n";

	return 0;
}
