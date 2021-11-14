#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
class LinkedList
{
public:
	struct node
	{
		string Title;
		string Author;
		string ISBN;
		int Quantity;
		node *next;
	};
	node* head;
	LinkedList();

	string show();

	string IS_Empty();

	string Add_Book_in_List(string title, string author, string isbn, int quantity);

	string Delete_Book(string searchKey);

	string load_Data_From_File(string file_name);

	string save_Data_Into_File(string file_name);

	void Display_All_Books();

	string Search_Book(string searchKey);

	string Remove_Single_Book(string searchkey);

	string Partial_Search_Book(string searchKey);
};

#endif
