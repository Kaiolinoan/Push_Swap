int ft_atol(char *str)
{
    long nb;
    int signal;
    size_t i;

    while (str[i] >= 9 && str[i] <= 13  || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            signal *= -1;
        }
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (signal * nb);
}