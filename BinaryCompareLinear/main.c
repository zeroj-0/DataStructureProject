#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 100001
#define compare(x, y) (((x) < (y)) ? -1 : ((x)==(y))? 0 : 1)

//어떤 것이 더 빨리 찾는가
int linearSearch(int list[], int searchNum);
int binsearch(int list[], int searchnum, int left, int right);

int main(void) {
    //이진탐색용
   int list[MAX_SIZE];
    //선형탐색용
   int list2[MAX_SIZE];
   int n = 0;
   int result = 0;
   int result2 = 0;
   int searchNum = 0;
    //원소의 갯수(배열의 크기)를 얼마나 받을 것인가
   printf("Enter the number of numbers to generator : ");
   scanf("%d", &n);
   for (int i = 0; i < n; i++) {
      list[i] = i + 1;
   }
    srand((unsigned int) time(NULL));
   for (int i = 0; i < n; i++) {
      list2[i] = rand() % n;
   }

   srand((unsigned int) time(NULL));
   searchNum = list2[rand() % n];
   result = binsearch(list, searchNum, list[0], list[n - 1]);
   result2 = linearSearch(list2, searchNum);
   printf("이진탐색 : %d를 찾은 횟수 : %d\n", searchNum, result);
   printf("선형탐색 : %d를 찾은 횟수 : %d\n", searchNum, result2);
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

int linearSearch(int list[], int searchNum) {
   for (int i = 0; i < MAX_SIZE; i++)
      if (list[i] == searchNum) return i;
   return -1;
}
