#include "classes.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define M_PI        3.14159265358979323846

Conus::Conus()
{
	R = 1;
	h = 1;
}

void Conus::EnterParam()
{
	int er;
	do
	{
		printf("������� ������ ������� ���������: ");
		er = scanf("%d", &R);
		if (R <= 0 || er == 0)
			printf("������!!! ��������� ����! \n");
		fflush(stdin);
	} while (R <= 0 || er == 0);
	do
	{
		printf("������� ������ �� �������� �� ������� ���������: ");
		er = scanf("%d", &h);
		if (h <= 0 || er == 0)
			printf("������!!! ��������� ����! \n");
		fflush(stdin);
	} while (h <= 0 || er == 0);
}

void Conus::DisplayParam()
{
	printf("������: %d\n������ ������� ���������: %d \n", h, R);
}

double Conus::Area()
{
	return M_PI*R*R*h*pow(3,-1);
}

SlicedConus::SlicedConus()
{
	r = 1;
}

void SlicedConus::EnterParam()
{
	Conus::EnterParam();
	int er;
	do
	{
		printf("������ �������� ���������:");
		er = scanf("%d", &r);
		if (r <= 0 || er == 0)
			printf("������!!! ��������� ����! \n");
		fflush(stdin);
	} while (r <= 0 || er == 0);

}

void SlicedConus::DisplayParam()
{
	Conus::DisplayParam();
	printf("������ �������� ���������: %d\n", r);
}

double SlicedConus::Area()
{
	return M_PI*pow(3, -1)*h*(R*R+R*r+r*r);
}
