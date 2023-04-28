#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "forward_list/forward_list.h"

/* Convert a decimal number to its binary equivalent. */
extern forward_list DecToBin(size_t decimal);


/* Convert a decimal number to its octal equivalent. */
extern forward_list DecToOct(size_t decimal);


/* Convert a decimal number to its hexadecimal equivalent. */
extern forward_list DecToHex(size_t decimal);


/* Convert a binary number to its decimal equivalent. */
extern size_t BinToDec(const char *binary);


/* Convert an octal number to its decimal equivalent. */
extern size_t OctToDec(const char *octal);


/* Convert a hexadecimal number to its decimal equivalent. */
extern size_t HexToDec(const char *hexadecimal);


/* Convert a binary number to its octal equivalent. */
extern forward_list BinToOct(const char *binary);


/* Convert a binary number to its hexadecimal equivalent. */
extern forward_list BinToHex(const char *binary);


/* Convert an octal number to its binary equivalent. */
extern forward_list OctToBin(const char *octal);


/* Convert an octal number to its hexadecimal equivalent. */
extern forward_list OctToHex(const char *octal);


/* Convert a hexadecimal number to its binary equivalent. */
extern forward_list HexToBin(const char *hexadecimal);


/* Convert a hexadecimal number to its octal equivalent. */
extern forward_list HexToOct(const char *hexadecimal);


#endif
