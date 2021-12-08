#include <stdio.h>
#include <stdlib.h>
#include <libxml2/libxml/parser.h>

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
#define MAX_TERMS 100

typedef struct {
   float coef;
   int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void padd(int starta, int finisha, int startb, int finishb, int* startd, int* finishd);
void attach(float coefficient, int exponent);

int main() {
    int startA  = 0;    int finishA = 0;
    int startB  = 0;    int finishB = 0;
    int startD = 0;    int finishD = 0;
    
//    다항식 a : 2x^500 + 1x^3 + 3
//    다항식 b : 1x^5 + 2x^3 + 3x^2 + 1
    
    startA = avail; //start지점 인덱스 0
    attach(2, 500);    attach(1, 3); attach(3, 0);
    finishA = avail-1; //avail-1 은 2를 가리키고 있음

    startB = avail; // 인덱스 3
    attach(1, 5);    attach(2, 3); attach(3, 2); attach(1, 0);
    finishB = avail-1;

    //A와 B의 인덱스를 합쳐놓은 지점
    startD = avail;
    finishD = -1;

    //finish D, start D는 왜 주소로 남겨두었나 ?
    padd(startA, finishA, startB, finishB, &startD, &finishD);

    for (int i = 0; i < avail; i++) {
        if (i == finishB) printf("%.0fx^%d = ", terms[i].coef, terms[i].expon);
        else if (i == avail - 1) printf("%.0fx^%d", terms[i].coef, terms[i].expon);
        else printf("%.0fx^%d + ", terms[i].coef, terms[i].expon);
    }
        
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)   // d = a + b. 그런데 startd와 finishd는 왜 포인터일까?
{
    float coefficient;
    *startD = avail;   // avail은 terms[]에서 비어있는 공간의 색인
    while (startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon, terms[startB].expon))
        {
        case -1: // a.expon < b.expon
            attach(terms[startB].coef, terms[startB].expon);
            startB++;  break;   // startb를 증가시키는 이유?
        case 0: // equal exponents
            coefficient = terms[startA].coef + terms[startB].coef;
            if (coefficient) attach(coefficient, terms[startA].expon);
            startA++;  startB++;   // starta와 startb를 모두 증가
            break;
        case 1: //  a.expon > b expon
            attach(terms[startA].coef, terms[startA].expon);
            startA++;   // starta만 증가
        }
//      아래의 for문 두개를 사용하지 않고 하는 방법
//    for (; startA <= finishA; startA++) attach(terms[startA].coef, terms[startA].expon);
//    for (; startB <= finishB; startB++) attach(terms[startB].coef, terms[startB].expon);
    // 여기의 for문은 A와 B의 다항식을 비교하면서 남는 다항식의 차수들을 계산하고 남은 식 뒤에 붙여주는 역할을 하는 것임
    // 그렇게 하기 위해 다항식 뒤에 의미 없는 항을 만들어내는 것임
    
    //    다항식 a : 2x^500 + 1x^3 + 3 + (0^-1 : 의미 없는 항)
    //    다항식 b : 1x^5 + 2x^3 + 3x^2 + 1 + (0^-1 : 의미 없는 항)
    
        /*
        startA = avail; //start지점 인덱스 0
        attach(2, 500);    attach(1, 3); attach(3, 0); attach(0, -1);
        finishA = avail-1; //avail-1 은 2를 가리키고 있음

        startB = avail; // 인덱스 3
        attach(1, 5);    attach(2, 3); attach(3, 2); attach(1, 0); attach(0, -1);
        finishB = avail-1;
    */
    
    *finishD = avail - 1;
}

void attach(float coefficient, int exponent)
{
    // 다항식에 새로운 항을 추가하는 함수
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "Too many terms in the polynomial \n.");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;   // avail은 여기에서 증가됨.
}
