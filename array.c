#include <stdio.h>
#include <stdlib.h>
#include "alloc_funcs.h"

typedef struct {
    char **pp_strings;
    size_t size;
    size_t capacity;
} str_array;

str_array *
safe_malloc_str_array(void)
{
    str_array *p_new_array = (str_array *)safe_malloc(sizeof(str_array), "new_array", __LINE__, __func__);
    if (!p_new_array) {
        return NULL;
    }

    p_new_array->pp_strings = (char **)safe_malloc(sizeof(char *), "p_new_array->pp_strings", __LINE__, __func__);
    if (!p_new_array->pp_strings) {
        return NULL;
    }

    p_new_array->size = 0;
    p_new_array->capacity = 1;

    return p_new_array;
}

int
append_str(str_array *str_arr, char *new_string)
{
    if (!str_arr) {
        return 0;
    }

    if (str_arr->size == str_arr->capacity) {
        char **tmp = (char **)safe_realloc(str_arr->pp_strings, 2 * str_arr->capacity * sizeof(char *), "tmp", __LINE__, __func__);
        if (!tmp) {
            return 0;
        }

        str_arr->pp_strings = tmp;
        str_arr->capacity *= 2;
    }

    str_arr->pp_strings[str_arr->size++] = new_string;
    return 1;
}

void
free_str_array(str_array *str_arr)
{
    if (!str_arr) {
        return;
    }
    free(str_arr->pp_strings);
    free(str_arr);
}