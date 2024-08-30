#include <stdio.h>
#include <math.h>


// EXERCISE 1:
// what is the sum of multiples of 3 and 5 from 1 to 1000?
int PA1(int start, int end);

void Multiplesof3or5(void)
{
    // brute force
    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (!(i % 3) || !(i % 5)) sum += i;
    }
    printf("%d\n", sum);

    // arithmetic progression
    printf("%d\n", PA1(1, 1000/3) * 3 + PA1(1, 1000/5) * 5 - PA1(1, 1000/15) * 15);
}

int PA1(int start, int end)
{
    return (start + end) * (end - start + 1)/2;
}



// EXERCISE 2:
// what is the sum of all even numbers smaller than 4000000 in fibonacci order
void EvenFibonacciNumbers(void)
{
    unsigned int prev2 = 1;
    unsigned int prev1 = 2;
    unsigned long long int sum = 0;
    unsigned int temp;

    while (prev1 < 4000000)
    {
        sum += prev1 % 2 ? 0:prev1;

        temp = prev1;
        prev1 = prev1 + prev2;
        prev2 = temp;
    }

    printf("%d\n", sum);
}



// EXERCISE 3:
// what is the largest prime factor of 600851475143
unsigned long long int sqrtfloor(unsigned long long int n);
int isprime(unsigned long long n);

#define NUMBER 600851475143

void LargestPrimeFactorWORKFORTHISCASE(void)
{
    unsigned long long int n = sqrtfloor(NUMBER);
    n += n%2 ? 0:-1;

    for (;n >= 2; n-=2)
    {
        if (!(NUMBER % n))
        {
            if(isprime(n))
            {
                printf("%llu\n", n);
                return;
            }
        }
    }
    printf("%llu\n", NUMBER);
}

void LargestPrimeFactor(void)
{
    unsigned long long int n = NUMBER;
    
    if (isprime(n))
    {
        printf("%d\n", n);
    }
    
    /*
      goes through all primes and divide untill the number is not divisible by the prime anymore
    */

    while (!(n % 2)) n /= 2;
    if (n==1) 
    {
        printf("2\n");
        return;
    }

    for (int largestprime = 3; largestprime <= n; largestprime += 2)
    {
        if (isprime(largestprime))
        {
            while (!(n % largestprime)) n /= largestprime;
            if (n == 1) 
            {
                printf("%d\n", largestprime);
                return;
            }
        }
    }
}



// given a number, return true if it's prime, false otherwise
int isprime(unsigned long long n)
{

    /*
       square rooting to lower the number of iterations (is not necessary to search if the numbers after the
       square root are primes, because if one of the numbers after the sqrt are multiplying, it's multiplying
       another before the sqrt, never after)
    */

    if (n == 2 || n == 3) return 1;

    for (int i = 3, root = sqrtfloor(n); i <= root; i += 2)
    {
        if (!(n % i)) return 0;
    }
    return 1;
}

// given a number, return the floor of its square root
unsigned long long int sqrtfloor(unsigned long long int n)
{
    unsigned long long int left = 1;
    unsigned long long int right = n;

    // binary search
    while (left < right)
    {
        unsigned long long int mid = left + (right - left)/2;

        if (mid > n/mid) right = mid;
        else
        {
            if (mid + 1 > n/(mid + 1)) return mid;

            left = mid + 1;
        }
    }

    return right;
}