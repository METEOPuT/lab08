#include <iostream>
#include <fstream>
#include "formatter_ex.h"
#include "solver.h"

int main()
{
    float a = 1;
    float b = 2;
    float c = 1;

    //std::cin >> a >> b >> c;

    float x1 = 0;
    float x2 = 0;

    try
    {
        solve(a, b, c, x1, x2);

        formatter(std::cout, "x1 = " + std::to_string(x1));
        formatter(std::cout, "x2 = " + std::to_string(x2));

	std::ofstream log("/home/logs/log.txt");

	formatter(log, "x1 = " + std::to_string(x1));
	formatter(log, "x2 = " + std::to_string(x2));
    }
    catch (const std::logic_error& ex)
    {
        formatter(std::cout, ex.what());
    }

    return 0;
}
