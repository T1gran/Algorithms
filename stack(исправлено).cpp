#include <iostream>

using namespace std;

int push()											//���������� �������� � ����
{	
	int a=0;
	cout<<"������� �������: "<<endl;
	cin>>a;
	return a;
}

int pop(int i)										//�������� �������� �� �����
{
	if(i==0)
		{ 
			cout<<"���� ����"<<endl;
			system("pause");
		}
		else
		{
			i--;
		}
	return i;
}

void show(int* stack, int i)						//����� ����� �� �����
{
		int n=i;
		if(n==0) cout<<"���� ����"<<endl;
		else
		{
			for(i=0;i<n;i++)
			{
				cout<<stack[i]<<" ";
			}
		}
		cout<<endl;
		system("pause");
}

int main()
{
	setlocale(LC_ALL, "rus");
	int a=30;
	int* stack=new int [a];
	int choose = 0;
	int size = 0;
	int i = 0;
	menu:
	cout<<"1.�������� ������� � ����"<<endl<<"2.������� ������� �� �����"<<endl<<"3.������� ���� �� �����"<<endl<<"4.��������� ������"<<endl;
	cin >> choose;
	if(choose==1)
	{
		if(size<a)
		{
			size++;
			int t = push();
			stack[i]=t;
			i=size;
			system("cls");
		}
		else														//��������� ������
		{
			size++;										
			a=a*2;
			int* new_stack = new int[a];
			for(i=0;i<size-1;i++)
			{
				new_stack[i] = stack[i];
			}
			new_stack[i] = push();
			delete[] stack;
			stack = new_stack;
			i=size;
			system("cls");
		}
	}
	if(choose==2)
	{
		size = pop(size);
		system("cls");
	}
	if(choose==3)
	{
		show(stack, size);
		system("cls");
	}
	if(choose==4) return 0;
	goto menu;
	delete [] stack;
	return 0;
}
