#include <stdio.h>
#include <conio.h>
#include <windows.h>

int n = 0;
int i = 0;
int j = 0;

int changeminus(double a[], int n) {
int i, s = 0;
for(i = 0; i < n; i++)
{
   if (a[i] < 0)
    {
        a[i] = -1;
    }
}
return a[i];
}

int changeplus(double a[], int n) {
int i, s = 0;
for(i = 0; i < n; i++)
{
    if (a[i] > 0)
    {
        a[i] = 1;
    }
}
return a[i];
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
printf("Розмір масиву = ");
    scanf("%d", &n);
    
double a[n];
for(int i = 0; i < n; i++)
{
    printf("a[%d]=", i);
    scanf("%lf", &a[i]);
}

changeminus(a, n);
changeplus(a, n);

for (int i=0; i<n; i++)
    printf("\r\na[%d]=%g\t", i, a[i]);

// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}