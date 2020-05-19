PROG_NAME=structfe
LEX_FILE=ANSI-frontend.l

all: $(PROG_NAME).out

$(PROG_NAME).out: lex.yy.c $(PROG_NAME).tab.c strucit_utils.o strucit_type.o strucit_symbols.o strucit_errors.o
	gcc -o $@ $^ -lfl

$(PROG_NAME).tab.c: $(PROG_NAME).y
	bison -v -d $(PROG_NAME).y

lex.yy.c: $(LEX_FILE)
	flex $(LEX_FILE)

%.o: %.c
	@(gcc -o $@ -c $<)


.PHONY: clean mrproper

clean:
	rm -rf *.o $(PROG_NAME).tab.* lex.yy.c $(PROG_NAME).output

mrproper:
	rm -rf *.o $(PROG_NAME).tab.* lex.yy.c $(PROG_NAME).output $(PROG_NAME).out
