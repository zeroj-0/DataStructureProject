#include <stdio.h>
#define MAX_TERMS 101
#define MAX_ROW_COL 6
#define MAX_COL 7

typedef struct {
   int row;
   int col;
   int value;
} term;

term a[MAX_TERMS];
term b[MAX_TERMS];
//희소행렬 : 0이 많이 포함된 행렬
int num2darray[MAX_ROW_COL][MAX_ROW_COL] = {
{15, 0, 0, 22, 0, -15},
{0, 11, 3, 0, 0, 0},
{0, 0, 0, -6, 0, 0},
{0, 0, 0, 0, 0, 0},
{91, 0, 0, 0, 0, 0},
{0, 0, 28, 0, 0, 0}
};

void convertMatrix(int max_row, int max_col) {
   int value = 0;
   int aIdx = 1;
   a[0].row = max_row;
   a[0].col = max_col;

   for (int row = 0; row < max_row; row++) {
      for (int col = 0; col < max_col; col++) {
         if (num2darray[row][col] != 0) {
            a[aIdx].row = row;
            a[aIdx].col = col;
            a[aIdx].value = num2darray[row][col];
            aIdx++;
            value++;
         }
      }
   }
   a[0].value = value;
}
//전치함수
void transpose(term a[], term b[]) {
   int count, i, j, currentb;
   count = a[0].value;   // a에서 0이 아닌 원소의 수
   b[0].row = a[0].col;// b의 행의 수 = a의 열의 수
   b[0].col = a[0].row; // b의 열의 수 = a의 행의 수
   b[0].value = count;  // 0이 아닌 원소 수는 a와 동일
   if (count > 0) {   // a가 empty matrix가 아니라면…
      currentb = 1;// 새로운 원소가 b에 저장될 위치.
      for (i = 0; i < a[0].col; i++) {
         // a의 열 순서로 전치 연산 실행 (i: 현재 열)
         for (j = 1; j <= count; j++) {
            //  a에서 현재 열을 찾자. (a는 행순서로 저장)
            if (a[j].col == i) {
               //  현재 열의 원소 발견. b에 추가하자.
               b[currentb].row = a[j].col;
               b[currentb].col = a[j].row;
               b[currentb].value = a[j].value;
               currentb++;// b의 저장될 위치를 1 증가
            }
         }
      }
   }
}
//전치함수 2
void fast_transpose(term a[], term b[]) {
   //   a는 입력 행렬, b는 출력 행렬. b = aT
   int row_terms[MAX_TERMS];// a의 열의 원소 수 저장
   int starting_pos[MAX_TERMS];// 각 열의 시작위치 저장
   int i, j;
   int num_col = a[0].col;
   int num_terms = a[0].value;
   b[0].row = num_col;   b[0].col = a[0].row;
   b[0].value = num_terms;
   if (num_terms > 0) {
      //출력
      for (i = 0; i <= a[0].value; i++) printf("a[%d] -> r[%d]c[%d]v[%d]\n", i, a[i].row, a[i].col, a[i].value);
      for (i = 0; i < num_col; i++) row_terms[i] = 0;

      // 출력
      for (i = 0; i < num_col; i++) printf("rt[%d] -> [%d]\n", i, row_terms[i]);
      for (i = 1; i <= num_terms; i++) row_terms[a[i].col]++;

      //출력
      for (i = 0; i < num_col; i++) printf("rt[%d] -> [%d]\n", i, row_terms[i]);
      starting_pos[0] = 1;

      //출력
      for (i = 1; i < num_col; i++) starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
      for (i = 0; i < num_col; i++) printf("sp[%d] -> [%d]\n", i, starting_pos[i]);
      for (i = 1; i <= num_terms; i++) {
         j = starting_pos[a[i].col]++;
         b[j].row = a[i].col;  b[j].col = a[i].row;
         b[j].value = a[i].value;
      }
   }
}

int main(void) {
   convertMatrix(MAX_ROW_COL, MAX_ROW_COL);
   transpose(a, b);
   fast_transpose(a, b);
    return 0;
}
