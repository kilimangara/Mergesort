// Merge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
void Slivaem(int *a, int first, double middle, int last) {
  int pos1=first;
 
  int pos2=middle+1;
 
  int pos3=0;  
 
  int *temp = new int[last-first+1];
 
  // идет слияние, пока есть хоть один элемент в каждой последовательности
  while (pos1 <= middle && pos2 <= last) {
    if (a[pos1] < a[pos2])
      temp[pos3++] = a[pos1++];
    else
      temp[pos3++] = a[pos2++];
  }
 
  // одна последовательность закончилась - 
  // копировать остаток другой в конец буфера 
  while (pos2 <= last)   // пока вторая последовательность непуста 
    temp[pos3++] = a[pos2++];
  while (pos1 <= middle)  // пока первая последовательность непуста
    temp[pos3++] = a[pos1++];
 
  for (pos3 = 0; pos3 < last-first+1; pos3++)
    a[first+pos3] = temp[pos3];
 
  delete []temp;
}
void SortSlivaem(int *mas, int first, int last)
{
    double middle = 0;
if (first<last)
{
    middle = (first + last)/2;
SortSlivaem(mas, first, (first+last)/2); //сортируем левую часть
SortSlivaem(mas, (first+last)/2+1, last); //сортируем правую часть
Slivaem(mas, first, middle, last); //сливаем две части
}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5]={0, 8, 1, 4, 5};
	SortSlivaem(a,0,4);
	for(int i(0);i<5;++i)
	{
		cout<<"a["<<i<<"]="<<a[i]<<endl;
	}
	getchar();
	return 0;
}

