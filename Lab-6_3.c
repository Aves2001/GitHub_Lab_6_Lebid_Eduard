#include <stdio.h>
#include <conio.h>
#include <windows.h>

int n = 0;
int min = 0;
int mini = 0;
int temp =0;
int i = 0;
int j = 0;

int focuspocus(int a[], int n) {
printf("\r\nПерший елемент: a[%d]=%d буде замінено містцями з",0, a[0]);

min = a[0];
for (i=2; i<n; i++){
    if (i % 2 == 0){
        if (min>a[i])
            min = a[i]; // запам'ятати мінімальне значення
            mini = i;
}
                temp = a[0];
                a[0] = a[i];
                a[i] = temp;
}

printf("\r\nнайменшим парним елементом: a[%d]=%d\r\n",mini, min);
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
        printf("\r\n");

int a[n];
    for(int i = 0; i < n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }

    focuspocus (a, n);


printf("\r\n\nРезультат:\r\n");

for (int i=0; i<n; i++)
    printf("\r\na[%d]=%d\t", i, a[i]);

// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}