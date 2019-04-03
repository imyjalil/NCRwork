#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
struct Node
{
	string name;
	bool directory_flag;
	struct Node *children;
	struct Node *sibling;
	struct Node *parent;
};
class CmdApp
{
	struct Node *root, *current;
public:
	CmdApp()
	{
		root = new Node;
		root->name = "Root";
		root->children = NULL;
		root->parent = NULL;
		root->sibling = NULL;
		root->directory_flag = true;
		current = root;
	}
	vector<string> tokenise(string fullpath, char chr)
	{
		string strdup = "";
		int i = 0; vector<string>tokens;
		for (i = 0; fullpath[i]; i++)
		{
			if (fullpath[i] != chr)
			{
				strdup += fullpath[i];
			}
			else
			{
				tokens.push_back(strdup);
				strdup = "";
			}
		}
		tokens.push_back(strdup);
		return tokens;
	}
	void insert_directory(string fullpath)
	{
		vector<string> tokens = tokenise(fullpath,'/');
		struct Node *iterator, *iterator_down;
		int index_to_search;
		if (tokens[0] == "Root")
		{
			iterator = root;
			index_to_search = 1;
		}
		else
		{
			iterator = current;
			index_to_search = 0;
		}
		iterator_down = iterator->children;
		while (1)
		{
			if (index_to_search == tokens.size() - 1)
			{
				break;
			}
			for (;;)
			{
				if (iterator_down == NULL)
				{
					cout << "Invalid location" << endl; return;
				}
				if (iterator_down->name == tokens[index_to_search] && iterator_down->directory_flag == true)
				{
					index_to_search++;
					iterator = iterator_down;
					iterator_down = iterator_down->children;
					break;
				}
				else
				{
					iterator_down = iterator_down->sibling;
				}
			}
		}
		struct Node* newNode = new Node;
		newNode->name = tokens[tokens.size() - 1];
		newNode->directory_flag = true;
		newNode->children = NULL;
		newNode->parent = NULL;
		newNode->sibling = NULL;
		if (iterator_down == NULL)//if there are no files or directories in the present directory
		{
			newNode->parent = iterator;
			iterator->children = newNode;
		}
		else
		{
			struct Node *last;
			for (last = iterator_down; last->sibling != NULL; last = last->sibling)
			{
				if (last->name == tokens[tokens.size() - 1] && last->directory_flag == true)
				{
					cout << "Directory already exists" << endl; return;
				}
			}
			if (last->name == tokens[tokens.size() - 1] && last->directory_flag == true)
			{
				cout << "Directory already exists" << endl; return;
			}
			newNode->parent = iterator;
			last->sibling = newNode;
		}
	}
	void insert_file(string fullpath)
	{
		vector<string> tokens = tokenise(fullpath, '/');
		struct Node *iterator, *iterator_down;
		int index_to_search;
		if (tokens[0] == "Root")
		{
			iterator = root;
			index_to_search = 1;
		}
		else
		{
			iterator = current;
			index_to_search = 0;
		}
		iterator_down = iterator->children;
		while (1)
		{
			if (index_to_search == tokens.size() - 1)
			{
				break;
			}
			for (;;)
			{
				if (iterator_down == NULL)
				{
					cout << "Invalid location" << endl; return;
				}
				if (iterator_down->name == tokens[index_to_search] && iterator_down->directory_flag == true)
				{
					index_to_search++;
					iterator = iterator_down;
					iterator_down = iterator_down->children;
					break;
				}
				else
				{
					iterator_down = iterator_down->sibling;
				}
			}
		}
		struct Node* newNode = new Node;
		newNode->name = tokens[tokens.size() - 1];
		newNode->directory_flag = false;
		newNode->children = NULL;
		newNode->parent = NULL;
		newNode->sibling = NULL;
		if (iterator_down == NULL)//if there are no files or directories in the present directory
		{
			newNode->parent = iterator;
			iterator->children = newNode;
		}
		else
		{
			struct Node *last;
			for (last = iterator_down; last->sibling != NULL; last = last->sibling)
			{
				if (last->name == tokens[tokens.size() - 1] && last->directory_flag == false)
				{
					cout << "File already exists" << endl; return;
				}
			}
			if (last->name == tokens[tokens.size() - 1] && last->directory_flag == false)
			{
				cout << "File already exists" << endl; return;
			}
			newNode->parent = iterator;
			last->sibling = newNode;
		}
	}
	void change_directory(string fullpath)
	{
		vector<string> tokens = tokenise(fullpath, '/');
		struct Node *iterator, *iterator_down;
		int index_to_search;
		if (tokens.size() == 1 && tokens[0] == "..")
		{
			if (current->parent != NULL)
			{
				current = current->parent;
			}
			return;
		}
		if (tokens.size() == 1 && tokens[0] == ".")
		{
			return;
		}
		if (tokens[0] == "Root")
		{
			if (tokens.size() == 1)
			{
				current = root; return;
			}
			iterator = root; index_to_search = 1;
		}
		else
		{
			iterator = current; index_to_search = 0;
		}
		iterator_down = iterator->children;
		while (1)
		{
			if (index_to_search == tokens.size() - 1)
			{
				break;
			}
			for (;;)
			{
				if (iterator_down == NULL)
				{
					cout << "Invalid location" << endl; return;
				}
				if (iterator_down->name == tokens[index_to_search] && iterator_down->directory_flag == true)
				{
					index_to_search++;
					iterator = iterator_down;
					iterator_down = iterator_down->children;
					break;
				}
				else
				{
					iterator_down = iterator_down->sibling;
				}
			}
		}
		struct Node* iterator_last;
		for (iterator_last = iterator_down; iterator_last != NULL; iterator_last = iterator_last->sibling)
		{
			if (iterator_last->name == tokens[index_to_search])
			{
				iterator_down = iterator_last; break;
			}
		}
		if (iterator_last == NULL)
		{
			cout << "Directory does not exist" << endl; return;
		}
		current = iterator_down;
	}
	bool parent_directory(struct Node *last)
	{
		struct Node *parentPath;
		parentPath = current;
		while (parentPath != NULL)
		{
			if (parentPath == last)
			{
				return true;
			}
			parentPath = parentPath->parent;
		}
		return false;
	}
	void del(Node *iterator)
	{
		if (iterator != NULL)
			del(iterator->sibling);
		if (iterator != NULL && iterator->children != NULL)
			del(iterator->children);
		if (iterator != NULL)
		{
			delete iterator;
		}
	}
	void delete_directory(string fullpath)
	{
		vector<string>tokens = tokenise(fullpath, '/');
		struct Node* iterator, *iterator_down, *iterator_prev;
		int index_to_search;
		if (tokens[0] == "Root")
		{
			if (tokens.size() == 1)
			{
				cout << "Root directory cannot be deleted." << endl; return;
			}
			iterator = root;
			index_to_search = 1;
		}
		else
		{
			iterator = current;
			index_to_search = 0;
		}
		iterator_down = iterator->children;
		iterator_prev = iterator_down;
		while (1)
		{
			if (index_to_search == tokens.size() - 1)
			{
				break;
			}
			for (;;)
			{
				if (iterator_down == NULL)
				{
					cout << "Invalid location" << endl; return;
				}
				if (iterator_down->name == tokens[index_to_search] && iterator_down->directory_flag == true)
				{
					index_to_search++;
					iterator = iterator_down;
					iterator_down = iterator_down->children;
					break;
				}
				else
				{
					iterator_prev = iterator_down;
					iterator_down = iterator_down->sibling;
				}
			}
		}
		struct Node* last;
		for (last = iterator_down,iterator_prev=last; last != NULL; iterator_prev=last, last = last->sibling)
		{
			if (last->name == tokens[index_to_search] && last->directory_flag == true)
			{
				break;
			}
		}
		if (last == NULL)
		{
			cout << "invalid location" << endl; return;
		}
		if (parent_directory(last))
		{
			cout << "In that directory/subdirectory, cannot delete." << endl;
			return;
		}
		if (iterator->children == last)
		{
			if (last->children != NULL)
			{
				del(last->children);
			}
			iterator_prev = iterator_prev->sibling;
			iterator->children = iterator_prev; if(iterator_prev != NULL) iterator_prev->parent = iterator;
			delete last;
		}
		else if (last->sibling == NULL)
		{
			if (last->children != NULL)
			{
				del(last->children);
			}
			iterator_prev->sibling = NULL;
			delete last;
		}
		else
		{
			if (last->children != NULL)
			{
				del(last->children);
			}
			iterator_prev->sibling = last->sibling;
			delete last;
		}
	}
	void delete_file(string fullpath)
	{
		vector<string>tokens = tokenise(fullpath, '/');
		struct Node* iterator, *iterator_down, *iterator_prev;
		int index_to_search;
		if (tokens[0] == "Root")
		{
			if (tokens.size() == 1)
			{
				cout << "Root directory cannot be deleted." << endl; return;
			}
			iterator = root;
			index_to_search = 1;
		}
		else
		{
			iterator = current;
			index_to_search = 0;
		}
		iterator_down = iterator->children;
		iterator_prev = iterator_down;
		while (1)
		{
			if (index_to_search == tokens.size() - 1)
			{
				break;
			}
			for (;;)
			{
				if (iterator_down == NULL)
				{
					cout << "Invalid location" << endl; return;
				}
				if (iterator_down->name == tokens[index_to_search] && iterator_down->directory_flag == true)
				{
					index_to_search++;
					iterator = iterator_down;
					iterator_down = iterator_down->children;
					break;
				}
				else
				{
					iterator_prev = iterator_down;
					iterator_down = iterator_down->sibling;
				}
			}
		}
		struct Node* last;
		for (last = iterator_down, iterator_prev = last; last != NULL; iterator_prev = last, last = last->sibling)
		{
			if (last->name == tokens[index_to_search] && last->directory_flag == false)
			{
				break;
			}
		}
		if (last == NULL)
		{
			cout << "File does not exist." << endl; return;
		}
		if (iterator->children == last)
		{
			iterator_prev = iterator_prev->sibling;
			iterator->children = iterator_prev; if (iterator_prev != NULL) iterator_prev->parent = iterator;
			delete last;
		}
		else if (last->sibling == NULL)
		{
			iterator_prev->sibling = NULL;
			delete last;
		}
		else
		{
			iterator_prev->sibling = last->sibling;
			delete last;
		}
	}
	void print_working_directory()
	{
		cout << current->name << endl;
	}
	void list_files()
	{
		struct Node* iterator = current->children;
		if (iterator == NULL)
		{
			cout << "No files to display" << endl; return;
		}
		while (iterator != NULL)
		{
			cout << iterator->name << " ";
			iterator = iterator->sibling;
		}
		cout << endl;
	}
	void print_path_to_current_directory()
	{
		vector<string>path_from_bottom;
		struct Node* iterator=current;
		while(iterator!=NULL)
		{ 
			path_from_bottom.push_back(iterator->name);
			iterator = iterator->parent;
		}
		for (int i = path_from_bottom.size() - 1; i > 0; i--)
		{
			cout << path_from_bottom[i] << "/";
		}
		cout << path_from_bottom[0];
	}
	void help()
	{
		cout << "mkdir <directory name> - creates a directory" << endl;
		cout << "                         name can be absolute or relative" << endl;
		cout << "mkfil <file name>      - creates a directory" << endl;
		cout << "                         name can be absolute or relative" << endl;
		cout << "cd <directory name>    - changes working directory to target directory" << endl;
		cout << "                         name can be absolute or relative" << endl;
		cout << "ls                     - lists files and directories current directory" << endl;
		cout << "rmdir <directory name> - removes a directory and all its subdirectories and files" << endl;
		cout << "                         name can be absolute or relative" << endl;
		cout << "rmfil <file name>      - removes a directory and all its subdirectories and files" << endl;
		cout << "                         name can be absolute or relative" << endl;
		cout << "pwd                    - prints present working directory" << endl;
		cout << "man                    - lists available commands" << endl;
	}
	void clear_screen()
	{
		system("CLS");
	}
	~CmdApp()
	{
		del(root);
	}
};
int main()
{
	CmdApp cmdapp;
	while (1)
	{
		cmdapp.print_path_to_current_directory();
		cout << ">";
		string command, path;
		cin >> command;
		if (command == "exit")
		{
			break;
		}
		else if (command == "mkdir")
		{
			cin >> path;
			cmdapp.insert_directory(path);
		}
		else if (command == "mkfil")
		{
			cin >> path;
			cmdapp.insert_file(path);
		}
		else if (command == "ls")
		{
			cmdapp.list_files();
		}
		else if (command == "cd")
		{
			cin >> path;
			cmdapp.change_directory(path);
		}
		else if (command == "pwd")
		{
			cmdapp.print_working_directory();
		}
		else if (command == "rmdir")
		{
			cin >> path;
			cmdapp.delete_directory(path);
		}
		else if (command == "rmfil")
		{
			cin >> path;
			cmdapp.delete_file(path);
		}
		else if (command == "clear")
		{
			cmdapp.clear_screen();
		}
		else if (command == "man")
		{
			cmdapp.help();
		}
		else
		{
			cout << "Invalid command. Enter 'man' to list valid commands" << endl;
		}
	}
	return 0;
}