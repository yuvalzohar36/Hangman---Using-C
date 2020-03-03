#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 1000
char fullstr[15][10];
int num_of_words = 0;
int opportunities;
int randomIndex = 0;
char last_string[255];
int word_length = 0;

int choose_opp() {
    int i;
    printf("\n Welcome to Hangame - Using C\n");
    //scanf("%d ",   &opportunities);
    printf("Type number of opportunities \n");
    scanf(" %d",  &opportunities);
   printf("Number of opportunities is : %d ", opportunities);
    printf("\n");
    // until Here just get number of playes
    return 0;
}

int readfile() {
        FILE* fp;
        int i = 0;
        char str[MAXCHAR];
        char* filename = "C:\\Users\\yuval\\Desktop\\Words.txt";
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Could not open file %s", filename);
            return 1;
        }
        while (fgets(str, MAXCHAR, fp) != NULL) {
            num_of_words += 1;
            printf(" %d \t ", num_of_words);
            strcpy(fullstr[i], str);
            printf("%s", fullstr[i]);
            i = i + 1;
        }
        srand(time(NULL));
        randomIndex = rand() % num_of_words;
        fclose(fp);
        return 0;
    }

int manage(){
        char compare_string[15];
        strcpy(compare_string, fullstr[randomIndex]);
        printf("\n The Words is : %s", &compare_string);
        for (word_length = 0; compare_string[word_length] != '\0'; ++word_length);
        printf("\n Length of Word is %d \n ", word_length-1);   // Find The Length Of The String 
        for (int k = 0;k < word_length-1;k++) {                        // Create new String With _ _ for guesses 
            last_string[k] = '_';
        }
        printf("\n Hangman : %s \n \n  ", last_string);
         while (opportunities >= 0){
            int count = 0;
            printf("Enter a char between A - Z \n");
            char currently_try;
            scanf(" %s", &currently_try);
            printf("The char you Entered is : %c", currently_try);
            printf("\n");
            printf("The number of opp is %d \n", opportunities);
            for (int j = 0;j < 10;++j) {
                if (compare_string[j] == currently_try) {
                    printf("Nice guess, the Letter %c exist ! \n ", currently_try);
                    last_string[j] = currently_try;
                    printf("\n The Word is : %s \n \n \n  ", last_string);
                    ++opportunities;
                    //break;
                }
                else {
                    count++;
                }
            }
            if (count == 10) {
                printf("Bad try !");
            }
            if (check_winning() == 0) {
                return 0;
            }
            --opportunities;
      }
        printf("Out of opp");
        return 0;
}

int check_winning() {
    int winning_counter = 0;
    for (int k = 0;k < word_length - 1;k++) {                        // Create new String With _ _ for guesses 
        if (last_string[k] != '_') {
            ++winning_counter;
        }
    }
    if (winning_counter == word_length - 1) {
        printf("\n You Won !");
        return 0;
    }
}


int main()
{
    readfile();
    choose_opp();
    manage();
}




