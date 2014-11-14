GCC=gcc
CFLAGS=-g -Wall -Werror

all: re

re: List.o Stack.o State.o Regex.o re.c
	$(GCC) $(CFLAGS) List.o Stack.o State.o Regex.o re.c -o re

test: testRe testList testStack testState

testRe: List.o Stack.o State.o Regex.o testRegex.c
	$(GCC) $(CFLAGS) List.o Stack.o State.o Regex.o testRegex.c -o testRe

testList: List.o State.o testList.c
	$(GCC) $(CFLAGS) List.o State.o testList.c -o testList

testStack: List.o Stack.o State.o testStack.c
	$(GCC) $(CFLAGS) List.o Stack.o State.o testStack.c -o testStack

testState: List.o Stack.o State.o testState.c
	$(GCC) $(CFLAGS) List.o Stack.o State.o testState.c -o testState

Regex.o: Regex.c
	$(GCC) $(CFLAGS) -c Regex.c

State.o: State.c
	$(GCC) $(CFLAGS) -c State.c

List.o: Item.h List.c
	$(GCC) $(CFLAGS) -c List.c

Stack.o: StackItem.h Stack.c
	$(GCC) $(CFLAGS) -c Stack.c

clean:
	rm -rf *.o re testRe testList testStack testState
