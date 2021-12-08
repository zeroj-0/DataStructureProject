#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
       
    printf("첫번째 문자열 입력>");
    gets(str1);

//    printf("두번째 문자열 입력>");
//    gets(str2);

//    strcat(str1, str2);
//    printf("%s", str1);

//    if (!strcmp(str1, str2)) {
//        printf("%s와 %s는 같은 문자 입니다.₩n", str1, str2);
//    }
//    else {
//        printf("%s와 %s는 다른 문자열 입니다.₩n", str1, str2);
//    }
    
    
    char* tokens = strtok(str1, " ");
    while (tokens != NULL) {
        printf("%s", tokens);
        printf("\n");
        tokens = strtok(NULL, " ");
    };

    return 0;
}

/*
 void strnins(char* s, char* t, int i);

 int main() {
     char a[MAX_SIZE] = "Hello";
     char b[MAX_SIZE] = " ";

     
     strnins(a, b, 2);

     printf("%s", a);
     return 0;
 }
 void strnins(char* s, char* t, int i)
 {   // 스트링 s의 i번째 위치에 스트링 t를 삽입
     char string[MAX_SIZE], * temp = string;

     if (i < 0 && i > strlen(s)) {
         fprintf(stderr, "Position is out of bounds \n");
 //        exit(1);
     }
     if (!strlen(s))
         strcpy(s, t);
     else if (strlen(t)) {
         strcat(t, s + i);
         strcpy(s + i, t);
     }
 }
 */

/*

 int main(void) {
     char name[MAX_SIZE] = "서영정";
 //    printf("%s", name);
     char s1[MAX_SIZE];

     printf("이름 입력>>");

     gets(name);
     printf("%s\n", name);

     strcpy(name, "이승철");
     printf("%s\n", name);

     // 주의 strncpy를 할 경우, 문자열의 맨 마지막에 존재하는 \0가 복사가 안되므로 쓰레기값이 나옴.
     strncpy(s1, name, 2);
     s1[2] = '\0';
     printf("%s\n", s1);
     
     
     strcpy(name, "Hello");
     strcpy(s1, "World");
     strcat(name, s1);
     printf("%s\n", name);

     strncat(name, s1, 3);
     printf("%s\n", name);
 }
 */
