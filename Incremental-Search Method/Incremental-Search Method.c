#include <stdio.h>
#include <math.h>

// ch1.1_Incremental-Search Method
// 다항식 수식 직관적 계산: f(x) = a[3]*x^3 + a[2]*x^2 + a[1]*x + a[0]
double f(double x, double a[]) {
    return a[3] * pow(x, 3) + a[2] * pow(x, 2) + a[1] * x + a[0];
}

int main() {
    double a[4];           // 계수 배열 (a[3]x^3 + a[2]x^2 + a[1]x + a[0])
    double x;              // 초기근사해 (x_i)
    double dx;             // 초기증분 (Δx)
    double epsilon = 1e-4; // 허용오차 (ε = 10^-4)
    int it_max;            // 최대 반복 횟수 제한

    double f_x, f_xdx;     // f(x_i) 및 f(x_i + Δx)
    double prod;           // f(x_i) * f(x_i + Δx)
    int step = 0;

    // (1) 계수 배열 입력
    printf("3차 방정식 계수 (a3, a2, a1, a0)를 입력하세요: ");
    scanf_s("%lf %lf %lf %lf", &a[3], &a[2], &a[1], &a[0]);

    // (2) 초기 근사해, 증분, 최대 반복 횟수 입력
    printf("초기근사해(x_i) 및 초기증분(Δx)을 입력하세요: ");
    scanf_s("%lf %lf", &x, &dx);

    printf("최대 반복 횟수(it_max)를 입력하세요: ");
    scanf_s("%d", &it_max);

    printf("\n--- 계산 시작 ---\n");
    
    while (1) {
        step++;

        // 무한 루프 방지
        if (step > it_max) {
            printf("\n최대 반복 횟수(%d회)를 초과하여 계산 중단\n", it_max);
            break;
        }

        // (3) f(x_i) 및 f(x_i + Δx) 계산
        f_x = f(x, a);
        f_xdx = f(x + dx, a);

        // (4) f(x_i) * f(x_i + Δx) 부호 계산
        prod = f_x * f_xdx;

        printf("[%d단계] x_i = %.6f, Δx = %.6f, f(x_i)*f(x_i+Δx) = %.6e\n",
            step, x, dx, prod);

        // (5) 부호 조건에 따른 분기
        if (prod > 0) {
            // (5-i) f(x_i) * f(x_i + Δx) > 0 인 경우
            x = x + dx;
        }
        else if (prod < 0) {
            // (5-ii) f(x_i) * f(x_i + Δx) < 0 인 경우
            if (dx <= epsilon) {
                // Δx <= ε 이면 x_i + Δx를 근으로 하고 종료
                printf("\n[결과] 허용오차 조건 만족 (Δx <= ε)\n");
                printf("근(x) = %.6f (총 반복 횟수: %d회)\n", x + dx, step);
                break;
            }
            else {
                // else Δx = Δx * 0.1 로 하고 순서 (3)으로 이동
                dx = dx * 0.1;
            }
        }
        else {
            // (5-iii) f(x_i) * f(x_i + Δx) == 0 인 경우
            printf("\n[결과] 정확한 근 발견\n");
            printf("근(x) = %.6f (총 반복 횟수: %d회)\n", x + dx, step);
            break;
        }
    }

    return 0;
}