#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include "Collatz.h"
#include "LoginSystem.h"
#include "StrengthAnalysis.h"
#include "Generate.h"
#include "Decryption.h"

using namespace std;

/*static std::string encrypt(std::string word, const std::function<std::string(std::vector<int>)> toString)
{
	std::vector<signed int> encword(word.size());
	int offset = 0;
	for (int i = 0; i < word.size(); i++)
	{
		int item = (int)word[i];
		if (item < 0)
			item += 256;
		int toASCII = item + offset;
		int count = 0;
		while (toASCII > 1)
		{
			if (toASCII % 2 == 0)
			{
				toASCII = toASCII / 2;
			}
			else if (toASCII % 2 == 1)
			{
				toASCII = (toASCII * 3) + 1;

			}
			count++;
		}
		encword[i] = count;
		offset = count;
	}
	std::string password;
	password = toString(encword);
	return password;
};

static auto toString = [&](std::vector<int> encword)
{
	std::stringstream hidden;
	for (int i = 0; i < encword.size(); ++i)
	{
		hidden << encword[i];
	}
	std::string encpass = hidden.str();
	return encpass;
};

template<class t>
struct node
{
	t value;
	node* left;
	node* right;
};

template<class E>
class BinaryTree {

public:
	std::vector<int> values;
	BinaryTree() {}
	~BinaryTree() {}

	void insert(struct node<E>** tree, E data)
	{
		if (*tree == nullptr)
		{
			node<E>* newNode = new node<E>();
			newNode->value = data;
			*tree = newNode;
		}
		else if ((*tree)->value > data)
		{
			insert(&(*tree)->left, data);
		}
		else
		{
			insert(&(*tree)->right, data);
		}
	};

	void print_tree(struct node<E>* tree)
	{
		if (tree == nullptr) return;

		print_tree(tree->left);
		values.push_back(tree->value);
		//std::cout << tree->value << ' ';
		print_tree(tree->right);
	};

	void terminate_tree(struct node<E>* tree)
	{
		if (tree == nullptr) return;

		terminate_tree(tree->left);
		terminate_tree(tree->right);
		std::cout << "\nDeleting node : " << tree->value;
		delete tree;
	}

	bool search_tree(struct node<E>** tree, E data)
	{
		if (*tree == nullptr) {
			return false;
		}

		if ((*tree)->value == data) {
			return true;
		}

		if (search_tree(&(*tree)->left, data)) {
			return true;
		}

		return search_tree(&(*tree)->right, data);
	}
};
std::string SecondGroup()
{
	char group2[256];
	for (int i = 0; i < 256; i++)
	{
		group2[i] = (char)i;
	}

	srand((int)std::time(0) * rand());
	std::string words2;
	for (int i = 0; i < 256; i++)
	{
		words2 += group2[i];
	}
	return words2;
};

bool decrypt(std::string example, std::string group, std::string group2,int groupno)
{
	int size = 1, item, noletter = (groupno == 1) ? 27 : 93;// 256;
	std::string prefix, encpref, temp, temp2;
	for (int i = 0; i < example.length(); i++)
	{
		for (int j = 0; j < noletter; j++)
		{
			while (prefix.length() < size)
			{
				item = group[j];
				item = (item < 0) ? item += 256 : item;
				prefix += (char)item;
				temp2 += item;
				temp = encrypt(temp2, toString);
				temp2.clear();
			}
			//std::cout << prefix << "\n";
			encpref = encrypt(prefix, toString);
			if (!example.starts_with(encpref))
				prefix.pop_back();
			//if (example == encpref)
				//return true;
		}
		size++;
		/*if (!example.starts_with(encpref))
			return false;/
	}
	return false;
};
*/

int main()
{
	unique_ptr<Collatz> C = make_unique<Collatz>();
	C->System();

	/*struct node<int>* root = nullptr;
	unique_ptr<BinaryTree<int>> bt = make_unique<BinaryTree<int>>();
	for (int i = 0; i < 256; i++)
	{
		string l;
		l.push_back((char)i);
		if(!bt->search_tree(&root, std::stoi(encrypt(l, toString))))
			bt->insert(&root, std::stoi(encrypt(l, toString)));
		l.pop_back();
	}
	bt->print_tree(root);
	std::vector<int> values = bt->values;
	std::string prac = toString(values);
	//std::cout << values.size();
	std::string all = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !\"#$%^&*(){}[];:'@~,<.>//|*-+"};
	std::string sent = {"A friend to all is a friend to none"};
	std::string code = "27322810313331033910211452912207344136146925461033281533271031012815108114101";
	std::cout << decrypt(code, all, 2) << "\n";
	
	/*if (encrypt(sent, toString) == code)
		cout << "TRUE!\n";
	else
		cout << "FALSE!\n";*/
	//system("pause");
}