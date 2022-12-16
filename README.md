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
Implement the `push` which pushes an element to the stack. and `pall` opcodes which prints all the values on the stack, starting from the top of the stack.

**File**: [push.c](./push.c), [pall.c](./pall.c)

### 1. pint
Implement the `pint` opcode which prints the value at the top of the stack, followed by a new line.

**File**: [pint.c](./pint.c)

### 2. pop
Implement the `pop` opcode which removes the top element of the stack.

**File**: [pop.c](./pop.c)

### 3. swap
Implement the `swap` opcode which swaps the top two elements of the stack.

**File**: [swap.c](./swap.c)

### 4. add
Implement the `add` opcode which adds the top two elements of the stack.

**File**: [add.c](./add.c)

### 5. nop
Implement the `nop` opcode that doesn’t do anything.

**File**: [nop.c](./nop.c)

### 6. sub
Implement the `sub` opcode that subtracts the top element of the stack from the second top element of the stack.

**File**: [sub.c](./sub.c)

### 7. div
Implement the `div` opcode that divides the second top element of the stack by the top element of the stack.

**File**: [div.c](./div.c)

### 8. mul
Implement the `mul` opcode that multiplies the second top element of the stack with the top element of the stack.

**File**: [mul.c](./mul.c)

### 9. mod
Implement the `mod` opcode that computes the rest of the division of the second top element of the stack by the top element of the stack.

**File**: [mod.c](./mod.c)

### 10. comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

### 11. pchar
Implement the `pchar` opcode that prints the char at the top of the stack, followed by a new line.

**File**: [pchar.c](./pchar.c)

### 12. pstr
Implement the `pstr` opcode prints the string starting at the top of the stack, followed by a new line

**File**: [pstr.c](./pstr.c)

### 13. rotl
Implement the `rotl` opcode that rotates the stack to the top.

**File**: [rotl.c](./rotl.c)

### 14. rotr
Implement the `rotr` opcode that rotates the stack to the bottom.

**File**: [rotr.c](./rotr.c)

### 15. stack, queue
Implement the `stack` opcode that sets the format of the data to a stack (LIFO) the default behavior of the program, and the `queue` opcode that sets the format of the data to a queue (FIFO).

### 16. Brainf*ck
Write a Brainf*ck script that prints `School`, followed by a new line.
* All your Brainf*ck files should be stored inside the bf sub directory
* You can install the bf interpreter to test your code: `sudo apt-get install bf`
* Read: [Brainf*ck](https://en.wikipedia.org/wiki/Brainfuck)

**File**: [1000-school.bf](./1000-school.bf)

### 17. Add two digits (Brainf*ck)
Reads two digits from stdin, adds them, and print the result
* The total of the two digits with be one digit-long (<10)

**File**: [1001-add.bf](./1001-add.bf)

### 18. Multiplication (Brainf*ck)
Reads two digits from stdin, multiplies them, and print the result
* The result of the multiplication will be one digit-long (<10)

**File**: [1002-mul.bf](./1002-mul.bf)

### 19. Multiplication level up (Brainf*ck)
Reads the two digits from stdin, multiply them, and print the result, followed by a new line

**File**: [1003-mul.bf](./1003-mul.bf)