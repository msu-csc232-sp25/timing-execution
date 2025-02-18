/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

#ifndef MSU_CSC232_H
#define MSU_CSC232_H

#define FALSE 0
#define TRUE 1

#define EXECUTE_PREAMBLE TRUE

#define TEST_TASK1 FALSE
#define TEST_TASK2 FALSE
#define TEST_TASK3 FALSE
#define TEST_TASK4 FALSE
#define TEST_TASK5 FALSE

#include <algorithm>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

namespace naive
{
    /**
     * @brief Naive, recursive implementation, for finding the nth Fibonacci number.
     * @pre n > 0
     * @details
     * @verbatim
     * n      = 1  2  3  4  5  6 ...
     * fib(n) = 1  1  2  3  5  8 ...
     * @endverbatim
     * @param n an index into the Fibonacci sequence.
     * @return the nth Fibonacci number.
     */
    inline int fib( int n )
    {
        return ( n < 3 ? 1 : fib( n - 1 ) + fib( n - 2 ) );
    }
}

namespace top_down
{
    inline int fib(const int n, std::map<int, int>& fibMap)
    {
        if (fibMap.find(n) == fibMap.end()) // key n was not found, so compute its value
        {
            fibMap[n] = fib(n - 1, fibMap) + fib(n - 2, fibMap);
        }

        return fibMap[n];
    }

    inline int fib(const int n)
    {
        static std::map<int, int> fibMap{{0, 1}, {1, 1}};
        return fib(n, fibMap);
    }
}

namespace bottom_up
{
    inline int fib(const int n)
    {
        if (n < 3)
            return 1;

        int prevFib = 1;
        int currentFib = 1;
        for (int i = 2; i <= n; i++)
        {
            const int nextFib = prevFib + currentFib;
            prevFib = currentFib;
            currentFib = nextFib;
        }
        return currentFib;
    }
}

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

    // DO NOT Modify anything below this line

    int preamble( int argc, char * argv[] );

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string generate_uuid( )
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator( random_device( ) );

        std::uniform_int_distribution< int > dist( 0, 15 );

        const char * uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false,
                              true, false, true, false, false, false, false, false };

        std::string uuid;
        for ( bool dash_location: dash )
        {
            if ( dash_location )
                uuid += "-";
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
            uuid += uuid_alphabet[ dist( random_number_generator ) ];
        }
        return uuid;
    }
} // namespace csc232

#endif // MSU_CSC232_H
