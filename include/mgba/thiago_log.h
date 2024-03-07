#ifndef _MGBA_THIAGO_LOG_H
#define _MGBA_THIAGO_LOG_H

#include <stdio.h>

// #define TLOG(fmt, ...) do { \
//     printf("" fmt "\n", ##__VA_ARGS__); \
//     fflush(stdout); \
// } while (0)

// #define TWARN(fmt, ...) do { \
//     fprintf(stderr, "[WARNING]: " fmt "\n", ##__VA_ARGS__); \
//     fflush(stderr); \
// } while (0)

#define TLOG(fmt, ...) do { } while (0)
#define TWARN(fmt, ...) do { } while (0)

#endif // _MGBA_THIAGO_LOG_H
