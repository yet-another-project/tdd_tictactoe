#include <stdio.h>
#include <stdlib.h>
#include <test/testunit.h>
#include <demo.h>

int tests_run = 0;

static char* test_demo() {
    test_assert("The demo() function does not return 42 as specified", 42 == demo());
    return NULL;
}

static char* all_tests() {
    run_test(test_demo);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    if(result != NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

