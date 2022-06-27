#include <iostream>
using namespace std;

struct node												//узел дерева
{
	int value;
	node* right = nullptr;
	node* left = nullptr;
	int height = 1;
};

int balanceindex(node*& a)								//балансировка индексов
{
	if (a == nullptr)
	{
		return 0;
	}
	return (a->right != nullptr ? a->right->height : 0) - (a->left != nullptr ? a->left->height : 0);
}

void changeheight(node*& a)				//выравнивание высоты узла 
{										//Сравниваем левого и правого потомка, находим максимальный, прибавляем 1 и записываем в узел
	if (a == nullptr)
	{
		return;
	}
	int hl = (a->left != nullptr ? a->left->height : 0);
	int hr = (a->right != nullptr ? a->right->height : 0);
	a->height = __max(hl, hr) + 1;
}

node* bigleftturn(node*& a)				//большой левый поворот
{
	node* b = a->right;
	node* c = b->left;
	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;
	changeheight(a);
	changeheight(b);
	changeheight(c);
	return c;
}

node* smallrightturn(node*& a)				//малый правый поворот
{
	node* b = a->left;
	a->left = b->right;
	b->right = a;
	changeheight(a);
	changeheight(b);
	return b;
}

node* bigrightturn(node*& a)			//большой правый поворот
{
	node* b = a->left;
	node* c = b->right;
	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;
	changeheight(a);
	changeheight(b);
	changeheight(c);
	return c;
}

node* smallleftturn(node*& a)				//малый левый поворот
{
	node* b = a->right;
	a->right = b->left;
	b->left = a;
	changeheight(a);
	changeheight(b);
	return b;
}

node* balance(node*& a)						//балансировка
{
	changeheight(a);
	if (balanceindex(a) == 2)
	{
		if (balanceindex(a->right) < 0)
		{
			return bigleftturn(a);
		}
		return smallleftturn(a);
	}
	if (balanceindex(a) == -2)
	{
		if (balanceindex(a->left) > 0)
		{
			return bigrightturn(a);
		}
		return smallrightturn(a);
	}
	return a;
}

node* insert(node* root, int value)		//добавление узла в дерево
{
	if (root == nullptr)
	{
		node* p = new node;
		p->value = value;
		return p;
	}
	if (value == root->value)
	{
		return root;
	}
	if (value < root->value)
	{
		root->left = insert(root->left, value);
	}
	else
	{
		root->right = insert(root->right, value);
	}
	return balance(root);
}

node* searchmin(node* root)				//Поиск минимума дерева
{
	if (root == nullptr)
	{
		return root;
	}
	if (root->left == nullptr)
	{
		return root;
	}
	searchmin(root->left);
}

void print_Tree(node* p, int level)			//вывод дерева в виде дерева
{
	if (p)
	{
		print_Tree(p->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->value << endl;
		print_Tree(p->left, level + 1);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int level=0;
	node* root = nullptr;
	int x;
	bool again = true;
	while (again)
	{
		cout<<"0.Завершить работу"<<endl << "1.Добавить узел в дерево"<<endl<<"2.Вывести дерево в виде дерева"<<endl;
		cin >> x;
		switch (x)
		{
		case 0:
			again = false;
			continue;
		case 1:
			system("cls");
			cout << "Введите число: " << endl;
			cin >> x;
			root = insert(root, x);
			break;
		case 2:
			cout << endl;
			print_Tree (root, level);
			break;
			default:
			continue;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
