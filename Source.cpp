#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define size 11

using namespace std;
string bin(int c) {
	string binn;
	for (int h = 0; h < 9; h++) {
		binn += char('0' + c % 2);
		c /= 2;
	}
	return binn;
}
int main()
{
    char tmp[size][size], scr[size][size];


   int i, chislo, j, count = 0, q = 1, w = 1, index = 0;


    for (j = 0; j < size; j++) for (i = 0; i < size; i++) tmp[i][j] = '0';
	for (j = 0; j < size; j++) for (i = 0; i < size; i++) scr[i][j] = '0';


   for (int p = 0; p < 3; p++) {
		for (int k = 1; k < 4; k++) {
			char c;
			cin >> chislo >> c;
			index = 8;
			string binn = bin(chislo);
			for (int i = q; i <= q + 2; i++) {

				for (int j = w; j <= w + 2; j++) {

					scr[i][j] = binn[index--];
				}
			}
			w += 3;
		}
		q += 3;
		w = 1;
	}

	int d;
	d = 1;
	
	for (int v = 1; v <= d; v++)
	{
       for (i = 1; i < size - 1; i++) for (j = 1; j < size - 1; j++) tmp[i][j] = scr[i][j];
		for (i = 1; i < size - 1; i++)
		{
			for (j = 1; j < size - 1; j++)
			{
				if (tmp[i][j] == '0')
				{
					if (tmp[i - 1][j - 1] == '1') count++;
					if (tmp[i][j - 1] == '1') count++;
					if (tmp[i + 1][j - 1] == '1') count++;
					if (tmp[i + 1][j] == '1') count++;
					if (tmp[i + 1][j + 1] == '1') count++;
					if (tmp[i][j + 1] == '1') count++;
					if (tmp[i - 1][j + 1] == '1') count++;
					if (tmp[i - 1][j] == '1') count++;
					if (count == 3) scr[i][j] = '1';
					count = 0;
				}
				else
				{
					if (tmp[i - 1][j - 1] == '1') count++;
					if (tmp[i][j - 1] == '1') count++;
					if (tmp[i + 1][j - 1] == '1') count++;
					if (tmp[i + 1][j] == '1') count++;
					if (tmp[i + 1][j + 1] == '1') count++;
					if (tmp[i][j + 1] == '1') count++;
					if (tmp[i - 1][j + 1] == '1') count++;
					if (tmp[i - 1][j] == '1') count++;
					if ((count == 2) || (count == 3))
					{
						scr[i][j] = '1';
						count = 0;
					}
					else
					{
						scr[i][j] = '0';
						count = 0;
					}
				}
			}
		}
		
	}
	int otvet[9];
	int degree = 8, ind = 0;
	int otvet_chislo = 0;
	q = 1;
	for (int p = 0; p < 3; p++) {
		for (int k = 1; k < 4; k++) {

			for (int i = q; i <= q + 2; i++) {

				for (int j = w; j <= w + 2; j++) {

					otvet_chislo += int(scr[i][j] - '0') * pow(2, degree--);
				}
			}
			w += 3;
			degree = 8;
			otvet[ind++] = otvet_chislo;
			otvet_chislo = 0;
		}
		q += 3;
		w = 1;
	}
	for (i = 0; i < 9; i++)
		cout << otvet[i] << " ";
	system("pause");
	return 0;
}