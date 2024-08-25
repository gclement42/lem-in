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
        print_error("Please use a .map file.\n");
        return (false);
    }
    return (true);
}

static bool check_arguments(int argc, char *filename)
{
    if (argc != 2)
    {
        print_error("Usage: ./lem-in [file].\n");
        return (false);
    }
    if (!check_extension(filename))
        return (false);
    return (true);
}

int main(int argc, char **argv)
{
    char **data;
    t_lem_in lem_in;

    if (!check_arguments(argc, argv[1]))
        return (EXIT_FAILURE);

    data = get_data(argv[1]);
    if (!data)
        return (EXIT_FAILURE);
        
    lem_in = parse_data(data);
    printf("Number of ants: %d\n", lem_in.ants);
    return (EXIT_SUCCESS);
}
