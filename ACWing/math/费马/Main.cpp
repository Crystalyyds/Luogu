long long PowMod(long long a, int b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}
