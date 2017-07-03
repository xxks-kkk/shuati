## Failure solutions

Below are solutions I test out working locally but somehow
fails OJ.

I attach them here for future investigation.


### Solution one

```c
char* reverseWords(char* s) 
{
  if (strcmp(s,"") == 0) return "";
  char* result = malloc(sizeof(char) * strlen(s));
  char* token = strtok(s, " ");
  int i, j;
  char temp;
  while(1)
  {
    for(i = 0, j = strlen(token)-1; i<j; i++, j--) 
    {
      temp = token[i];
      token[i] = token[j];
      token[j] = temp;
    }
    strcat(result, token);
    token = strtok(NULL, " ");
    if (token != NULL) strcat(result, " ");
    else break;
  }
  return result;
}
```                                                                

### Solution two

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void
reverse(char* s, int i, int j)
{
  for(; i < j; i++, j--)
  {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

char*
reverseWords(char* s)
{
  int i, j;
  for(i = 0; s[i] != '\0'; i++)
  {
    if (s[i] != ' ')
    {
      j = i;
      for(; s[j] != '\0' && s[j] != ' '; j++);
      reverse(s, i, j-1);
      i = j;
    }
  }
  return s;
}

int
main(void)
{
  char *s = "Let's take LeetCode contest";
  int len = strlen(s);
  char *use = malloc(sizeof(char) * len);
  strcpy(use, s);
  char *result = reverseWords(use);
  printf("%s\n", result);
}
```
