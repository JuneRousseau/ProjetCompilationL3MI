extern int printd(int i);

int f(int a)
{
	int c;
	if(a==1)
	{ 
		int a;
		int b;
		b=a;
		c=a+b;
		return f(a-1);
	}
	else
	{
		int c;
		c=a;
	}
		return f(a-1);
}
				

int a;

int main() {

int a;
a=10;
a= f(a);

return 0;
}
