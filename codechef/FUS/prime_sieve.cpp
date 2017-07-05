int N = 2000001;
int prime[2000001] = {0};

void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    int i = 2,j;
    while(i*i <= N)
    {
        j = 2*i;
        if (prime[i] != 1)
        {
            while (j<N)
            {
                prime[j] = 1;
                j += i;
            }
        }
        i += 1;
    }
}

