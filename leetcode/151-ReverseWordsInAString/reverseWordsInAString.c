#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void reverseWords(char* s);
void reverse(char*, int, int);
void reverseEachWord(char*, int);
void cleanSpaces(char *, int);

void
reverseWords(char *s)
{
  int n = strlen(s);
  // Step 1: reverse the whole string
  reverse(s, 0, n-1);
  // Step 2: reverse each word
  reverseEachWord(s, n);
  // Step 3: clean up spaces
  cleanSpaces(s, n);
}

void
reverse(char* s, int i, int j)
{
  while (i < j)
  {
    char tmp = s[i];
    s[i++] = s[j];
    s[j--] = tmp;
  }
}

void
reverseEachWord(char* s, int n)
{
  int i = 0, j = 0;
  while (i < n)
  {
    while(i < j || (i < n && s[i] == ' ')) i++;
    while(j < i || (j < n && s[j] != ' ')) j++;
    reverse(s, i, j-1);
  }
}

void
cleanSpaces(char* s, int n)
{
  //trim leading, trailing and multiple spaces
  int i = 0, j = 0;
  while (j < n)
  {
    while (j < n && s[j] == ' ') j++; // skip spaces
    while (j < n && s[j] != ' ') s[i++] = s[j++]; // keep non spaces
    if (j < n) s[i++] = ' ';
  }
  realloc(s, sizeof(char)*i);
}

int
main()
{
  char *s = malloc(sizeof(char) * strlen("  the sky is  blue"));
  strcpy(s, "  the sky is  blue");
  reverseWords(s);
  printf("%s", s);
  return 0;
}
