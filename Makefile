debug :=

<< = @echo

%.out: %
%.out: %.o
	@ $(<<) "LINK" $(<)
	@ $(CXX) $(<) -o $(@) -g
	@ $(<<) " RUN" $(@)
	@ test "$(debug)" = "" && ./$(@) || gdb ./$(@)
#	@ rm $(@)

%.c.o: %.c
	@ $(<<) "  CC" $(<)
	@ $(CC) -c $(<) -o $(@) -g

%.cpp.o: %.cpp
	@ $(<<) " CXX" $(<)
	@ $(CXX) -c $(<) -o $(@) -g

all:
	$(<<) "How to use this repo"
	$(<<)
	$(<<) "make [solve-file.out [...]]"
	$(<<)
	$(<<) "Example: "
	$(<<) "make 1001-opposite-task"

clean:
	@rm -f *.out *.o

.PHONY: clean
