#include <stdio.h>
#include "logger.h"

void info(const char* message) {
    printf("[INFO]  %s\n", message);
}

void warn(const char* message) {
    printf("[WARNING]  %s\n", message);
}

void error(const char* message) {
    printf("[ERROR]  %s\n", message);
    exit(1);
}


