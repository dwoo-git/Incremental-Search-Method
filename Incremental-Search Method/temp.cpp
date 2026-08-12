#include <stdio.h>
#include <math.h>

// 다항식 수식 직관적 계산: f(x) = a[3]*x^3 + a[2]*x^2 + a[1]*x + a[0]
double f(double x, double a[]) {
    return a[3] * pow(x, 3) + a[2] * pow(x, 2) + a[1] * x + a[0];
    
    return a[3] * x * x * x + a[2] * x * x + a[1] * x + a[0];
    // pow(x, 3) 대신 x * x * x를, pow(x, 2) 대신 x * x를 씁니다.
    // 작동 여부 : 가변 입력(배열)을 받는 방식과 결과는 100 % 똑같습니다.
    // 장점 : pow 함수를 호출하는 오버헤드가 없어져서 컴퓨터 연산 속도가 훨씬 빨라집니다.
}


// 1. 함수 정의할 때 변수를 4개 따로 받음
double f(double x, double a3, double a2, double a1, double a0) {
    return a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0;
}

int main() {
    double x;
    double a3, a2, a1, a0;
    
    // 2. scanf로 개별 변수에 연속 입력받음 (배열 없이도 가능!)
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);

    // 3. 함수 호출시 변수를 각각 전달
    double result = f(x, a3, a2, a1, a0);
}