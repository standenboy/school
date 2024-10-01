#include <stddef.h>
extern size_t STRINGSPLITCOUNT;
typedef struct string string;
typedef struct string {
	char *_str; // not null terminated string, length encoded
	size_t _len;
	void (*free)(string*);	
	void (*appendchar)(string *, char);
	int (*insert)(string *, string *, size_t);
	void (*replacechar)(string *, char, char);
	int (*countchar)(string *, char);
	int (*cmp)(string *, string*);
	void (*fromcstring)(string *, char *);
	char *(*tocstring)(string *);
	string **(*split)(string *, char);
	void (*print)(string *);
	void (*input)(string *, size_t);
} string;

string *String(char *cstring);
void __stringfree(string *self);
void __stringappendchar(string *self, char c);
int __stringinsert(string *self, string *substring, size_t point);
void __stringreplacechar(string *self, char orig, char new);
int __stringcountchar(string *self, char c);
int __stringcmp(string *str1, string *str2);
void __stringfromcstring(string *self, char *cstring);
char *__stringtocstring(string *self);
string **__stringsplit(string *self, char delim);
void *print(string *self);
void *input(string *self, size_t len);

