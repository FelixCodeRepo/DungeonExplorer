#include "Random.hpp"
#include <cstdlib>
#include <ctime>

int random_num(const int start, const int end)
{
    srand(time(NULL)); // seed the random number generator with the current time
    return rand() % (end - start + 1) + start;
}