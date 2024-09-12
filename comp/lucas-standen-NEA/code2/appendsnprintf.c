#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *genfmt(char *buf, char *fmt){
	int len = strlen(buf) + strlen(fmt) + 1;
	char *out = malloc(len);

	int j = 0, i = 0;	
	while (buf[i] != '\0'){
		out[i] = buf[i];
		i++;
	}
	while (fmt[j] != '\0'){
		out[i] = fmt[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return out;
}

char *appendsnprintf(char *buf, int size, char *format, ...){
	va_list ap;
	char *outputbuf = malloc(size);
	va_start(ap, format);
	char *fmt = genfmt(buf, format);
	vsnprintf(outputbuf, size, fmt, ap);
	free(fmt);
	
	buf = realloc(outputbuf, strlen(outputbuf) + 1);
	va_end(ap);
	
	return buf;
}
