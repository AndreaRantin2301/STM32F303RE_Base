#include "utils/string_utils.h"

uint16_t custom_strlen(const char *str) {
    uint16_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}