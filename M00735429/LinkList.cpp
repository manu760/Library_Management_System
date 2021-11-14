#include"LinkList.h"

LinkedList::LinkedList() { head = NULL; }

string LinkedList::IS_Empty()
{
	if (head == NULL)
	{
		return "Empty";
	}
	else
	{
		return "Not Empty";
	}
}

string LinkedList::Add_Book_in_List(string title, string author, string isbn, int quantity)
{


	if (title != "")
	{
		node*n;
		n = new node;
		n->Title = title;
		n->Author = author;
		n->ISBN = isbn;
		n->Quantity = quantity;
		n->next = head;
		head = n;
		/////////////////////////////////////////////////////////
		node * temphead = head;
		string temptitle;
		string tempauthor;
		string tempisbn;
		int tempquantity;
		int counter = 0;
		/*while (temphead)
		{
			temphead = temphead->next;
			counter++;
		}*/
		temphead = head;

		//	for (int j = 0; j<counter; j++)
		//{
			while (temphead->next)
			{
				if (temphead->Title > temphead->next->Title)
				{
					temptitle = temphead->Title;
					temphead->Title = temphead->next->Title;
					temphead->next->Title = temptitle;

					tempauthor = temphead->Author;
					temphead->Author = temphead->next->Author;
					temphead->next->Author = tempauthor;

					tempisbn = temphead->ISBN;
					temphead->ISBN = temphead->next->ISBN;
					temphead->next->ISBN = tempisbn;

					tempquantity = temphead->Quantity;
					temphead->Quantity = temphead->next->Quantity;
					temphead->next->Quantity = tempquantity;
				}
				temphead = temphead->next;
			}
			temphead = head;
			//}
		/////////////////////////////////////////////////////////
	}
	return "Book added successfuly";
}

string LinkedList::Delete_Book(string searchKey)
{
	bool found = false;
	if (IS_Empty()=="Empty")
	{
		return "Error! List is empty.Can't delete any books.";
	}
	else
	{
		if (head->Title == searchKey)
		{
			node * temp = head;
			head = head->next;
			delete temp;;
			found = true;
			return "Book deleted.";
		}
		if (head->next == NULL)
		{
			if (head->Title == searchKey)
			{
				delete head; 
				found = true; 
				head = NULL;
				return "Book deleted.";
			}
		}
		node* temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->Title == searchKey)
			{
				node* temp_ptr = temp->next->next;
				delete temp->next; 
				found = true;
				temp->next = temp_ptr;
				return "Book deleted.";
			}
			temp = temp->next;
		}
	}
}

string LinkedList::load_Data_From_File(string file_name)
{
	string title = "", authors = "", isbn = "", quantity = "";
	int count = 0;
	fstream file;
	file.open(file_name, ios::in);
	if (file) 
	{
		while (getline(file, title, '\t'))
		{
			title.erase(std::remove(title.begin(), title.end(), '\n'), title.end());
			getline(file, authors, '\t');
			getline(file, isbn, '\t');
			getline(file, quantity, '\t');
			stringstream convert(quantity);
			int x = 0;
			convert >> x;
			Add_Book_in_List(title, authors, isbn, x);
			count++;
		}
	}
	else
	{
		file.close();
		return "Error! File not found.\n";
	}
	if (count > 0)
	{
		file.close();
		return ("Records successfuly loaded from File.\n");
	}
}

void LinkedList::Display_All_Books()
{
	if (IS_Empty() == "Empty")
	{
		cout << "Error! List is empty. Please load data from File.\n";
	}
	else
	{
		node *ptr;
		ptr = head;
		int count = 1;
		while (ptr != NULL)
		{
			cout << "Serial Number      : " << count << endl;
			cout << "Book Title         : " << ptr->Title << endl;
			cout << "Author(s) Name(s)  : " << ptr->Author << endl;
			cout << "ISBN Number        : " << ptr->ISBN << endl;
			cout << "Quantity Available : " << ptr->Quantity << endl;
			cout << "---------------------------------------------------------------------------------\n";
			count++;
			ptr = ptr->next;
		}
	}
}

string LinkedList::Search_Book(string searchKey)
{
	if (IS_Empty() == "Empty")
	{
		return "Error! List is empty. Please load data from File.\n";
	}
	else
	{
		node *ptr;
		ptr = head;
		int found = 0;
		while (ptr != NULL)
		{
			if (ptr->Title==searchKey)
			{
				cout << "Boot Title         : " << ptr->Title << endl;
				cout << "Author(s) Name(s)  : " << ptr->Author << endl;
				cout << "ISBN Number        : " << ptr->ISBN << endl;
				cout << "Quantity Available : " << ptr->Quantity << endl;
				cout << "---------------------------------------------------------------------------------\n";
				found++;
				return "Book Found";
			}
			ptr = ptr->next;
		}
		if (found == 0)
		{
			return "Book not Found.\n";
		}
	}
}

string LinkedList::Remove_Single_Book(string searchKey)
{
	if (IS_Empty() == "Empty")
	{
		return "Error! List is empty. Please load data from File.\n";
	}
	else
	{
		node *ptr;
		ptr = head;
		int found = 0;
		int quan = 0;
		while (ptr != NULL)
		{
			if (ptr->Title == searchKey)
			{
				found++;
				if (ptr->Quantity > 0)
				{
					quan++;
					ptr->Quantity--;
					return "Book Found and removed.\n";
				}
				else
				{
					return "Error! Quantity is 0.\n";
				}
			}
			ptr = ptr->next;
		}
		if (found == 0)
		{
			return "Book not Found.\n";
		}
	}
}

string LinkedList::Partial_Search_Book(string searchKey)
{
	if (IS_Empty() == "Empty")
	{
		return "Error! List is empty. Please load data from File.\n";
	}
	else
	{
		node *ptr;
		ptr = head;
		int found = 0;
		string rtn = "Not Found.";
		while (ptr != NULL)
		{
			std::size_t found = ptr->Title.find(searchKey);
			if (found != std::string::npos)
			{
				found++;
				rtn = "Found.";
				cout << "Boot Title         : " << ptr->Title << endl;
				cout << "Author(s) Name(s)  : " << ptr->Author << endl;
				cout << "ISBN Number        : " << ptr->ISBN << endl;
				cout << "Quantity Available : " << ptr->Quantity << endl;
				cout << "---------------------------------------------------------------------------------\n";
			}
			ptr = ptr->next;
		}
		return rtn;
	}
}

string LinkedList::save_Data_Into_File(string filename)
{
	if (IS_Empty() == "Empty")
	{
		return "Error! List is empty. Please load data from File.\n";
	}
	else
	{
		ofstream file;
		file.open(filename, ios::out);
		node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			file << ptr->Title << '\t' << ptr->Author << '\t' << ptr->ISBN << '\t' << ptr->Quantity << '\t' << endl;
			ptr = ptr->next;
		}
		file.close();
		return "Data uploaded to file successfully.";
	}
}
