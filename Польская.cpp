#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a=2, h=0, j=0;
	int priority[50]={0};
	char* stack=new char [100];
	char* inf=new char [100];
	int choose = 0, q=0, y=0, size = 0, i = 0;
	char out[100];
	cout<<"¬ведите выражение в инфиксной форме: "<<endl;			//ввод выражени€
	while(inf[j]!=13)
	{
		j++;
		inf[j]=_getch();
		cout<<inf[j];
	}
	if(j<2)															//проверка на пустоту
	{
		cout<<"ѕустое выражение"<<endl;
		return 1;
	}
	int u=j;
	for(j=0;j<u;j++)
	{
		if((inf[j]!='+')&&(inf[j]!='-')&&(inf[j]!='/')&&(inf[j]!='*')&&(inf[j]!='^')&&(inf[j]!='(')&&(inf[j]!=')'))
		{
			out[i]=inf[j];														//заполнение выходной строки
			i++;			
		}
		if((inf[j]=='+')||(inf[j]=='-')||(inf[j]=='/')||(inf[j]=='*')||(inf[j]=='^')||(inf[j]=='('))
		{
			if (inf[j]=='^') priority[q]=3;										//определение приоритета операции
			if ((inf[j]=='*')||(inf[j]=='/')) priority[q]=2;
			if ((inf[j]=='+')||(inf[j]=='-')) priority[q]=1;
			if (inf[j]==40)
			{																	
				stack[q]=inf[j];												//заполнение стека
				q++;
			}
			else
			{
				if ((priority[q]>priority[q-1])||stack[q-1]=='(')
				{
					stack[q]=inf[j];
					q++;
				}
				else
				{
					out[i]=stack[q-1];
					i++;
					stack[q-1]=inf[j];
				}
			}
		}
		if(inf[j]==')')															//выталкивание из стека в выходную строку
		{
			y=q-1;
			while(stack[y]!='(')
			{
				out[i]=stack[y];
				i++;
				y--;
			}
			q=y;
		}			
	}
	cout<<"¬ыход: ";															//вывод выходной строки
	for(h=1; h<i; h++)
	{
		cout<<out[h]<<" ";
	}
	cout<<endl<<"—тек: ";														//вывод стека
	for(h=0;h<q;h++)
	{
		cout<< stack[h] <<" ";
	}
	cout<<endl;
	system("pause");
	q=h-1;
	for(int h=q ;h>-1;h--)
	{
		out[i]=stack[h];														//выталкивание оставшихс€ элементов стека в выходную строку
		i++;
	}
	for(h = 1 ; h<i; h++)
	{
		cout<<out[h]<<" ";
	}
	cout<<endl;
	system("pause");
	delete [] stack;
	return 0;
}
