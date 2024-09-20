#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "util.h"
#include "parser.h"
#include "comp.h"
#include "appendsnprintf.h"


char infilename[128];
char outfilename[128];
char libs[64][128];
int libcount = 0;
bool omitc = false;
char compilerflags[64][128];
int compilerflagscount = 0;

void processargs(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		if (argv[i][0] == '-'){
			switch (argv[i][1]){
				case 'o':
					i++;
					strcpy(outfilename, argv[i]);
					break;
				
				case 'i': 
					i++;
					strcpy(libs[libcount], argv[i]);
					libcount++;
					break;
				case 'c':
					omitc = true;
					break;
				case 'f':
					i++;
					strcpy(compilerflags[compilerflagscount], argv[i]);
					compilerflagscount++;
					break;
				default:
					die("unknown argument!");
					break;
			}
		}else strcpy(infilename, argv[i]);
	}
}

int main(int argc, char **argv){
	processargs(argc, argv);


	FILE *f = fopen(infilename, "r");
	if (f == NULL)
		die("no such file or directory");
	
	FILE *fout;
	if (omitc == false) {
		fout = fopen("./tmp.zpy.c", "w");
	}else {
		fout = fopen(outfilename, "w");
	}

	if (fout == NULL)
		die("no such file or directory");

	strings *stringTokens = parse(f);

	if (stringTokens == NULL)
		die("couldn't parse file, is it formated properly?");
	
	fprintf(fout, "#include <zpylib.h>\n");
	for (int i = 0; i < libcount; i++){
		fprintf(fout, "#include <%s>\n", libs[i]);
	}
	
	for (int i = 0; i < stringTokens->count; i++){
		stringTokens->strs[i]++;
		stringTokens->strs[i][strlen(stringTokens->strs[i]) - 1] = '\0';
		astNode *line = tokenize(stringTokens->strs[i]);
			
		Compile(line, fout);
	}
	fclose(fout);

	if (omitc == false){
		char *cmd = malloc(512);
		snprintf(cmd, 512, "cc ./tmp.zpy.c /usr/local/share/zpylib/*.o -o %s -I/usr/local/share/zpylib/include -Wno-implicit-function-declaration ", outfilename);
		for (int i = 0; i < compilerflagscount; i++){
			cmd = appendsnprintf(cmd, 512, "%s ", compilerflags[i]);
		}
		system(cmd);
		remove("./tmp.zpy.c");
	}
	
	
}
