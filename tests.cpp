#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"
#include "Node.h"

TEST_CASE("LIST")
{
	OList *l = new OList();
	l->insert("a");
	l->insert("b");
	l->insert("c");
	l->insert("d");
	CHECK(l->get(0)=="d");
	CHECK(l->get(1)=="c");
}

TEST_CASE("REMOVE")
{
	OList *l = new OList();
        l->insert("a");
        l->insert("b");
        l->insert("c");
	l->remove(1);
	CHECK(l->get(1)=="c");
}

TEST_CASE("CONTAINS")
{
	OList *l = new OList();
        l->insert("a");
        l->insert("b");
        l->insert("c");
	CHECK(l->contains("c"));
	CHECK(!l->contains("z"));
}

