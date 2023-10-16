#include <stdio.h>
#include "wordlist.h"
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    if (2 != argc)
    {
        printf("Usage: %s [num to repeat hello].\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    wordlist_t *wordlist = wordlist_create();

    if (!wordlist) {
        exit(EXIT_FAILURE);
    }

    char word[100] = "hello";

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        wordlist_append(wordlist, word);
    }

    wordlist_print(wordlist);
    wordlist_free(wordlist);
    exit(EXIT_SUCCESS);
}