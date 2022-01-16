#include "splitting.h"

int trialDiv(int n){

	if(n%2 == 0)
		return 2;
	
	int i;
	for(i=3; i<=sqrt(n); i += 2){
		if(n%i == 0)
			return i;
	}

}

int fermatSplit(int n){

	int a = (int)ceil(sqrt(n));
	int c = a*a-n;
	while (!perfectSquare(c)){
	
		a++;
		c=a*a-n;
	
	}
	return (int)(a + sqrt(c));

}

int f(int x, int n){

	long int y = x*x;
	return (int)(abs(y + 1) % n);

}

int pollardRho(int n){

	int x = 2;
	int z = 2;
	int d = 1;

	while (d==1)
	{
		x = f(x, n);
		z = f(f(z,n),n);
		d = Gcd(abs(z-x), n);
	}

	if (d == 0)
		return -1;
	return d;
	
}

int pollardP_1S1 (int n, int B){

	int i, g, a = 2;
	int *primes = Atkin(B+1);

	for(i=1; primes[i]!=0; i++){
		a = expmod(a, (int)pow(primes[i], (int)(log(B)/log(primes[i]))), n);
	}
	g = Gcd(a-1, n);
	free(primes);

	if(g == 1)
		return -1;
	if(g%n == 0)
		return -n;
	return g;

}


int main(){
	
	int n = 0, d = 0;
	FILE *fp = fopen("composites.csv", "r"), *fpw;
	char *ch = NULL;
	char *lineptr = NULL;
	size_t len;
	size_t read;
	clock_t start, diff;
	char *fname = "p_11.csv";
	int B;

	/* Start where you left off */

	if ((fpw=fopen(fname, "r")))
	{
		while (((read = getline(&ch, &len, fpw)) != -1))
		{
			continue;
		}
		
		fclose(fpw);
		d = atoi(ch);
		printf("Start from %d\n", d);
		
		while (((read = getdelim(&ch, &len, 44, fp)) != -1))
		{
			n=atoi(ch);
			if(n==d)
				break;
		}	
	}

	/* Get next composite and test */
	while (((read = getdelim(&ch, &len, 44, fp)) != -1) )
	{

		n = atoi(ch); 
		printf("\b\b\b\b\b\b\b\b\b%d", n);
		B = (int) exp(log(sqrt(n)/2)/1.1);
		if(B<7)
			B=7;
		start = clock();
		d = pollardP_1S1(n, B);
		diff = clock() - start;
		fpw = fopen(fname, "a");
		fprintf(fpw, "%d,%d,%Lf\n", n, d, (long double)((double)diff/((double)CLOCKS_PER_SEC)));
		fclose(fpw); 

		
	}
	fclose(fp);
	printf("\n");
/*
	n=25681, B=7;
	d = pollardP_1S1(n, B);
	printf("%d\n", d);


	int* primes = Atkin(8), i;
	for(i=0; i < primes[0]; i++){
		printf("%d,", primes[i]);
	}printf("\n");
*/
	return 0;
	
}