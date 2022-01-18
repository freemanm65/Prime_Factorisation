# Prime_Factorisation

splitting.c contains the following functions
- trialDiv(int n) - an implementation of the trial division algorithm
- fermatSplit(int n) - an implementation of the fermat factorisation algorithm
- pollardRho(int n) - an implementation of the Pollard Rho algorithm
- f(int x, int n) - reduces x^2 + 1 modulo n, used in pollardRho
- pollardP_1S1(int n, int B) - an implementation of the Pollard p-1 algorithm
- main() - the function that runs when the compiled program runs. Currently tests pollardRho. Requires a composites.csv file

utilities.c contains the following
- Gcd(int a, int b) - computes the gcd of a and b
- longgcd(long int a, long int b) - computes the gcd of a and b, where a and b are long integers
- expmod(int b, int e, int n) - performs the fast modular exponentiation algorithm
- longexpmod(int b, long int e, int n) - performs the fast modular exponentiation algorithm, where the exponent can be a long int
- perfectSquare(int n) - determines whether n is a perfect square
- mrWitness(int, int, int, int) - used in mrTest
- mrTest(int n) - determines whether n is a prime - unused
- Atkin(int x) - generates an array of primes less than x

genComposites.py generates the odd composites up to 100,000,000

splitting.c can be compiled on unix machines by running the compile file. This generates an executable called main which will run the main function in splitting.c

