#ifndef DEBUG_HXX
#define DEBUG_HXX

#ifdef DEBUG
#include <iostream>
#define DEBUG_LOG(x) do { std::cout << x; } while (false);
#define DEBUG_LINE(x) do { std::cout << x << std::endl; } while (false);
#define DEBUG_NEWLINE() do { std::cout << std::endl; } while (false);
#else
#define DEBUG_LOG(x) // no-op
#define DEBUG_LINE(x) // no-op
#define DEBUG_NEWLINE() // no-op
#endif // DEBUG

#endif // DEBUG_HXX
