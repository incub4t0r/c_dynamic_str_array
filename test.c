#include <stdio.h>
#include "array.h"
#include <stdlib.h>
int
main(void)
{
    str_array *str_arr = safe_malloc_str_array();
    if (!str_arr) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 123456789; i++)
    {
        append_str(str_arr, "Hello");
    }
    // for (size_t i = 0; i < str_arr->size; i++) {
    //     printf("%s\n", str_arr->pp_strings[i]);
    // }
    free_str_array(str_arr);
    exit(EXIT_SUCCESS);
}