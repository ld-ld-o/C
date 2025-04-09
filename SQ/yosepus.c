#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int queue[1000];       // N 최대값에 맞게 배열 준비
    for (int i = 0; i < N; i++) {
        queue[i] = i + 1;  // 1부터 N까지 채움
    }

    int result[1000];      // 제거 순서 저장
    int front = 0, rear = N;
    int count = 0;
    int idx = 0;

    int size = N;
    int pos = 0;

    while (size > 0) {
        count = 0;
        // K번째 찾기
        while (count < K) {
            if (queue[pos % N] != 0) {  // 살아 있는 사람만 세기
                count++;
            }
            if (count == K) break;
            pos++;
        }
        // 제거
        result[idx++] = queue[pos % N];
        queue[pos % N] = 0;  // 제거 표시
        size--;
        pos++;
    }

    // 출력
    printf("<");
    for (int i = 0; i < N; i++) {
        printf("%d", result[i]);
        if (i != N - 1) printf(", ");
    }
    printf(">\n");

    return 0;
}

