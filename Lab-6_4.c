#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
const int Low=-100, High=100;

int mas_a_rand (int n, int m, int a[][m])
{
    srand(time(0));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            a[i][j]=Low + rand() % (High - Low + 1);
        }
    }
}

int mas_v_scanf (int size, int v[])
{
    int s = 0;
    printf("\r\nВведіть масив цілих чисел вектора:\r\n");
        do
        {
            if (s<size)
                scanf ("%d", &v[s]);
            s++;
        }
        while (s<size);
}

int convert_a_t (int n, int m, int temp[], int a[][m])
{
int t =0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            temp[t]=a[i][j];
            t++;
        }
    }
}

int sort_temp (int p, int temp[])
{
    int tmp=0;
    for (int i=0; i<p-1; i++)
    {
        for (int j=0; j<p-i-1; j++)
        
            if (temp[j] > temp[j+1])
            {
                tmp=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=tmp;
            }
    }
}

int find (int size, int p, int temp[], int v[])
{
    int b=0;
    int our_min = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < size; j++)
            if(temp[i]==v[j]) {b=1;break;}
            if(b==0) {our_min=temp[i];break;}
    }
system("cls");
if (b==0) printf("   Мінімальний елемент матриці,\n   який не входить до складу\n   елементів вектора: %d\n", our_min);
    else printf("Такі елементи відсутні\n");

}

int printf_a_v (int size, int n, int m, int v[], int a[][m])
{
    printf("\r\n\n");
    printf("Вектор:\r\n");
        for (int i = 0; i < size; i++)
        {
            printf("a[%d]=%d\t", i, v[i]); printf("\n");
        }

    printf("\r\n\n");
    printf("Матриця:\r\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            printf("a[%d][%d]=%d\t", i, j, a[i][j]); printf("\n");
        }
}

int i, j = 0;
int n = 0;
int m = 0;
int size = 0;
int p = 0;

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

printf("\r\nВведіть: ");

    printf("\r\nКількість рядків матриці: ");
        scanf ("%d", &n);

    printf("Кількість стовпців матриці: ");
        scanf ("%d", &m);

printf("\r\nРозмір вектора = ");
    scanf ("%d", &size);

////////////
int a[n][m];
int v[size];
////////////
mas_v_scanf (size, v);
////////////
p=n*m;
int temp[p];
////////////
mas_a_rand (n, m, a);
convert_a_t (n, m, temp, a);
sort_temp (p, temp);
find (size, p, temp, v);
printf_a_v (size, n, m, v, a);

// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}