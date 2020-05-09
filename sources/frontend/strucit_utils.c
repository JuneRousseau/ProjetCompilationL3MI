#include "strucit_utils.h"

int cpt_label;
int error;

char *ajouter_code(char *code_genere, char *str){
  int new_size= strlen(code_genere)+strlen(str)+1;
  char *new_code = (char *)malloc(new_size);
  strcpy(new_code, code_genere);
  strcat(new_code, str);
  return new_code;
}

char *init_code(char *code_genere){
    code_genere = (char *) malloc(0);
    return code_genere;
}

char *concatener(char *strs, ...)
    {
	char *dest = strs;
	va_list ap;
	va_start(ap, strs);
	strs = va_arg(ap, char*);

	while(strs != NULL) {
	    dest = ajouter_code(dest, strdup(strs));
	    strs = va_arg(ap, char*);
	};

	va_end(ap);
	return dest;
    }

void init_error(){error=0;}
int get_error_code(){return error;}
void set_error_code(int n){error=n;}
