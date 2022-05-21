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
		printf("Введите радиус нижнего основания: ");
		er = scanf("%d", &R);
		if (R <= 0 || er == 0)
			printf("Ошибка!!! Повторите ввод! \n");
		fflush(stdin);
	} while (R <= 0 || er == 0);
	do
	{
		printf("Введите высоту от верхнего до нижнего основания: ");
		er = scanf("%d", &h);
		if (h <= 0 || er == 0)
			printf("Ошибка!!! Повторите ввод! \n");
		fflush(stdin);
	} while (h <= 0 || er == 0);
}

void Conus::DisplayParam()
{
	printf("Высота: %d\nРадиус нижнего основания: %d \n", h, R);
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
		printf("Радиус верхнего основания:");
		er = scanf("%d", &r);
		if (r <= 0 || er == 0)
			printf("Ошибка!!! Повторите ввод! \n");
		fflush(stdin);
	} while (r <= 0 || er == 0);

}

void SlicedConus::DisplayParam()
{
	Conus::DisplayParam();
	printf("Радиус верхнего основания: %d\n", r);
}

double SlicedConus::Area()
{
	return M_PI*pow(3, -1)*h*(R*R+R*r+r*r);
}
