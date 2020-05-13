PROG_NAME=structbe
LEX_FILE=ANSI-backend.l

all: $(PROG_NAME).out

$(PROG_NAME).out: lex.yy.c $(PROG_NAME).tab.c
	gcc -o $@ $^ -lfl

$(PROG_NAME).tab.c: $(PROG_NAME).y
	bison -v -d $<

lex.yy.c: $(LEX_FILE)
	flex $(LEX_FILE)


.PHONY: clean mrproper

clean:
	rm -rf *.o $(PROG_NAME).tab.* lex.yy.c $(PROG_NAME).output

mrproper:
	rm -rf *.o $(PROG_NAME).tab.* lex.yy.c $(PROG_NAME).output $(PROG_NAME).out	
