extern int printd( int i );

int main() {
  int i;
  int j;
  int k;
  i = 45000;
  j = -123;
  k = 43;
  printd(((i+j)*k/100+j*k*i-j*2*k)/(k-j*2*k));
  return 0;
}
