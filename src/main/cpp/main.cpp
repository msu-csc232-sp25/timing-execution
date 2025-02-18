/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 202 James R. Daehn
 */

#include "csc232.h"


int main( int argc, char * argv[] )
{
    std::ofstream out_file;
    out_file.open("../fib.csv");
    out_file << "n,naive::fib(n),top_down::fib(n),bottom_up::fib(n)" << std::endl;
    for ( auto n = 1; n <= 40; ++n)
    {
        naive::fib(1);
        // Get the starting time
        auto start = std::chrono::high_resolution_clock::now();
        // Execute some code
        auto result = naive::fib( n);
        // Get the ending time
        auto end = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        std::chrono::duration<double> duration = end - start;
        // Output the duration in seconds
        out_file << n << "," << duration.count() << ",";

        // collect top-down data
        top_down::fib(1);
        start = std::chrono::high_resolution_clock::now();
        result = top_down::fib( n);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        out_file << duration.count() << ",";

        // collect bottom-up data
        bottom_up::fib(1);
        start = std::chrono::high_resolution_clock::now();
        result = bottom_up::fib( n);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        out_file << duration.count() << std::endl;
    }
    out_file.close();
    return EXIT_SUCCESS;
}
