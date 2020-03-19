#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
using namespace std;

struct Node {
	char inf[8];
	Node* next;
	Node* prev;
};


struct List {
	Node* head = NULL;
	Node* tail = NULL;
	void creat(int n) {
		Node* cur = new Node;
		cout << "Заполните дизъюнкции переменными a,b,c,d. !-перед переменной означает НЕ "<<endl;
		cin >> cur->inf;
		cur->prev = NULL;
		cur->next = NULL;
		head = cur;
		tail = cur;
		for (int i = 1; i < n; i++)
		{
			Node* cur = new Node;
			cout << "Следующая ";
			cin >> cur->inf;
			cur->prev = tail;
			tail->next = cur;
			tail = cur;
			tail->next = NULL;
		}
	};
	int otvet(int a, int b, int c, int d) {
		int aa, bb, cc, dd;
		int otv = 1;
		int temp;
		Node* cur = head;
		while (cur) {
			aa = 0, bb = 0, cc = 0, dd = 0;
			if (strstr(cur->inf, "!a"))
			{
				aa = 1;
				if (a == 0) { a = 1; }
				else(a = 0);
			}
			else if (strstr(cur->inf, "a")) { aa = 1; }
			if (strstr(cur->inf, "!b"))
			{
				bb = 1;
				if (b == 0) { b = 1; }
				else(b = 0);
			}
			else if (strstr(cur->inf, "b")) { bb = 1; }
			if (strstr(cur->inf, "!c"))
			{
				cc = 1;
				if (c == 0) { c = 1; }
				else(c = 0);
			}
			else if (strstr(cur->inf, "c")) { cc = 1; }
			if (strstr(cur->inf, "!d"))
			{
				dd = 1;
				if (d == 0) { d = 1; }
				else(d = 0);
			}
			else if (strstr(cur->inf, "dd")) { dd = 1; }
			if ((a == 1 && aa==1) || ( b == 1 && bb==1) || (c == 1 && cc==1)|| (d == 1 && dd==1)) 
			{ 
				temp = 1;
			}
			else {
				temp = 0;
			}
			if (temp == 0) { otv = 0; }
			cur = cur->next;
		}
		return otv;
	}
};
  


	int main()
	{
		List knf;
		int n;
		cout << "Количество конъюнкций: " << endl;
		cin >> n;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		knf.creat(n);
		for (int a = 0; a <= 1; a++) {
			for (int b = 0; b <= 1; b++) {
				for (int c = 0; c <= 1; c++) {
					for (int d = 0; d <= 1; d++)
					{
						cout << a << " " << b << " " << c << " " << d << " = " << knf.otvet(a, b, c, d) << endl;
					}
				}
			}
		}
		return 0;
	}