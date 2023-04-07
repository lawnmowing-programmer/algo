#include <stdio.h>

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// arr의 start부터 end까지 숫자들 중에서
// pivot보다 작거나 같은 값을 result에 채우는 함수
int get_left_cnt(int *array, int start, int end, int pivot, int *left)
{
    int idx = 0;
    for (int i = start; i <= end; i++)
    {
        if (array[i] <= pivot)
            left[idx++] = array[i];
    }
    return (idx);
}

// arr의 start부터 end까지 숫자들 중에서
// pivot보다 큰 값을 result에 채우는 함수
int get_right_cnt(int *array, int start, int end, int pivot, int *right)
{
    int idx = 0;
    for (int i = start; i <= end; i++)
    {
        if (array[i] > pivot)
            right[idx++] = array[i];
    }
    return (idx);
}

void quick_sort(int *array, int start, int end)
{
    if (start >= end)
        return;

    int pivot = array[start];
    int left[50];
    int right[50];
    int left_count = get_left_cnt(array, start + 1, end, pivot, left);
    int right_count = get_right_cnt(array, start + 1, end, pivot, right);

    for (int i = 0; i < left_count; i++)
        array[start + i] = left[i];

    array[start + left_count] = pivot;

    for (int i = 0; i < right_count; i++)
        array[start + left_count + 1 + i] = right[i];

    quick_sort(array, start, start + left_count - 1);
    quick_sort(array, start + left_count + 1, end);
    
}

int main()
{
    int n;
    int array[50];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    quick_sort(array, 0, n - 1);
	print_array(array, n);
    return (0);
}