#include "lem_in.h"

static bool check_extension(char *filename)
{
    int i;

    i = 0;
    while (filename[i])
        i++;
    if (filename[i - 1] != 'p' 
        || filename[i - 2] != 'a' 
        || filename[i - 3] != 'm' 
        || filename[i - 4] != '.')
    {
        ft_putstr_fd("\033[1;31mError: Please use a .map file.\n\033[0m", 2);
        return (false);
    }
    return (true);
}

static bool check_arguments(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_putstr_fd("\033[1;31mUsage: ./lem-in [file].\n\033[0m", 2);
        return (false);
    }
    if (!check_extension(argv[1]))
        return (false);
    return (true);
}

int main(int argc, char **argv)
{
    char **data;

    if (!check_arguments(argc, argv))
        return (EXIT_FAILURE);

    data = get_data(argv[1]);
    if (!data)
        return (EXIT_FAILURE);
        
    parse_data(data);

    return (EXIT_SUCCESS);
}
