/**
* @file SP.c
* @author Первый Е.Е., гр.515-В
* @date 29 июня
* @brief Летняя практика
*
* Указание минимального пути от одной ячейки до другой для шахматного короля
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//константный массив описаний направлений
const char directions[10][36] = {"","Влево вниз","Вниз","Вправо вниз","Влево","Вы находитесь на клетке назначения","Вправо","Влево вверх","Вверх","Вверх вправо"};
//константный массив буквенных обозначений ячеек доски
const char lit[8] = {'A','B','C','D','E','F','G','H'};


/**
* Получение пути от начальной ячейки до итоговой
*
* @param date kx,ky,dx,dy (координаты начальной позиции короля (k) и позиции назначения (d))
*/
void getting_way(int,int,int,int);

char way[20];
int main()
{
	setlocale(LC_ALL, "rus");
	enter:
	int kx, dx, ky, dy;
	
	printf("Введите начальную позицию короля: ");
	kx=getchar();
	ky = getchar();
	getchar();
	printf("Введите клетку назначения короля: ");
	dx = getchar();
	dy = getchar();
	getchar();
	
	int check=0;
	for (int i = 0; i < 8; i++)
	{
		if (kx == lit[i]) { kx = i; check++; }

		if (dx == lit[i]) { dx = i; check++; }
	}
	ky -= '0';
	dy -= '0';
	
	
	if (ky < 1 || ky>8 || dy < 1 || dy>8 || check != 2)
	{
		printf("\nДанные были введены неверно, попробуйте снова\n");
		goto enter;
	}
	

	
	getting_way(kx, ky, dx, dy);
	printf("Результат: %i ход(а/ов)\n", strlen(way) - 2);
	for (int i = 1; i < strnlen_s(way, 20); i++)
	{
		int a = way[i] - '0';
		
		for (int j = 1; j < 10; j++)
		{
			if (a == j) {
				printf("%s\n", directions[j]);
				break;
			}
		}
	}
}

void getting_way(int x, int y, int dx, int dy)
{
	strcpy_s(way,"0");

	for (;;)
	{
		if (x == dx && y == dy) { 
			strcat_s(way, "5");
			return;
		}
		//движение вверх и вниз по доске
		if (x == dx) {
			if (y < dy)
			{
				y++;
				strcat_s(way, "8");
			}
			else if(y>dy)
			{
				y--;
				strcat_s(way, "2");
			}
		}
		//движение влево и вправо по доске
		if (y == dy) {
			if (x < dx)
			{
				x++;
				strcat_s(way, "6");
			}
			else if(x>dx)
			{
				x--;
				strcat_s(way, "4");
			}
		}

		//движение по диагоналям
		if (y < dy && x < dx)
		{
			x++;
			y++;
			strcat_s(way,"9");
		}
		if (y > dy && x > dx)
		{
			x--;
			y--;
			strcat_s(way, "1");
		}
		if (y > dy && x < dx)
		{
			y--;
			x++;
			strcat_s(way, "3");
		}
		if (y<dy && x>dx)
		{
			y++;
			x--;
			strcat_s(way, "7");
		}
	}
}
