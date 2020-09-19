
#include <fenv.h> //fegetround FE_*
#include <math.h> // rint
#include <stdio.h> //printf

char fegetgroundtest()
{
    char str[]="unknown";
    printf("rounding using ");
    switch (fegetround())
    {
        case FE_DOWNWARD:
            printf("download");
            break;
        case FE_TONEAREST:
            printf("to nearest");
            break;
        case FE_TOWARDZERO:
            printf("towardzero");
            break;
        case FE_UPWARD:
            printf("upward");
            break; 
        default:
            printf("unknown");
    }
    printf(" rounding:\n");

    return *str;
}

