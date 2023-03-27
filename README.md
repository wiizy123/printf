The printf project is a collaboration between Isaiah Bana and Samuel Kusi-Aborah

***** MAIN.H *****

1. A new header file called main.h is created and defined
2. In this main.h file, all needed header files are include guarded. 
3. Defined macros for bit flags used to represent various formatting printf options
	F_MINUS 1: Indicates left- justification of the output
	F_PLUS 2: Indicates that the add or sub signs should always be displayed for signed conversions. 	F_ZERO 4: Indicates that the field should be zero-padded instead of space-padded
	F_HASH 8: Indicates that the value should be displayed with an alternative form
	F_SPACE 16: Indicates that a space should be used for positive values instead of a plus sign
4. Defined macros for length modifiers used in printf
	S_SHORT 1: Indicates that the argument for the conversion specifier is a short int.
	S_LONG 2: Indicates that the argument for the conversion specifier is a long int.
5. Define macros called UNUSED and BUFF_SIZE
	UNUSED: This is used suppress compiler warnings about unused variables. 
	BUFF_SIZE: defines a constant with value of 1024 which is used to specify the size of a buffer in the code. 
