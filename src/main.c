#include "main.h"
#include "luna.h"

int main(void) {
    struct lunaDate* theDate = (struct lunaDate*) malloc(sizeof(struct lunaDate));

    printf("Enter MM/DD/YYYY: ");
    scanf("%02u/%02u/%04u", &(theDate->month), &(theDate->day), &(theDate->year));

    printf("%02u/%02u/%04u\n", theDate->month, theDate->day, theDate->year);

    return(SUCCESS);
}
