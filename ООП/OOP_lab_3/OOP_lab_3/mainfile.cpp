#include "classes.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{
	int n=0;
	Conus el;
	SlicedConus colel;
	Conus *pel=&el; //указатель нужен для реализации полиморфизма
	int key1, key2;
	setlocale(0, "RUS"); // обеспесиваем вывод в консольное окно символов кириллицы
	do //выбирвем вид эллипса
	{
		printf("\n1 - обычный конус\n");
		printf("2 - усеченный конус\n");
		printf("ESC - выход\n");
		printf("Ваш выбор: \n");
		if ( n++ > 0) _getch();
		key1 = _getch();
		switch (key1)
		{
		case '1':
			pel = &el;
			break;
		case '2':
			pel = &colel;
			break;
		}
		if (key1 != 27)
		{
			do //выбираем действие для выбранного типа эллипса
			{
				printf("\n1 - ввод параметров\n");
				printf("2 - вывод параметров\n");
				printf("3 - посчитать обьем\n");
				printf("ESC - выход\n");
				printf("Ваш выбор: \n");
				_getch();
				key2 = _getch();
				switch (key2)
				{
				case '1': pel->EnterParam(); break;
				case '2': pel->DisplayParam(); break;
				case '3': printf("Площадь равна: %.2lf\n", pel->Area());
					break;
				}
			} while (key2 != 27);
		}
	} while (key1 != 27);
	return 0;
}
