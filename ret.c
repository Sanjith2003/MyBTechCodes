

#include <stdio.h>
#include <stdlib.h>

int* func(int a,int b)
{
    int* arr = (int*) malloc(sizeof(int)*(b-a+1));
    //int arr[b-a+1];
    int j = 0;
    for(int i = a;i <= b;i++)
    {
        arr[j++] =  i;
    }
    
    return arr;
}

int main()
{
    int* arr = func(1,5);
    
    for(int i = 0;i < 5;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

/*


func(1,5)
Main
*/