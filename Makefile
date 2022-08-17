debug :=

<< = @echo
%: %.c
	$(<<) " CC " $(<)
	@gcc $(<) -o $(@) -lm -g
	$(<<) "RUN " $(@)
	@ test "$(debug)" = "" && ./$(@) || gdb ./$(@)
	@ rm $(@)

all:
	$(<<) "How to use this repo"
	$(<<)
	$(<<) "make [solve-file-without-extension [...]]"
	$(<<)
	$(<<) "Example: "
	$(<<) "make 1001-opposite-task"

clean: $(wildcard *.c)
	rm -f $(^:%.c=%)

.PHONY: clean
