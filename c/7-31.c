#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[]={1,2,2,3,5,6,6,8,9};
    int sz;
    int right,left,k,mid;
    printf("Ҫ�ҵ������ǣ�");
    scanf("%d",&k);
    left = 0;
    right = (sizeof(arr)/sizeof(arr[0]))-1;
    while(left<=right)
    {
        mid = (left+right)/2;
        if (arr[mid] < k)
            left = mid + 1;
        else if (arr[mid] > k)
            right = mid -1;
        else if (arr[mid] == k)
            {
                printf("�������������е��±��ǣ�%d",mid);
                break;
            }
    }
    if (left > right)
        printf("�޷��ڸ��������ҵ�������\n");
    system("pause");
    return 0;
}