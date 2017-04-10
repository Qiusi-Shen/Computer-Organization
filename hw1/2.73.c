#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int add = x+y;
  int pos = (add>>31&1)&&(!(x>>31&1))&&(!(y>>31&1));
  int neg = (!(add>>31&1))&&(x>>31&1)&&(y>>31&1);
  int result = (((pos<<31)>>31)&INT_MAX)       
    | ((((!pos&&neg)<<31)>>31)&INT_MIN) 
    | ((((!pos&&!neg)<<31)>>31)&add);
  return result;
}
