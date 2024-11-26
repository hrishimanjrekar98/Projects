#include "stdio.h"
#include "stdlib.h"

int main()
{
    unsigned char num = 0, bit_cnt = 0;

    printf("Enter number:");
    scanf("%x", &num);    // x for hex input, %d for integer input and automatically convert to hex in next step

    for(int i = 0; i < 8; i++)
    {
        if(num & (1<<i))
        {
            bit_cnt++;
        }
    }

    printf("bit set cnt:%d", bit_cnt);
}