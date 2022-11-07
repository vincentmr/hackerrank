#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

int lexicographic_sort(const char *a, const char *b)
{
   int na = strlen(a);
   int nb = strlen(b);
   int i = 0;
   while (*a == *b && i < na && i < nb)
   {
      a++;
      b++;
      i++;
   }
   if (*a < *b)
   {
      return 0;
   }
   if (*a > *b)
   {
      return 1;
   }
   if (na < nb)
   {
      return 0;
   }
   return 1;
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
   return (lexicographic_sort(a, b) + 1) % 2;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
   int na = strlen(a);
   int nb = strlen(b);
   bool hasa[26];
   bool hasb[26];
   int idx;
   for (int i = 0; i < 26; i++)
   {
      hasa[i] = false;
      hasb[i] = false;
   }
   for (int i = 0; i < na; i++)
   {
      idx = (int)(a[i]) - 97;
      hasa[idx] = true;
   }
   for (int i = 0; i < nb; i++)
   {
      idx = (int)(b[i]) - 97;
      hasb[idx] = true;
   }
   int diffa = 0, diffb = 0;
   for (int i = 0; i < 26; i++)
   {
      if (hasa[i])
      {
         diffa += 1;
      }
      if (hasb[i])
      {
         diffb += 1;
      }
   }
   if (diffa < diffb)
   {
      return 0;
   }
   if (diffa > diffb)
   {
      return 1;
   }
   return lexicographic_sort(a, b);
}

int sort_by_length(const char *a, const char *b)
{
   int na = strlen(a);
   int nb = strlen(b);
   if (na < nb)
   {
      return 0;
   }
   if (na > nb)
   {
      return 1;
   }
   return lexicographic_sort(a, b);
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
   // qsort(arr, len, 1024 * sizeof(char), cmp_func);
}

int main()
{
   int n;
   scanf("%d", &n);

   char **arr;
   arr = (char **)malloc(n * sizeof(char *));

   for (int i = 0; i < n; i++)
   {
      *(arr + i) = malloc(1024 * sizeof(char));
      scanf("%s", *(arr + i));
      *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
   }

   // printf("%s\n", arr[0]);
   // printf("%s\n", arr[1]);
   // // n = lexicographic_sort(arr[0], arr[1]);
   // // printf("%d\n", n);
   // // n = lexicographic_sort_reverse(arr[0], arr[1]);
   // // printf("%d\n", n);
   // n = sort_by_number_of_distinct_characters(arr[0], arr[1]);
   // printf("%d\n", n);

   string_sort(arr, n, lexicographic_sort);
   for (int i = 0; i < n; i++)
      printf("%s\n", arr[i]);
   printf("\n");

   string_sort(arr, n, lexicographic_sort_reverse);
   for (int i = 0; i < n; i++)
      printf("%s\n", arr[i]);
   printf("\n");

   string_sort(arr, n, sort_by_length);
   for (int i = 0; i < n; i++)
      printf("%s\n", arr[i]);
   printf("\n");

   string_sort(arr, n, sort_by_number_of_distinct_characters);
   for (int i = 0; i < n; i++)
      printf("%s\n", arr[i]);
   printf("\n");
}