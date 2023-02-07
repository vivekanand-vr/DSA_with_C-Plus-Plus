#include <bits/stdc++.h>
using namespace std;

//Counts Digits in a Number 
int count_Digits(long X)
{
    int K = floor(log10(X) + 1);
    return K;
}

//Most Efficient method to calculate HCF/GCD
int GCD(long a, long b)
{
    if (a == 0)
        return b;

    return GCD(b % a, a);
}

//Finding trailing zeros in factorial of a number
int findTrailingZeros(int n)
{
    if (n < 0) 
        return -1;

    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

//Check is the number prime (Most Efficient Method) 
 bool isPrime(long num) {
        if(num <= 1) return false;
        if (num == 3 or num == 2)
            return true; 
        
        if(num%2==0 or num%3==0) 
            return false;

        for (long i = 5; i <= num; i += 6) 
            if (num % i == 0 || num % (i + 2) == 0) 
                return false; 

        return true;
    }

//Printing Divisors of A Number
 void printDivisors(int n)
{
	for(int i=1; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			cout<<i<<" ";

        
			if(i != (n / i))
				cout<<(n / i)<<" ";					
		}
	}
}

//Sieve of Erathosthenes
 void sieve(int n)
{
	if(n <= 1)
		return;

	bool isPrime[n+1];
	fill(isPrime, isPrime + n + 1, true);

	for(int i=2; i*i <= n; i++)
	{
		if(isPrime[i])
		{
			for(int j = 2*i; j <= n; j = j+i)
			{
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i<=n; i++)
	{   
		if(isPrime[i])
			cout<<i<<" ";
	}
}

//Computing Power
 int power(int x, int n)
{
	if(n == 0)
		return 1;

	int temp = power(x, n/2);
	temp = temp * temp;

	if(n % 2 == 0)
		return temp;
	else
		return temp * x; 
}

//Calculate (x^n) in O(log n) Time Complextity
int power(int x, int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
            res=(res*x);
        x=(x*x); 
        n=n>>1;
    }
    return res;
}

// Returns sum of first n natural numbers
int recurSum(int n)
{
    if (n <= 1)
        return n;
    return n + recurSum(n - 1);
}

//Factorial Using Recursion
int factorial(int N)
{  if(N<=1) return 1;  
       return N*factorial(N-1);
  }

//Sum of Digits
int sumOfDigits(int n)
{
   if(n%10==n) return n;
       return n%10 + sumOfDigits(n/10);
 }

// nCr 
int nCr(int n,int r)
{
    if(n==r or r==0) 
		return 1;
 	return nCr(n-1, r-1)+nCr(n-1, r);
}

//Quadratic Roots of a Mathematical Equation
 vector<int> quadraticRoots(int a, int b, int c) {
       
       long long d = (b*b)-4*a*c;
       vector<int>v1;
       
       if(d<0) v1.push_back(-1);
       
       else 
       {
           int x1 = floor((-b+sqrt(d))/(2*a));
           int x2 = floor((-b+sqrt(d))/(2*a));
           v1.push_back(x1);
           v1.push_back(x2);
       }
       
       sort(v1.begin(),v1.end(), greater<int>());
       return v1; 
    }
