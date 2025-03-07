#include<stdio.h>
#include<stdint.h>

#define PAGE_SIZE 4096

int main () {
    uint32_t input;
    scanf("%d", &input);
    if (input > 4294967295 || input < 0) {
        printf("Virtual address not in range! 0 to 2^32 - 1")
    }

    printf("Page number: %d\n", input / PAGE_SIZE);
    printf("Offset: %d\n", input % PAGE_SIZE);
}