all: tokenizer

tokenizer: tokenizer.c history.c ui.c
	gcc $^ -o $@

clean:
	rm -f *.o *.c~ tokenizer 
