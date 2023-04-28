#include <stdio.h>
#include <stdlib.h>
#include "conversions.h"


int main()
{
	
	signed char storage[100];
	forward_list equivalent = NULL;
	
	size_t decimal = 0; 
	int op;
	int exit_status = EXIT_SUCCESS;
	
	puts( "Welcome to my calculator (programmer mode only)." );
	puts( "(This is a list of all valid operations)" );
	puts( "0.  Convert binary to octal." );
	puts( "1.  Convert binary to decimal." );
	puts( "2.  Convert binary to hexadecimal." );
	puts( "3.  Convert octal to binary." ); 
	puts( "4.  Convert octal to decimal." );
	puts( "5.  Convert octal to hexadecimal." );
	puts( "6.  Convert decimal to binary." );
	puts( "7.  Convert decimal to octal." );
	puts( "8.  Convert decimal to hexadecimal." );
	puts( "9.  Convert hexadecimal to binary." );
	puts( "10. Convert hexadecimal to octal." );
	puts( "11. Convert hexadecimal to decimal." );
	puts( "12. Close the program.\n" );
		
	while(1)
	{
		printf("Select one operation: ");
		scanf("%i", &op);
		
		if(op < 0 || op > 11)
		{
			if(op == 12)
			{
				puts("Program terminated."); 
			}
			else
			{
				puts("Invalid operation... program terminated."); 
				exit_status = EXIT_FAILURE; 
			}
			break;
		}
		
		switch(op)
		{			 
			case 0:
				printf("Enter a binary number: ");
				scanf("%99s", storage);
				equivalent = BinToOct(storage);
				break;
			case 1:
				printf("Enter a binary number: ");
				scanf("%99s", storage);
				decimal = BinToDec(storage);
				break;
			case 2:
				printf("Enter a binary number: ");
				scanf("%99s", storage); 
				equivalent = BinToHex(storage);
				break;
			case 3:
				printf("Enter an octal number: ");
				scanf("%99s", storage); 
				equivalent = OctToBin(storage);
				break;
			case 4:
				printf("Enter an octal number: ");
				scanf("%99s", storage);  
				decimal = OctToDec(storage);
				break;
			case 5:
				printf("Enter an octal number: ");
				scanf("%99s", storage);  
				equivalent = OctToHex(storage);
				break;
			case 6:	
				printf("Enter a decimal number: ");
				scanf("%lu", &decimal);  
				equivalent = DecToBin(decimal);
				break;
			case 7:	
				printf("Enter a decimal number: ");
				scanf("%lu", &decimal);  
				equivalent = DecToOct(decimal);
				break;
			case 8:	
				printf("Enter a decimal number: "); 
				scanf("%lu", &decimal);  
				equivalent = DecToHex(decimal);
				break;
			case 9:	
				printf("Enter a hexadecimal number: "); 
				scanf("%99s", storage);  
				equivalent = HexToBin(storage);
				break;
			case 10:	
				printf("Enter a hexadecimal number: "); 
				scanf("%99s", storage);  
				equivalent = HexToOct(storage);
				break;
			case 11:	
				printf("Enter a hexadecimal number: "); 
				scanf("%99s", storage);  
				decimal = HexToDec(storage);
				break;
				
		}
		
		if(equivalent)
		{
			display(equivalent);
			erase(&equivalent);
		}
		else
		{
			printf("%lu\n", decimal);
			decimal = 0;
		}
		
	}	
	
	return exit_status;
}
