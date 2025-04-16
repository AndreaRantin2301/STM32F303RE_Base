#include <stdint.h>

/**
 * @brief Utility function to avoid using stdlib
 * 
 * @param str String of which we need to calculate the length
 * @return Length of the string
 */
uint16_t custom_strlen(const char *str);