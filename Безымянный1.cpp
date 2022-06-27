#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
 
/*
��������� ��������� �����, ������� ����� ������������ ��� ���������� ����� � ������
*/
struct edge{
    char x, y; //�������
    edge(){}
    edge(char a, char b)
	{
        x = a;
        y = b;
    }
};
 
int main() 
{
    int n, m;
    cin >> n >> m;
    vector <edge> graph (m); //����� ��������� �����
    vector <edge> tree; //����� ������
    vector <int> variety (n); //��������� ������
    
    /*
    variety[n] = m - ������� n ����������� ��������� m.
    ��������� ���� ���������� ��� ������ ������� ���� ���������
    */
    for (int i = 0; i < n; i++)
	{
        variety[i] = i;
    }
    
    /*
    ��������� ����� ��������� ����� ���������� �� ������������ �����
    */
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[i].x = a;
        graph[i].y = b;
    }
    /*
    ��������� ������� ������� �����. 
    ���� ������� �� ����������� ������ � ���� �� ���������, 
    �� ����� ����� ��������� � ���� ������, � ������� �������� � ���� ���������
    */
    for (int i = 0; i < m; i++)
	{
        int a = graph[i].x;
        int b = graph[i].y;
        if (variety[a] != variety[b])
		{
            tree.push_back(graph[i]);
            int old_variety = variety[b], new_variety = variety[a];
            for (int j = 0; j < n; j++)
			{
                if (variety[j] == old_variety){
                    variety[j] = new_variety;
                }
            }
        }
    }
 
    
    for(int i = 0; i < n - 1; i++)
	{ //�� �������� ���������� ������, ��� �������� n-1 �����
        cout << tree[i].x << " " << tree[i].y;
        if (i != n-2){
            cout << endl;
        }
    }
    return 0;
}
