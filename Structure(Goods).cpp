
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <locale.h>
using namespace std;


const int SIZE = 100;
struct inv_type {
	char item[40]; // ������������ ������
	double cost; // ���������
	double retail; // ��������� ����
	int on_hand; // ��������� � ������� ����������
	int lead_time; // ����� ���� �� ���������� �������
} invtry[SIZE];

void enter(),
init_list(),
display();
void update(),
input(int i);
int menu();

int main()
{
	setlocale(LC_ALL, "Ru");
	char choice;
	init_list();
	for(;;) {
		choice = menu();
		switch (choice) {
		case 'e': enter();
			break;
		case 'd': display();
			break;
		case 'u': update();
			break;
		case 'q': return 0;
		}
	}
}

void init_list()
{
	int t;
	// ��� ������� ����� �������� ������ ���.
	for (t = 0; t < SIZE; t++) 
		*invtry[t].item = '\0';
}



//���� ��������� � ����������� ���������.
void enter()
{
	int i;
	// ������� ������ ��������� ���������.
	for (i = 0; i < SIZE; i++)
		if (!*invtry[i].item) break;
	// ���� ������ �����, �������� i ����� ����� SIZE.
	if (i == SIZE) {
		cout << "������ �����.\n";
		return;
	}
	input(i);
}


// ���� ����������.
void input(int i)
{
	cout << "�����: ";
	cin >> invtry[i].item;
	cout << "���������: ";
	cin >> invtry[i].cost;
	cout << "��������� ����: ";
	cin >> invtry[i].retail;
	cout << "� �������: ";
	cin >> invtry[i].on_hand;
	cout << "����� �� ���������� ������� (� ����): ";
	cin >> invtry[i].lead_time;
}
// ����������� ������������� ��������.
void update()
{
	int i;
	char name[80];
	cout << "������� ������������ ������: ";
	cin >> name;
	for (i = 0; i < SIZE; i++)
		if (!strcmp(name, invtry[i].item)) break;
	if (i == SIZE) {
		cout << "����� �� ������.\n";
		return;
	}
	cout << "������� ����� ����������.\n";
	input(i);
}

void display()
{
	int t;
	for (t = 0; t < SIZE; t++) {
		if (*invtry[t].item) {
			cout << invtry[t].item << '\n';
			cout << "���������: $" << invtry[t].cost;
			cout << "\nB �������: $";
			cout << invtry[t].retail << '\n';
			cout << "� �������: " << invtry[t].on_hand;
			cout << "\n�� ���������� ��������: ";
			cout << invtry[t].lead_time << " ����\n\n";
		}
	}
}

