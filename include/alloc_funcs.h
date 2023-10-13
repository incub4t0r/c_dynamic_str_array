#ifndef ALLOC_INFO_H
#define ALLOC_INFO_H

#include <stddef.h>

void *safe_malloc(size_t num_bytes, char *var_name, int line_num, const char *func_name);
void *safe_realloc(void *ptr, size_t num_bytes, char *var_name, int line_num, const char *func_name);

#endif