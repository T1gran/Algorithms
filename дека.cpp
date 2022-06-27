#include <iostream>

using namespace std;

struct deque					//���� ����
{
    int info;
    deque *next;
    deque *prev;
};

deque* createfirst(int a, deque *p)			//�������� ������� ��������
{
	p->info=a;
    p->next=nullptr;
    p->prev=nullptr;
    return p;
}

deque* createleft(int a, deque* p, deque* s)	//�������� �������� �����
{
	p->info=a;
    p->prev=nullptr;
    p->next=s;
    s->prev=p;
    return p, s;
}

deque* createright(int a, deque* p, deque* s)	//�������� �������� ������
{
	p->info=a;
    p->prev=s;
    p->next=nullptr;
    s->next=p;
    return p, s;
}

deque* deleteleft(int w, int left, deque* p[20])		//�������� �������� �����
{
	if(w==0)
	{
		cout<<"�������� ����������"<<endl;
	}
	if(w==1)
	{
		delete p[left];
		cout<<"������� ������"<<endl;
	}
	if(w>1)
	{
		p[left]=p[left]->next;
		delete p[left]->prev;
		p[left]->prev=NULL;
		cout<<"������� ������"<<endl;
	}
	system("pause");
	system("cls");
	return *p;
}

deque* deleteright(int w, int right, deque* p[20])		//�������� �������� ������
{
	if(w==0)
	{
		cout<<"�������� ����������"<<endl;
	}
	if(w==1)
	{
		delete p[right];
		cout<<"������� ������"<<endl;
	}
	if(w>1)
	{
		p[right]=p[right]->prev;
		delete p[right]->next;
		p[right]->next=NULL;
		cout<<"������� ������"<<endl;
	}
	system("pause");
	system("cls");
	return *p;
}

int showleft(int w, int i, int left, deque *p[20])		//����� ���� �� ����� ����� �������
{
	int r=0;
	if(w>0)
    {
		deque *y[20];
	    for(int z=0; z<i; z++)
	    {
			y[z]=new deque;
	    	y[z]=p[z];	
		}
	    r=left;
	    do
	    {
	        cout<<y[r]->info<<" ";
	        y[r]= y[r]->next;
	    }
	    while(y[r]!=nullptr);
    }
    else
    {
    	cout<<"��� ����"<<endl;
	}
	system("pause");
	system("cls");
}

int showright(int w, int i, int right, deque *p[20])				//����� ���� �� ����� ������ ������
{
	int r=0;
	if(w>0)
    {
	    deque *y[20];
	    for(int z=0; z<i; z++)
	    {
	    	y[z]=new deque;
	    	y[z]=p[z];	
		}
	    r=right;
	    do
	    {
	    	cout<<y[r]->info<<" ";
	        y[r]= y[r]->prev;
	    }
	    while(y[r]!=nullptr);	
	}
	else
	{
		cout<<"��� ����"<<endl;
	}
	system("pause");
	system("cls");
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int size=20;
    deque *p[size];
    int a;
    int i=0, w=0, x=7, r=0, left=0, right=0;
    while(x!=0)
    {
    	cout<<"0.��������� ������\n1.�������� ������� �����\n2.�������� ������� ������\n3.������� ������� �����\n4."
        "������� ������� ������\n5.������� �������� ����� �������\n6.������� �������� ������ ������\n";
    	cin>>x;
    	if(x==1)
    	{
        	cout<<"������� �������, ������� ������ �������� �����: "<<endl;
        	cin>>a;
        	p[i]=new deque;
        	if(w==0)
        	{
        		createfirst(a, p[i]);
        		left=i;
    			right=i;
        	}
        	if(w!=0)
        	{	
        		createleft(a, p[i], p[left]);
            	left=i;
        	}
        	w++;
        	i++;
        	system("cls");
    	}
    	if (x==2)
    	{
        	cout<<"������� �������, ������� ������ �������� ������: "<<endl;
        	cin>>a;
        	p[i]=new deque;
        	if(w==0)
        	{
            	createfirst(a, p[i]);
            	left=i;
    			right=i;
        	}
        	if(w!=0)
			{
        		createright(a, p[i], p[right]);
            	right=i;
        	}
        	i++;
        	w++;
        	system("cls");
    	}
    	if(x==3)
	    {
	    	deleteleft(w,left, p);
	    	if(w>0)
	    	{
	    		w--;
			}
		}
    	if(x==4)
	    {
	    	deleteright(w, right, p);
	    	if (w>0)
			{
				w--;
			}
		}
    	if (x==5)
    	{
    		showleft(w, i, left, p);
    	}
    	if (x==6)
    	{
    		showright(w, i, right, p);	
    	}
	}
	return 0;
}
