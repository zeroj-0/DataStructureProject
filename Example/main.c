
#include <stdio.h>
#include <time.h>

void func(void){
    int result = 0;
    for (int i=0; i<1000; i++) {
        result += i;
    }
}

int main(void){
    clock_t start, stop;
    double duration;
    
    start = clock();
    func();
    stop = clock();
    
    duration = ((double)(stop-start)) / CLOCKS_PER_SEC;
    printf("실행시간 : %.8f", duration);
    
}
