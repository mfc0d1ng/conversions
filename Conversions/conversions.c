#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "conversions.h"


forward_list DecToBin(size_t decimal)
{
	forward_list binary = NULL;
	while(decimal)
	{
		push_front(&binary, decimal % 2 + 48);
		decimal /= 2;
	}
	return binary;
}


forward_list DecToOct(size_t decimal)
{
	forward_list octal = NULL;
	while(decimal)
	{
		push_front(&octal, decimal % 8 + 48);
		decimal /= 8; 
	}
	return octal;
}


forward_list DecToHex(size_t decimal)
{
	forward_list hexadecimal = NULL;
	signed char decimal_val = 0;
	while(decimal)
	{
		decimal_val = decimal % 16;
		if(decimal_val < 10)
		{
			push_front(&hexadecimal, decimal_val + 48);
		}
		else
		{	
			push_front(&hexadecimal, decimal_val + 87);
		}
		decimal /= 16; 
	}
	return hexadecimal;
}


size_t BinToDec(const char *binary)
{
	if(!strncmp(binary, "0b", 2))
	{
		binary += 2; 
	}
	int it = strlen(binary); 
	int counter = 0; 
	size_t decimal = 0;
	size_t base = 1;
	while(it)
	{
		it--;
		if(binary[it] == '0' || binary[it] == '1')
		{
			decimal += base * (binary[it] - 48);
			base *= 2; 
			counter++;
		}
		else
		{
			printf("Invalid binary digit '%c'\n", binary[it]);
			exit(EXIT_FAILURE); 
		}
		if(counter == 65)
		{
			printf("Warning: too large binary number => s\"0b%s\"\n", binary); 
			decimal = ULLONG_MAX; 
			break; 
		}
	}
	return decimal; 
}


size_t OctToDec(const char *octal)
{
	if(!strncmp(octal, "0o", 2))
	{
		octal += 2; 
	}
	int it = strlen(octal); 
	int counter = 0; 
	size_t decimal = 0;
	size_t base = 1;
	while(it)
	{
		it--;
		if(octal[it] >= '0' && octal[it] < '8')
		{
			decimal += base * (octal[it] - 48);
			base *= 8; 
			counter++;
		}
		else
		{
			printf("Invalid octal digit '%c'\n", octal[it]);
			exit(EXIT_FAILURE); 
		}
		if(counter == 23)
		{
			printf("Warning: too large octal number => \"0o%s\"\n", octal); 
			decimal = ULLONG_MAX;
			break; 
		}
	}
	return decimal; 
}


size_t HexToDec(const char *hexadecimal)
{
	if(!strncmp(hexadecimal, "0x", 2))
	{
		hexadecimal += 2; 
	}
	int it = strlen(hexadecimal); 
	int counter = 0; 
	size_t decimal = 0;
	size_t base = 1;
	while(it)
	{
		it--;
		if(hexadecimal[it] >= '0' && hexadecimal[it] <= '9')
		{
			decimal += base * (hexadecimal[it] - 48);
			base *= 16; 
			counter++;
		}
		else if(hexadecimal[it] >= 'a' && hexadecimal[it] < 'g')
		{
			decimal += base * (hexadecimal[it] - 87); 
			base *= 16; 
			counter++;
		}
		else if(hexadecimal[it] >= 'A' && hexadecimal[it] < 'G')
		{
			decimal += base * (hexadecimal[it] - 55); 
			base *= 16; 
			counter++;
		}
		else
		{
			printf("Invalid hexadecimal symbol '%c'\n", hexadecimal[it]);
			exit(EXIT_FAILURE); 
		}
		if(counter == 17)
		{
			printf("Warning: too large hexadecimal number => \"0x%s\"\n", hexadecimal); 
			decimal = ULLONG_MAX;
			break; 
		}
	}
	return decimal; 
}



forward_list BinToOct(const char *binary)
{
	return DecToOct(BinToDec(binary));
}


forward_list BinToHex(const char *binary)
{
	return DecToHex(BinToDec(binary));
}


forward_list OctToBin(const char *octal)
{
	return DecToBin(OctToDec(octal));
}


forward_list OctToHex(const char *octal)
{
	return DecToHex(OctToDec(octal));
}


forward_list HexToBin(const char *hexadecimal)
{
	return DecToBin(HexToDec(hexadecimal));
}


forward_list HexToOct(const char *hexadecimal)
{
	return DecToOct(HexToDec(hexadecimal));
}


