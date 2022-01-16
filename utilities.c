#include "utilities.h"

int expmod(int b, int e, int m){

	int r = 1;
	long int x;
	while(e > 0){
		if(e%2){
			x = (r*b) % m;
			r = (int) x;
		}
		x = (b*b)%m;
		b = (int) x;
		e >>= 1;
	}
	return r;
}

int longexpmod(int b, long int e, int m){

	int r = 1;
	while(e > 0){
		if(e%2)
			r = (r * b)%m;
		b = (b*b)%m;
		e >>= 1;
	}
	return r;
}

int Gcd(int a, int b){

	if(!a || !b)
		return 0;
	if (b > a){
		a=a-b;
		b=a+b;
		a=b-a;
	}
	int temp, c;

	while (1){

		if (a % b == 0)
			return b;

		c = (int)(a / b);
		temp = b;
		b = a - c*b;
		a = temp;
	}

}

long int longgcd(long int a, long int b){

	if (b > a){
		a=a-b;
		b=a+b;
		a=b-a;
	}
	long int temp, c;

	while (1){

		if (a % b == 0)
			return b;

		c = a / b;
		temp = b;
		b = a - c*b;
		a = temp;
	}

}

int perfectSquare(int x){
	
	double root = sqrt(x);
	return (root- (int) root) == 0;

}

char mrWitness(int n, int k, int q, int a){

	int i, x = expmod(a, q, n);
    if(x==1 || x==n-1)
        return 0;
    for(i=0; i<k; i++){
        x = expmod(x, 2, n);
        if(x == n-1)
            return 0;
	}
    return 1;
}

char mrTest(int n){

	int witnesses[] = {2, 7, 61};

	int i, k, q;
    for(k=1; !((n-1)/((int)pow(2,k)) % 2); k++)
    q = (int) (n-1)/((int)pow(2,k));

	for(i=0; i<3; i++){
		if(Gcd(witnesses[i], n) > 1)
            return 0;
        if(mrWitness(n, k, q, witnesses[i]))
            return 0;
	}
	return 1;
}

int *Atkin(int limit){

    int wlimit;
    int i, j, k, x, y, z;
	int nprimes;
    unsigned char *sieve;
	sieve = (unsigned char *) calloc(limit, sizeof(unsigned char));
 
    wlimit = sqrt(limit);
 
    for (x = 1; x <= wlimit; x++) {
        for (y = 1; y <= wlimit; y++) {
            z = 4 * x * x + y * y;
            if (z <= limit && (z % 60 == 1 || z % 60 == 13 || z % 60 == 17 || z
                    % 60 == 29 || z % 60 == 37 || z % 60 == 41 || z % 60 == 49
                    || z % 60 == 53)) {
                sieve[z] = !sieve[z];
            }
            z = 3 * x * x + y * y;
            if (z <= limit && (z % 60 == 7 || z % 60 == 19 || z % 60 == 31 || z
                    % 60 == 43)) {
                sieve[z] = !sieve[z];
            }
            z = 3 * x * x - y * y;
            if (x > y && z <= limit && (z % 60 == 11 || z % 60 == 23 || z % 60
                    == 47 || z % 60 == 59)) {
                sieve[z] = !sieve[z];
            }
        }
    }
 
    for (i = 5; i <= wlimit; i++) {
        if (sieve[i] == 1) {
            for (j = 1; j * i * i <= limit; j++) {
                sieve[j * i * i] = 0;
            }
        }
    }

	for(i=6; i<limit; i++)
		nprimes += sieve[i];

	int *primes = (int *)malloc((nprimes + 4)*sizeof(int));
	primes[0]=nprimes+4, primes[1]=2;primes[2]=3;primes[3]=5;
	
	for(i=4, j=5; i<nprimes+4 && j<limit; j++){
		if(sieve[j]){
			primes[i] = j;
			i++;
		}
	}
	free(sieve);
	
	return primes;
}

/*
int main(){
	int *p = Atkin(80);
	int i;
	for(i=0; i<22; i++)
		printf("%d\n", *(p+i));
}
*/