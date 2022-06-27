#include <iostream>
#include <cstdlib>
using namespace std;
int GetMinrun(int n)			//вычисление минрана
{
    int r = 0;           /* станет 1 если среди сдвинутых битов будет хотя бы 1 ненулевой */
    while (n >= 64) 
	{
    	r |= n & 1;
    	n >>= 1;
	}
	return n + r;
}

int getRandomNumber(int min, int max)				//псевдорандомные числа
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int* enter(int* a, int lenght)				//заполнение входного массива
{
	int j=0;
	cout<<"Входной массив: ";
	for(j=0;j<lenght;j++)
	{
		a[j]=getRandomNumber(1, 300);
		cout<<a[j]<<" ";
	}
	return a;
}

int* unite(int* start, int* run, int less, int bigger)				//слияние подмассивов
{
	int i=0;
	int x=0;
	int t=0;
	int z=0;
	int left=0;
	int* temporary=new int[less];
	int* sorted=new int[500];
	if(less>bigger) left=bigger;
	else left=less;
	for(i=start[less];i<start[less+1];i++) 
	{ 
		temporary[t]=run[i];
		t++; 
	}
	z=t;
	t=0;
	x=start[bigger];
	i=0;
	while(1)
	{
		if(temporary[t]>run[x])
		{
			sorted[i]=run[x];
			x++;
		}
		else
		{
			sorted[i]=temporary[t];
			t++;
		}
		i++;
		if(t==z)
		{
			for(x=x;x<start[bigger+1];x++)
			{
				sorted[i]=run[x];
				i++;
			}
			break;
		} 
		if(x==start[bigger+1])
		{
			for(t=t;t<z;t++)
			{
				sorted[i]=temporary[t];
				i++;
			}
			break;
		}
	}
	int e=start[left];
	for(t=0;t<i;t++)
	{
		run[e]=sorted[t];
		e++;
	}
	return run;	 
}

int* searchRun(int* a, int* run, int lenght, int* size, int* start, int k, int i, int minrun, int x, int j)				//поиск подмассивов
{
	int change=0;
	run[i]=a[i];
	run[i+1]=a[i+1];
	while(1)
	{
		if(((a[i]>a[i+1])&&(a[i+1]>a[i+2]))||((a[i]<a[i+1])&&(a[i+1]<a[i+2])))
		{
			if((i+2>lenght)||(i+2==lenght)) break;
			run[i+2]=a[i+2];
		}
		else
		{
			break;	
		}
		i++; 
	}
	k=i+1;
	size[x]=k+1-start[x];
	i=start[x];
	if(run[i]>run[i+1])
	{
		for(i=start[x];i<k;i++)
		{
			run[i]^=run[k]^=run[i]^=run[k];
			k--;
			if(i>lenght) break;
		}
	}
	if((size[x]<minrun)&&(start[x]+minrun<=lenght))
	{
		for(i=size[x]+start[x]; i<minrun+start[x]; i++)
		{
			run[i]=a[i];
		}
		for(i=size[x]+start[x]; i<minrun+start[x]; i++)
		{
			if(run[i]<run[i-1])
			{
				change=run[i];
				j=i-1;
				while((run[i]<run[j])&&(j>start[x]-1))
				{
					j--;
				}
				for(k=i; k>j; k--)
				{
					run[k]=run[k-1];
				}
				run[j+1]=change;
			}
		}
		k=i-1;
		size[x]=minrun;
	}
	if((size[x]<minrun)&&(start[x]+minrun>lenght))
	{
		for(i=size[x]+start[x]; i<lenght; i++)
		{
			run[i]=a[i];
		}
		for(i=size[x]+start[x]; i<lenght; i++)
		{
			if(run[i]<run[i-1])
			{
				change=run[i];
				j=i-1;
				while((run[i]<run[j])&&(j>start[x]-1))
				{
					j--;
				}
				for(k=i; k>j; k--)
				{
					run[k]=run[k-1];
				}
				run[j+1]=change;
			}
		}
		k=i-1;
		size[x]=lenght-start[x];	
	}
	start[x+1]=start[x]+size[x];
	return run, &i, start, size;	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//шаг 1.
	int lenght=0, minrun=0, k=0, i=0, j=0, x=0, limit=0, change=0;
	int less=0, bigger=0;
	int size[100]={0};
	int start[100]={0};
	cout<<"Выберите длину массива: "<<endl;
	cin>>lenght;
	int* a=new int[lenght];
	int* run=new int[lenght];
	enter(a, lenght);
	minrun=GetMinrun(lenght);
	cout<<endl<<"minrun = "<<minrun<<endl;
	here:
	i=start[x];
	if(i+2<=lenght) searchRun(a, run, lenght, size, start, k, i, minrun, x, j); //больше одного эл-та осталось
	if((i<lenght)&&(i+1==lenght))//1 элемент
	{
		run[i]=a[i];
		size[x]=1;
		start[x+1]=start[x]+size[x];
	}		 
	x++;
	if(start[x]<lenght) goto here;
	//шаг 2;
	j=x;  
	for(i=0;i<j-2;i++)																	//выбор подмассивов для слияний
	{
		if(!((size[i]>size[i+1]+size[i+2])&&(size[i+1]>size[i+2])))
		{
			if((size[i]>size[i+2])||(size[i]==size[i+2]))
			{
				if(size[i+1]>size[i+2])
				{
					less=i+2;
					bigger=i+1;
				}
				else
				{
					bigger=i+2;
					less=i+1;
				}
				unite(start, run, less, bigger);
				size[i+1]=size[bigger]+size[less];
				for(k=i+2;k<j;k++)
				{
					start[k]=start[k+1];
				}
				for(k=i+2;k<j;k++)
				{
					size[k]=size[k+1];
				} 
			}
			else
			{
				if(size[i+1]<size[i])
				{
					less=i+1;
					bigger=i;
				}
				else
				{
					less=i;
					bigger=i+1;
				}
				unite(start, run, less, bigger);
				size[i+1]=size[bigger]+size[less];
				for(k=i+2;k<j;k++)
				{
					start[k]=start[k+1];	
				}
				for(k=i;k<j;k++)
				{
					size[k]=size[k+1];
				}	
			} 	
			j--;
		}
	}
	x=j;
	for(i=x-2;i>-1;i--)
	{
		if(size[i]>size[i+1])
		{
			bigger=i;
			less=i+1;
		}
		else
		{
			less=i;
			bigger=i+1;
		}
		unite(start, run, less, bigger);
		size[i]=size[i]+size[i+1];
		x--;
	}
	cout<<"Отсортированный массив: "<<endl;					//вывод отсортированного массива
	for(i=0;i<lenght;i++)
	{
		cout << run[i] << " ";
	}
	return 0;
}
