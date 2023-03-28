#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int row;
    int col;
    int value;
};

void transpose(struct element* a, struct element* b, int terms)
{
    int n, i, j, current_b;
    n = a[0].value;

    b[0].row = n;
    b[0].col = a[0].row;
    b[0].value = terms;

    if (terms > 0)
    {
        current_b = 1;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j <= terms; j++)
            {
                if (a[j].col == i)
                {
                    b[current_b].row = a[j].col;
                    b[current_b].col = a[j].row;
                    b[current_b].value = a[j].value;
                    current_b++;
                }
            }
        }
    }
}

int main()
{
    int rows, cols, terms, i;
    struct element* a, * b;

    printf("행, 열 및 0이 아닌 항목의 수를 입력하세요: ");
    scanf_s("%d %d %d", &rows, &cols, &terms);

    if (rows <= 0 || cols <= 0 || terms < 0 || terms > rows * cols)
    {
        printf("유효하지 않은 입력입니다.\n");
        return 0;
    }

    a = (struct element*)malloc((terms + 1) * sizeof(struct element));
    b = (struct element*)malloc((terms + 1) * sizeof(struct element));

    if (!a || !b)
    {
        printf("메모리 할당에 실패하였습니다.\n");
        return 0;
    }

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = terms;

    printf("행, 열 및 0이 아닌 값을 입력하세요:\n");

    for (i = 1; i <= terms; i++)
    {
        scanf_s("%d %d %d", &a[i].row, &a[i].col, &a[i].value);

        if (a[i].row < 0 || a[i].row >= rows || a[i].col < 0 || a[i].col >= cols)
        {
            printf("유효하지 않은 입력입니다.\n");
            free(a);
            free(b);
            return 0;
        }
    }

    transpose(a, b, terms);
    printf("전치행렬:\n");

    for (i = 1; i <= terms; i++)
    {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }

    free(a);
    free(b);

    return 0;
}