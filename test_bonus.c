#include <stdio.h>
#include "ft_printf.h"

void run_test(const char *name)
{
    printf("\n=== %s ===\n", name);
}

int main(void)
{
    int ret1, ret2;
    char *s = "42Madrid";
    
    run_test("1. Integers: Width, Precision, Zero, Plus, Space");
    ret1 = printf("Libc: [%015.5d] [%-15.5d] [%+010d] [% 10.0d] [%.0d]\n", -42, 42, 42, 0, 0);
    ret2 = ft_printf("Mine: [%015.5d] [%-15.5d] [%+010d] [% 10.0d] [%.0d]\n", -42, 42, 42, 0, 0);
    printf("Ret -> Libc: %d | Mine: %d\n", ret1, ret2);

    run_test("2. Hexadecimals: Hashtag, Zero, Minus, Precision");
    ret1 = printf("Libc: [%#015x] [%#-15X] [%#.0x] [%#10.5x] [%#x]\n", 255, 255, 0, 255, 0);
    ret2 = ft_printf("Mine: [%#015x] [%#-15X] [%#.0x] [%#10.5x] [%#x]\n", 255, 255, 0, 255, 0);
    printf("Ret -> Libc: %d | Mine: %d\n", ret1, ret2);

    run_test("3. Strings & Chars: Truncation, Width, Minus");
    ret1 = printf("Libc: [%10.2s] [%-10.4s] [%.0s] [%-5c] [%5c]\n", s, s, s, 'X', 'Y');
    ret2 = ft_printf("Mine: [%10.2s] [%-10.4s] [%.0s] [%-5c] [%5c]\n", s, s, s, 'X', 'Y');
    printf("Ret -> Libc: %d | Mine: %d\n", ret1, ret2);
    
    run_test("4. Unsigned & Pointers: Edge cases");
    ret1 = printf("Libc: [%010.5u] [%15p] [%-15p]\n", 42, (void *)s, NULL);
    ret2 = ft_printf("Mine: [%010.5u] [%15p] [%-15p]\n", 42, (void *)s, NULL);
    printf("Ret -> Libc: %d | Mine: %d\n", ret1, ret2);
    
    run_test("5. The Ultimate Combo (Multiple variables)");
    ret1 = printf("Libc: %05d | %-10.3s | %#.4x | %+d\n", 7, s, 42, 42);
    ret2 = ft_printf("Mine: %05d | %-10.3s | %#.4x | %+d\n", 7, s, 42, 42);
    printf("Ret -> Libc: %d | Mine: %d\n", ret1, ret2);

    return 0;
}
