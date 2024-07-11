
// functions for user
void Die(); // brings down the program
void *CheckedMalloc(long size); // malloc checked with autofree
void *CheckedRealloc(void *out, long size); // realloc checked with autofree

literal *giveType(char *tok); // gives a string a type

// gives strings types
I64 *isNum(char *str); 
Float *isFloat(char *str);
Char *isChar(char *str);
literal *isArr(char *str);
Vdef *isVdef(char *str);
