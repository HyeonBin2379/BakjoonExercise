#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 명단 리스트 생성용 구조체
typedef struct {
    char name[21];
} Name;

// qsort 정렬 기준
int compare(const void* first, const void* second)
{
    Name* a = (Name*)first;
    Name* b = (Name*)second;

    if (strcmp(a->name, b->name) > 0)
        return 1;
    else if (strcmp(a->name, b->name) < 0)
        return -1;
    else
        return 0;
}
// 사전순으로 이진탐색
int binarySearch(Name list[], int len, char* target)
{
    int left = 0;
    int right = len-1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmp(list[mid].name, target) == 0)
            return mid;
        else if (strcmp(list[mid].name, target) > 0)
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}
int main(void)
{
    int m, n;
    scanf("%d%d", &n, &m);

    Name unheard[n];    // 듣도못한 사람들
    Name unseen[m];     // 보도못한 사람들

    // 듣도못한 사람, 보도못한 사람 이름 입력
    for (int i = 0; i < n; i++)
    {
        scanf("%s", unheard[i].name);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", unseen[i].name);
    }
    
    // 두 리스트를 정렬하기
    qsort(unheard, n, sizeof(unheard[0]), compare);
    qsort(unseen, m, sizeof(unseen[0]), compare);

    // 듣도보도 못한 사람 = 두 명단에 이름이 모두 존재하는 사람
    // 듣도보도못한 사람의 unseen에서의 인덱스 번호만 따로 저장하여 출력
    int indices[m] = {0,};
    int count = 0;          // 듣도보도못한 사람 수
    for (int i = 0; i < n; i++)
    {
        int idx;    // unseen에서의 인덱스 번호
        // unheard의 명단에서 unseen에 있는 이름 찾기, 이진 탐색을 활용
        if ((idx = binarySearch(unseen, m, unheard[i].name)) != -1)
        {
            indices[count++] = idx;
        }
    }

    // 듣도보도 못한 인원수와 이름 출력(이름 출력은 사전순)
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
        printf("%s\n", unseen[indices[i]].name);
    
    return 0;
}