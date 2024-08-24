#include "lem_in.h"

static bool check_arguments(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("\033[1;31mUsage: %s [file]. Please use a .map file.\n\033[0m", argv[0]);
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    if (!check_arguments(argc, argv))
        return (1);
    // if (!parse_file(argv[1]))
    //     return (1);
    return (0);
}
