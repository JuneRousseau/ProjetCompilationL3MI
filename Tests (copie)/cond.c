extern int printd( int i );

int main() {
  int i;
  int j;
  i = 450;
  j = -123;

  /*i=1+2+3+4+5+6+7+8+9+9+9+9+1+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9+9;
j=1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+11+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1;
*/
  if ( i+1 < j+0 ) printd(i); else printd(j);
  if ( i+1 < 123 ) printd(i); else printd(j);
  if ( i+1 < j ) printd(i); else printd(j);
  if ( 45 < j+0 ) printd(i); else printd(j);
  if ( 45 < 123 ) printd(i); else printd(j);
  if ( 45 < j ) printd(i); else printd(j);
  if ( i < j+0 ) printd(i); else printd(j);
  if ( i < 123 ) printd(i); else printd(j);
  if ( i < j ) printd(i); else printd(j);

  if ( i+1 > j+0 ) printd(i); else printd(j);
  if ( i+1 > 123 ) printd(i); else printd(j);
  if ( i+1 > j ) printd(i); else printd(j);
  if ( 45 > j+0 ) printd(i); else printd(j);
  if ( 45 > 123 ) printd(i); else printd(j);
  if ( 45 > j ) printd(i); else printd(j);
  if ( i > j+0 ) printd(i); else printd(j);
  if ( i > 123 ) printd(i); else printd(j);
  if ( i > j ) printd(i); else printd(j);

  if ( i+1 >= j+0 ) printd(i); else printd(j);
  if ( i+1 >= 123 ) printd(i); else printd(j);
  if ( i+1 >= j ) printd(i); else printd(j);
  if ( 45 >= j+0 ) printd(i); else printd(j);
  if ( 45 >= 123 ) printd(i); else printd(j);
  if ( 45 >= j ) printd(i); else printd(j);
  if ( i >= j+0 ) printd(i); else printd(j);
  if ( i >= 123 ) printd(i); else printd(j);
  if ( i >= j ) printd(i); else printd(j);

  if ( i+1 <= j+0 ) printd(i); else printd(j);
  if ( i+1 <= 123 ) printd(i); else printd(j);
  if ( i+1 <= j ) printd(i); else printd(j);
  if ( 45 <= j+0 ) printd(i); else printd(j);
  if ( 45 <= 123 ) printd(i); else printd(j);
  if ( 45 <= j ) printd(i); else printd(j);
  if ( i <= j+0 ) printd(i); else printd(j);
  if ( i <= 123 ) printd(i); else printd(j);
  if ( i <= j ) printd(i); else printd(j);

  if ( i+1 == j+0 ) printd(i); else printd(j);
  if ( i+1 == 123 ) printd(i); else printd(j);
  if ( i+1 == j ) printd(i); else printd(j);
  if ( 45 == j+0 ) printd(i); else printd(j);
  if ( 45 == 123 ) printd(i); else printd(j);
  if ( 45 == j ) printd(i); else printd(j);
  if ( i == j+0 ) printd(i); else printd(j);
  if ( i == 123 ) printd(i); else printd(j);
  if ( i == j ) printd(i); else printd(j);

  if ( i+1 != j+0 ) printd(i); else printd(j);
  if ( i+1 != 123 ) printd(i); else printd(j);
  if ( i+1 != j ) printd(i); else printd(j);
  if ( 45 != j+0 ) printd(i); else printd(j);
  if ( 45 != 123 ) printd(i); else printd(j);
  if ( 45 != j ) printd(i); else printd(j);
  if ( i != j+0 ) printd(i); else printd(j);
  if ( i != 123 ) printd(i); else printd(j);
  if ( i != j ) printd(i); else printd(j);

  return 0;
}
