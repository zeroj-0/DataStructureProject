#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 6
int linearSearch(int list[], int searchNum);
int main() {
   int searchNum = 5;
   int list[MAX_SIZE] = { 6, 8, 3, 5, 2, 1 };
   int idx = 0;
   idx = linearSearch(list, searchNum);
   if (idx == 1) printf("%d번째 인덱스에 존재합니다.", idx);
   else printf("찾고자 하는 숫자가 존재 하지 않습니다,");
}
int linearSearch(int list[], int searchNum) {
   for (int i = 0; i < MAX_SIZE; i++)
       //i 자체가 비교횟수
      if (list[i] == searchNum) return i;
   return -1;
}
