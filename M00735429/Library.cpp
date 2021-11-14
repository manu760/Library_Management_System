#include<iostream>
#include<fstream>
#include<string>
#include"LinkList.h"
#include"catch.hpp"
using namespace std;

void showMenu()
{
	cout << "1) Load Data from a File.\n";
	cout << "2) Add new Book.\n";
	cout << "3) Disply All Books.\n";
	cout << "4) Search a Book.\n";
	cout << "5) Partial Search a Book.\n";
	cout << "6) Permanently Delete a Book.\n";
	cout << "7) Remove a single Book.\n";
	cout << "8) Save data into File.\n";
	cout << "9) Exit Program.\n";
	cout << "\nPlease enter your choice :  ";
}

int main(int argc,char* argv[])
{
	LinkedList l;
	cout<<l.load_Data_From_File(argv[1]);
	int choice = 0;
	while (choice != 8)
	{
		system("cls");
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string file_name;
			cout << "Enter file name : "; cin >> file_name;
			cout << l.load_Data_From_File(file_name) << endl;
			system("pause");break;
		}
		case 2:
		{
			string title, author, isbn; int quantity;
			cout << "Enter Title     : "; cin.ignore(); getline(std::cin, title);
			cout << "Enter Author(s) : "; getline(std::cin, author);
			cout << "Enter ISBN      : "; getline(std::cin, isbn);
			cout << "Enter Quantity  : "; cin >> quantity;
			cout << l.Add_Book_in_List(title, author, isbn, quantity) << endl;
			system("pause");break;
		}
		case 3:
		{
			l.Display_All_Books();
			system("pause");break;
		}
		case 4:
		{
			string search_key;
			cout << "Enter Book Title to search : "; cin.ignore(); getline(std::cin, search_key);
			cout << l.Search_Book(search_key) << endl;
			system("pause");break;
		}
		case 5:
		{
			string search_key;
			cout << "Enter Partial Book Title to search : "; cin.ignore(); getline(std::cin, search_key);
			cout << l.Partial_Search_Book(search_key) << endl;
			system("pause");break;
		}
		case 6:
		{
			string search_key;
			cout << "Enter correct Book Title to delete : "; cin.ignore(); getline(std::cin, search_key);
			if (l.Delete_Book(search_key) == "Book deleted.")
			{
				cout << "Boot with title ( " << search_key << " ) has been deleted.\n";
			}
			else
			{
				cout << "Book not found.\n";
			}
			system("pause");break;
		}
		case 7:
		{
			string search_key;
			cout << "Enter correct Book Title to remove a single book : "; cin.ignore(); getline(std::cin, search_key);
			cout << l.Remove_Single_Book(search_key);
			system("pause"); break;
		}
		case 8:
		{
			string file_name;
			cout << "Enter file name : "; cin >> file_name;
			cout << l.save_Data_Into_File(file_name);
			system("pause"); break;
		}
		case 9:
		{
			cout << "Exiting Program.\n";
			return 0;
			system("pause");break;
		}
		default:
		{
			cout << "Error! Please enter correct choice. (1-7)\n";
			system("pause");break; 
		}
		}
	}
	system("pause");
}


