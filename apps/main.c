#include <stdio.h>
#include "wordlist.h"
#include <stdlib.h>
int
main(void)
{
    wordlist_t *wordlist = wordlist_create();
    if (!wordlist) {
        exit(EXIT_FAILURE);
    }

    char word[100] = "hello";
    for (int i = 0; i < 100; i++)
    {
        wordlist_append(wordlist, word);
    }

    wordlist_print(wordlist);
    wordlist_free(wordlist);
    exit(EXIT_SUCCESS);
}