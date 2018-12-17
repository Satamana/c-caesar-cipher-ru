#include<iostream>
#include<windows.h>
using namespace std;
void locker(FILE *from, FILE *to, int k)
{
	char ch;
	char *ind;
	char Ru[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char ru[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	while (!feof(from))
	{
		ch = fgetc(from);
		if (ch >= 65 && ch <= 90) putc(char(ch = ((ch + k % 26 > 90) ? ch - 26 : ch) + k % 26), to);
		else if (ch >= 97 && ch <= 122) putc(char(ch = ((ch + k % 26 > 122) ? ch - 26 : ch) + k % 26), to);
		else if ((ind = strchr(Ru, ch)) != 0) putc(*(ind = ((ind + k % 33 > Ru + 32) ? ind - 33 : ind) + k % 33), to);
		else if ((ind = strchr(ru, ch)) != 0) putc(*(ind = ((ind + k % 33 > ru + 32) ? ind - 33 : ind) + k % 33), to);
		else putc(ch, to);
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char *filefrom = "first.txt";
	char *fileto = "second.txt";
	FILE *from = fopen(filefrom, "r");
	FILE *to = fopen(fileto, "w");
	if (from && to)
	{
		locker(from, to, 3);
		fclose(from);
		fclose(to);
	}
	else cout << "Ошибка в открытии " << ((to) ? filefrom : fileto) << endl;
}