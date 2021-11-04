#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define compare(x, y) (((x) < (y)) ? -1 : ((x)==(y))? 0 : 1)
#define MAX_SIZE 500001

int binsearch(int list[], int searchnum, int left, int right);

int main() {
   int list[MAX_SIZE];
   int n = 0;
   int result = 0;
   int searchNum = 0;
   clock_t start, stop;
   double duration;
   printf("Enter the number of numbers to generator : ");
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      list[i] = i+1;
   }
   srand((unsigned int) time(NULL));
   searchNum = rand() % n;

   start = clock();
   result = binsearch(list, searchNum, list[0], list[n - 1]);
   stop = clock();

   duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
   printf("%d를 찾은 횟수 : %d\t실행시간 : %.8f", searchNum, result,duration);
}
int binsearch(int list[], int searchnum, int left, int right) {
   int middle;
   int count = 0;
   while (left <= right) {
      count++;
      middle = (left + right) / 2;
      switch (compare(list[middle], searchnum)) {
      case -1:
         // searchnum이 list[middle]보다 큰 경우
         left = middle + 1;
         break;
      case 0:
         // searchnum이 list[middle]과 같은 경우
         return count;
      case 1:
         // searchnum이 list[middle]보다 작은 경우
         right = middle - 1;
      }
   }
   return -1;
}
