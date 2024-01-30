# Printf

The printf function is a built-in C language function that can be found in the <stdio.h> library and is used to print formatted data to the standard output.

The printf function can take in a variable number of arguments and prints the formatted data to the screen. These arguments can span the whole range of any data type that the C programming language recognises from; strings, to integers, to character, to user-defined data types and even acts accordingly to any escape sequence. Formatted strings are also included in these identifiers.

These are the two arguments that the printf() function accepts:

	1. Format Specifier / format string

		A string that speciefes as to which data should be printed

	2. Arugment
		
		These are the variables that can be identified by the format specifier.

Syntax:

	printf("%FormatSpecifier", argumemt);

Example:

	printf("%d\n", 8);

	printf() =	The printf function
	""	 =	Tells the printf function where the format specifier begins and ends
	%d	 =	Format specifier
	\n	 = 	Escape sequence, in this case a newline
	8	 =	The argument passed to the printf functon

This example will print the result of '8' to the standard output (stdout (1)) and ends with a newline.
Another use of the printf() function is to print normal string without arguments.

Example:

	printf("Hello World\n");

This will result in the words "Hello World", being printed out to standard output ending with a newline character. 

# Write

The write function is a system call responsible for printing information to the standard output / sending messages to other users terminals.

Syntax:

	write((an int)output display, variable to be printed, (an int) length of variable);

Example:

	write(1, "hello world", 5)

	write() 	=	The function call
	1		=	Where the variable will be displayed
	"hello world"   =	The variable, in this case it's a string
	5		=	The length of the data being printed

This output will result in the stdout(1) printing "hello", as the length specified was 5.
