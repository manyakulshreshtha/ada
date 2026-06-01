#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobile_pos = -1;

    for(int i = 0; i < n; i++)
    {
        if(dir[a[i]-1] == LEFT && i != 0)
        {
            if(a[i] > a[i-1] && a[i] > mobile)
            {
                mobile = a[i];
                mobile_pos = i;
            }
        }

        if(dir[a[i]-1] == RIGHT && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile)
            {
                mobile = a[i];
                mobile_pos = i;
            }
        }
    }
    return mobile;
}

void generatePermutations(int n)
{
    int a[n], dir[n];

    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    while(1)
    {
        int mobile = getMobile(a, dir, n);

        if(mobile == 0)
            break;

        int pos;
        for(pos = 0; pos < n; pos++)
            if(a[pos] == mobile)
                break;

        if(dir[mobile-1] == LEFT)
        {
            int temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;
            pos--;
        }
        else
        {
            int temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;
            pos++;
        }

        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
                dir[a[i]-1] *= -1;
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    generatePermutations(n);

    return 0;
}