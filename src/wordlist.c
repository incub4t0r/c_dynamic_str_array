#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc_funcs.h"

typedef struct {
    char **words;
    size_t size;
    size_t capacity;
} wordlist_t;

wordlist_t* wordlist_create(void)
{
    wordlist_t *p_wordlist = (wordlist_t *)safe_malloc(sizeof(wordlist_t), "new_array", __LINE__, __func__);
    if (!p_wordlist) {
        return NULL;
    }

    p_wordlist->size = 0;
    p_wordlist->capacity = 8;
    
    p_wordlist->words = (char **)safe_malloc(p_wordlist->capacity * sizeof(p_wordlist->words), "p_wordlist->words", __LINE__, __func__);
    if (!p_wordlist->words) {
        free(p_wordlist);
        return NULL;
    }

    return p_wordlist;
}

int wordlist_append(wordlist_t *str_arr, char *new_string)
{
    if (!str_arr) {
        return 0;
    }
    if (str_arr->size == str_arr->capacity) {
        char **tmp = (char **)safe_realloc(str_arr->words, 2 * str_arr->capacity * sizeof(str_arr->words), "str_arr->words", __LINE__, __func__);
        // char **tmp = realloc(str_arr->words, 2 * str_arr->capacity * (strlen(new_string) + 1));
        if (!tmp) {
            return 0;
        }

        str_arr->words = tmp;
        str_arr->capacity *= 2;
    }

    str_arr->words[str_arr->size] = strdup(new_string);
    if (!str_arr->words[str_arr->size])
    {
        printf("Size does not match\n");
        return 0;
    }
    str_arr->size++;
    return 1;
}

int wordlist_find(wordlist_t *str_arr, char *string)
{
    if (!str_arr)
    {
        return -1;
    }
    for (size_t idx = 0; idx < str_arr->size; idx++)
    {
        if (strcmp(str_arr->words[idx], string) == 0)
        {
            return idx;
        }
    }
    return -1;
}

void wordlist_print(wordlist_t* str_arr)
{
    if (!str_arr)
    {
        return;
    }
    for (size_t idx = 0; idx < str_arr->size; idx++)
    {
        printf("Location: %p\t%s\n", &(str_arr->words[idx]), str_arr->words[idx]);
    }
}

void wordlist_free(wordlist_t *str_arr)
{
    if (!str_arr)
    {
        return;
    }

    for (size_t i = 0; i < str_arr->size; i++) {
        free(str_arr->words[i]);
    }

    free(str_arr->words);
    free(str_arr);
}