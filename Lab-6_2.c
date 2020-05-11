#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
const int n=10000, Low=-100, High=100; 
int k = 0;
int i = 0;
int j = 0;


int men7(int b[], int c) {
for (int i=0; i<n; i++)
{
    if (b[i] < 7)
    {
        k++;
    }
}return printf("\r\nКількість елементів масиву, менших за число сім: %d\r\n", k);
}

int nol(int a[], int c) {
for (int i=0; i<n; i++)
{
    if (a[i] == 0)
    {
        j++;
    }
}return printf("\r\nКількість нулів в масиві: %d\r\n", j);
}


int chcp, chcpOut = 0;
int main(void)
{
// память chcp
    chcp = GetConsoleCP();
    chcpOut = GetConsoleOutputCP();

// UTF-8
    SetConsoleCP(65001);                
    SetConsoleOutputCP(65001);
//
int a[n];
srand(time(0));
for (int i=0; i<n; i++)
a[i]=Low + rand() % (High - Low + 1);


printf("\r\nКількість елементів в масиві: [%d]\r\n\n", n);

men7(a,n);

nol(a,n);


// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}