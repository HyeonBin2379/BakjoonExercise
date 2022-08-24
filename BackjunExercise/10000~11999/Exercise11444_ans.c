#include <stdio.h>
#include <string.h>

long long arr[2][2];
long long original[2][2];
long long temp1[2][2];

int N = 2;
long long B;
int i, j, m;



// 재귀 속에서 정적 변수인 arr을 공용으로 사용하면서 업데이트해나감.
void pow_(long long k) {
    
    //10830번과 다르게 제곱수 B가 0일 때의 예외가 있다...
    if(k <= 1) { // k == 1에서 k <= 1로 교체 -> 피보나치 pow_(0)일 때가 있으므로..
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++)
                arr[i][j] %= 1000000007LL;
        }
        return;
    }
    
    pow_(k / 2);
    
    // 재귀 결과 상태를 받아옴, int a = pow_(k / 2)라고 보면 됨.
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++)
            temp1[i][j] = arr[i][j];
    }
    
    // 비워주고
    memset(arr, 0, sizeof(arr));
    
    // 곱
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            for(m = 0; m < N; m++)
                arr[i][j] = (arr[i][j] + (temp1[i][m] * temp1[m][j])) % 1000000007LL;
        }
    }
    
    if(k % 2) {
        // temp1에 arr 결과값을 복사한 뒤
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++)
                temp1[i][j] = arr[i][j];
        }
        // arr을 다시 비워주고
        memset(arr, 0, sizeof(arr));
        
        // 곱
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                for(m = 0; m < N; m++)
                    arr[i][j] = (arr[i][j] + (temp1[i][m] * original[m][j])) % 1000000007LL;
            }
        }
        
    }
    
}

int main() {
    
    scanf("%lld", &B);
    
    
    arr[0][0] = original[0][0] = 1LL;
    arr[0][1] = original[0][1] = 1LL;
    arr[1][0] = original[1][0] = 1LL;
    arr[1][1] = original[1][1] = 0LL;
    
    pow_(B - 1); // 행렬곱에서 얻을 수 있는 최대 피보나치는 F(n+1) = 행렬 0,0 이므로 절약을 위해 이렇게 수행.
    
    //10830번과 다르게 제곱수 B가 0일 때의 예외가 있다...
    printf("%lld", (B==0)?0:arr[0][0]);
}
