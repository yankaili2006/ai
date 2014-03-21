#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv)
{
    int d[8] = {1, -2, 3, 10, -4, 7, 2, -5}, i, fsum = 0, max = 0;

    for(i = 0; i<8; i++)
    {
        if(fsum + d[i] > d[i])
        {
            fsum = fsum + d[i];
        }
        else
        {
            fsum = d[i];
        }

        if(fsum > max)
        {
            max = fsum;
        }
    printf("fmax = [%d], max = [%d]\n", fsum, max);
    }
    printf("max = [%d]\n", max);

    return 0;
}
