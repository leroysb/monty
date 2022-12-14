# The Monty Language (Stacks, Queues - LIFO, FIFO)
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

## Resources
1. [How do I use extern to share variables between source files in C](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
2. [Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
3. [Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)
4. [Queue operations](https://www.edureka.co/blog/queue-in-c/)

## Compilation & Output
* The code must be compiled this way: `$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
* Any output must be printed on `stdout`
* Any error message must be printed on `stderr`. [Here is a link to a GitHub repository](https://github.com/sickill/stderred) illustrating how to make sure your errors are printed on `stderr`

## Tasks
### 0. push, pall
Implement the `push` and `pall` opcodes.

**The push opcode**

The opcode `push` pushes an element to the stack.
* Usage: `push <int>`, where `<int>` is an integer
* if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`, where is the line number in the file
* You won’t have to deal with overflows. Use the `atoi` function

**The pall opcode**

The opcode `pall` prints all the values on the stack, starting from the top of the stack.
* Usage `pall`
* Format: see example
* If the stack is empty, don’t print anything

### 1. pint
Implement the `pint` opcode.

**The pint opcode**

The opcode `pint` prints the value at the top of the stack, followed by a new line.
* Usage: `pint`
* If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 2. pop
Implement the `pop` opcode.

**The pop opcode**

The opcode `pop` removes the top element of the stack.
* Usage: pop
* If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 3. swap
Implement the swap opcode.

**The swap opcode**

The opcode `swap` swaps the top two elements of the stack.
* Usage: `swap`
* If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

### 4. add
Implement the `add` opcode.

**The add opcode**

The opcode `add` adds the top two elements of the stack.
* Usage: `add`
* If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end: The top element of the stack contains the result, The stack is one element shorter.

### 5. nop
Implement the `nop` opcode.

**The nop opcode**

The opcode `nop` doesn’t do anything.
* Usage: `nop`
