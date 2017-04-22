long loop(long x,long n)
{
  long result = 0;
  long mask;
  for(mask = 1; mask != 0; mask = mask << n)
    {
      result |= (mask & x);
    }
  return result;
}

/*
A. register  %rdi hold x
   register  %rsi hold n
   register  %rax hold result 
   register  %rdx hold mask

B. the initial value of result is 0 and
   the initial value of mask is 1

C. test condition is mask != 0;

D. mask = mask << n;

E. result |= (mask & x);

F. the code is above

*/
