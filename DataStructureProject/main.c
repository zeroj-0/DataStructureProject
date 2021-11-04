#include <stdio.h>
#define MAX(a,b)((a>b)?a:b)     // a>b이면 a, a<b이면 b가 return
#define MAX_DEGREE 50
 
typedef struct{
    int degree;                         //최고차항 선언
    float coef[2][MAX_DEGREE];          //[0][]은 계수 [1][]은차수를 저장
}polynomial;
 
polynomial addPoly(polynomial A,polynomial B)
{
    polynomial C;  // 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언
    int A_index=0,B_index=0,C_index=0;
    int A_degree=A.degree,B_degree=B.degree;
    C.degree = MAX(A.degree,B.degree);  //A와 B중에 최고차항을 넣어줌
 
    while(A_index<=A.degree && B_index<=B.degree){
        if(A_degree>B_degree)
        {
            C.coef[0][C_index++]=A.coef[0][A_index++];
            A_degree--;
        }
        else if(A_degree == B_degree){
            C.coef[0][C_index++]=A.coef[0][A_index++]+B.coef[0][B_index++];
            A_degree--;
            B_degree--;
        }
        else
        {
            C.coef[0][C_index++]=B.coef[0][B_index++];
            B_degree--;
        }
    }
    return C;      //다항식 덧셈의 결과 다항식 C를 반환
}
 
 
void printPoly(polynomial P)
{
    int i,degree;
    degree=P.degree;
 
    for(i=0;i<P.degree+1;i++)
    {
        printf("%3.0fx^%d ",P.coef[0][i],degree--);
    }
    printf("\n");
}
 
int main(void)
{
    polynomial A={3,{4,3,5,0}};
    polynomial B={4,{3,1,0,2,1}};
 
    polynomial C;
    
    C= addPoly(A,B); // 다항식 A,B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출
 
    printf("\n A(x)="); printPoly(A);       //다항식 A출력
    printf("\n B(x)="); printPoly(B);       //다항식 B출력
    printf("\n C(x)="); printPoly(C);       //다항식 C출력
 
    getchar();
    return 0;
}
