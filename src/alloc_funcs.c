#include <stdio.h>
#include <stdlib.h>

void *
safe_malloc(const size_t num_bytes, const char *var_name, const int line_num, const char *func_name)
{
    void *p_malloc_location = NULL;
    p_malloc_location = malloc(num_bytes);

    if (!p_malloc_location)
    {
        printf("Fatal: failed to allocate %ld bytes for variable '%s' on line '%d' in function '%s': Cannot allocate memory\n", num_bytes, var_name, line_num, func_name);
        free(p_malloc_location);
        return NULL;
    }

    return p_malloc_location;
}

void *
safe_realloc(void *ptr, const size_t num_bytes, const char *var_name, const int line_num, const char *func_name)
{
    void *p_realloc_location = NULL;
    p_realloc_location = realloc(ptr, num_bytes);

    if (!p_realloc_location)
    {
        printf("Fatal: failed to reallocate %ld bytes for variable '%s' on line '%d' in function '%s': Cannot allocate memory\n", num_bytes, var_name, line_num, func_name);
        free(p_realloc_location);
        return NULL;
    }

    return p_realloc_location;
}