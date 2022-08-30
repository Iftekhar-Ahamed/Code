#include <stdio.h>
int main()
{
  int i=1;

  kazKoro:
  printf(" %d iftekhar,Asik\n",i);
  i=i-1;
  if(i>=-5)goto kazKoro;

  return 0;
}