extern int printd( int i );
extern int *malloc( int size );

int main() {
   int *i;
   int *j;
   
   i=malloc(sizeof(int));
   j=malloc(sizeof(int));

   *i=4;
  
   printd(*i);

   *j=6;
   printd(*j);

   *j=*j+(*i);
   printd(*j);
   return 0;
}
