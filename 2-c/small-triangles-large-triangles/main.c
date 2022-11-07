#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
   int a;
   int b;
   int c;
};

typedef struct triangle triangle;

long int perimeter(triangle *tr)
{
   return (tr->a + tr->b + tr->c);
}

long int area(triangle *tr)
{
   long int p = perimeter(tr);
   return p * (p - 2 * tr->a) * (p - 2 * tr->b) * (p - 2 * tr->c);
}

int cmpfunc(const void *a, const void *b)
{
   triangle first = *(const triangle *)a;
   triangle second = *(const triangle *)b;
   return area(&first) - area(&second);
}

void sort_by_area(triangle *tr, int n)
{
   /**
    * Sort an array a of the length n
    */
   qsort(tr, n, sizeof(triangle), cmpfunc);
   // for (int i = 0; i < n; i++){
   //     printf("%d %d %d\n", tr->a, tr->b, tr->c);
   //     tr++;
   // }
}

int main()
{
   int n;
   scanf("%d", &n);
   triangle *tr = malloc(n * sizeof(triangle));
   for (int i = 0; i < n; i++)
   {
      scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
   }
   sort_by_area(tr, n);
   for (int i = 0; i < n; i++)
   {
      printf("%03d %03d %03d %ld\n", tr[i].a, tr[i].b, tr[i].c, area(&tr[i]));
   }
   return 0;
}