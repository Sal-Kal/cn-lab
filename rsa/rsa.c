#include <stdio.h>
#include <math.h>

double encrypt(double m, double e, double n)
{
    return fmod(pow(m, e), n);
}

double decrypt(double c, double d, double n)
{
    return fmod(pow(c, d), n);
}

double gcd(int n1, int n2)
{
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}

void main()
{
    double p = 3, q = 7, e, d, m, c, r, phi, n, k = 2;
    phi = (p - 1) * (q - 1);
    n = p * q;

    e = 2;
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    m = 12;

    d = (1 + (k * phi)) / e;

    c = encrypt(m, e, n);

    printf("The cipher text is : %f", c);

    r = decrypt(c, d, n);

    printf("\nThe decrypted message is %f", r);
}