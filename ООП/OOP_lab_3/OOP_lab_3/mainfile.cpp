#include "classes.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main()
{
	int n=0;
	Conus el;
	SlicedConus colel;
	Conus *pel=&el; //��������� ����� ��� ���������� ������������
	int key1, key2;
	setlocale(0, "RUS"); // ������������ ����� � ���������� ���� �������� ���������
	do //�������� ��� �������
	{
		printf("\n1 - ������� �����\n");
		printf("2 - ��������� �����\n");
		printf("ESC - �����\n");
		printf("��� �����: \n");
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
			do //�������� �������� ��� ���������� ���� �������
			{
				printf("\n1 - ���� ����������\n");
				printf("2 - ����� ����������\n");
				printf("3 - ��������� �����\n");
				printf("ESC - �����\n");
				printf("��� �����: \n");
				_getch();
				key2 = _getch();
				switch (key2)
				{
				case '1': pel->EnterParam(); break;
				case '2': pel->DisplayParam(); break;
				case '3': printf("������� �����: %.2lf\n", pel->Area());
					break;
				}
			} while (key2 != 27);
		}
	} while (key1 != 27);
	return 0;
}
