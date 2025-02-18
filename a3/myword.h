/*
--------------------------------------------------
Project: a3q2
File:    myword.h
Author:  Sushant Sah
Version: 2025-01-31
--------------------------------------------------
*/ 

#ifndef MYWORD_H
#define MYWORD_H

#include <stdio.h>

typedef enum boolean {
    FALSE = 0, TRUE = 1
} BOOLEAN;

typedef struct word {
    char word[20];
    int count;
} WORD;

typedef struct wordstats {
    int line_count;
    int word_count;
    int keyword_count;
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictrionay);

BOOLEAN contain_word(char *dictionary, char *word);

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif