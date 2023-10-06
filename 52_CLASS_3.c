#include <stdio.h>
#include <string.h>
int myStringLen(char a[])
{
  int len = 0;
  for (int i = 0; a[i] != '\0'; i++)
  {
    len++;
  }
  return len;
}
void takeInput(char a[])
{
  char ch = ' ';
  int i = 0;
  while (scanf("%c", &ch) == 1 && (ch != '\n' || i == 0))
  {
    if (ch == '\n')
    {
      continue;
    }

    a[i] = ch;
    i++;
  }
  a[i] = '\0';
}

void myConcatString(char a[], char b[])
{
  int lenOfA = myStringLen(a), lenOfB = myStringLen(b);
  a[lenOfA] = ' ';
  lenOfA++;
  for (int i = lenOfA; i <= lenOfA + lenOfB; i++)
  {
    a[i] = b[i - lenOfA];
  }
}
int main()
{
  char a[30], b[15];
  // for (int i = 0; i < 4; i++)
  // {
  //   scanf("%c", &a[i]);
  // }
  // gets(a);
  // scanf(" %[^\n]", a);
  // takeInput(a);
  // printf("%s\n", a);
  // for (int i = 0; i < 4; i++)
  // {
  //   printf("index %d = %c\n", i, a[i]);
  // }
  // char ch;
  // scanf("%c", &ch);
  // getchar();
  // gets(a);
  // gets(b);
  // printf("%s %s \n", a, b);

  takeInput(a);
  takeInput(b);
  // char t[] = " ";
  // strcat(a, t);
  // strcat(a, b);
  myConcatString(a, b);
  printf("%s %s \n", a, b);
}