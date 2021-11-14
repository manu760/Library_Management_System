#define CATCH_CONFIG_MAIN
#include"LinkList.cpp"
#include"catch.hpp"

TEST_CASE("Empty Error") {
	LinkedList l = LinkedList();
	REQUIRE(l.IS_Empty() == "Empty");
}

TEST_CASE("Add Function") {
	LinkedList l = LinkedList();
	REQUIRE(l.Add_Book_in_List("str","str","str",1) == "Book added successfuly");
}

TEST_CASE("Load Data") {
	LinkedList l = LinkedList();
	REQUIRE(l.load_Data_From_File("books.txt") == "Records successfuly loaded from File.\n");
}

TEST_CASE("Delete Function") {
	LinkedList l = LinkedList();
	REQUIRE(l.Delete_Book("Graph Databases") == "Error! List is empty.Can't delete any books.");
}

TEST_CASE("Load Data Error") {
	LinkedList l = LinkedList();
	REQUIRE(l.load_Data_From_File("boo0000ks.txt") == "Error! File not found.\n");
}
