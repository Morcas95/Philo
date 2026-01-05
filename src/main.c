#include "philo.h"

int main(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
    {
        print_error("Only 5 or 6 arguments to be entered.\n");
        return (1);
    }
    check_input(argc, argv);
    return (0);
}