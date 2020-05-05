extern int printd( int i );

int (*fact) (int n);
int *(test)(int a, int b);
int foo (int n)
{
  if ( n <= 1 )
    return 1;
  return (n*(*fact)(n-1));
}


int main() {
  int a;
  fact=&foo;
  a=test;
  printd((*fact)(10));
  return 0;
}
