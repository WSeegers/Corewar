# Corewars

wseegers
pstubbs
kmarchan
gsteyn

## Introduction
• Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one an- other with the support of “processes”, with the objective being for these champions to stay “alive”.

• The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...

• The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

Following are the instructions bots are limited too.

| Instructions  | Descriptions from WeThinkCode PDF | 
| :-------------: |-----------------------------------|
|lfork|means long-fork, to be able to fork abut straw from a distance of 15 meters, exactly like with its opcode. Same as a fork without modulo in the address|
|sti|Opcode 11. Take a registry, and two indexes (potentially registries) add the two indexes, and use this result as an address where the value of the first parameter will be copied.|
|fork|there is no argument’s coding byte, take an index, opcode 0x0c. Create a new process that will inherit the different states of its father, except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).|
|lld|Means long-load, so it’s opcode is obviously 13. It the same as ld, but without % IDX_MOD. Modify the carry.|
|ld|Take a random argument and a registry. Load the value of the first argument in the registry. Its opcode is 10 in binary and it will change the carry.|
|add|Opcode 4. Take three registries, add the first two, and place the result in the third, right before modifying the carry.|
|zjmp|there’s never been, isn’t and will never be an argument’s coding byte behind this operation where the opcode is 9. It will take an index and jump to this address if the carry is 1.|
|sub|Same as add, but with the opcode est 0b101, and uses a substraction.|
|ldi|ldi, ldi, as per the name, does not imply to go swimming in chestnut cream, even if its code is 0x0a. Instead, it will use 2 indexes and 1 registry, adding the first two, treating that like an address, reading a value of a registry’s size and putting it on the third.|
|or|This operation is an bit-to-bit OR, in the same spirit and principle of and, its opcode is obviously 7.|
|st|take a registry and a registry or an indirect and store the value of the registry toward a second argument. Its opcode is 0x03. For example, st r1, 42 store the value of r1 at the address (PC + (42 % IDX_MOD))|
|aff|The opcode is 10 in the hexadecimal. There is an argument’s coding byte, even if it’s a bit silly because there is only 1 argument that is a registry, which is a registry, and its content is interpreted by the character’s ASCII value to display on the standard output. The code is modulo 256.|
|live|The instruction that allows a process to stay alive. It can also record that the player whose number is the argument is indeed alive. No argument’s coding byte, opcode 0x01. Oh and its only argument is on 4 bytes.|
|xor|Acts like and with an exclusive OR. As you will have guessed, its opcode in octal is 10.|
|lldi|Opcode 0x0e. Same as ldi, but does not apply any modulo to the addresses. It will however, modify the carry.|
|and|Apply an & (bit-to-bit AND) over the first two arguments and store the result in a registry, which is the third argument. Opcode 0x06. Modifies the carry.|

---

# The Assembler
This is the program that will compile your champions and translate them from the language you will write them in (assembly language) into “Byte-code”.Bytecode is a machine code, which will be directly interpreted by the virtual machine.

#### Following are the special flags we have added to our "asm".
```
./asm -[flag] zork.s
```

|-t (tokens) | -i (instructions) | -v (verbose) |
|-----------------------------------|-----------------------------------|-----------------------------------|
|<img width="318" alt="screen shot 2018-09-20 at 09 57 06" src="https://user-images.githubusercontent.com/24510543/45803969-2de9bf80-bcbb-11e8-9bc5-298c567804c6.png">|<img width="429" alt="screen shot 2018-09-20 at 09 56 56" src="https://user-images.githubusercontent.com/24510543/45803972-2f1aec80-bcbb-11e8-950d-25dab8587655.png">|<img width="396" alt="screen shot 2018-09-20 at 09 56 31" src="https://user-images.githubusercontent.com/24510543/45803974-2fb38300-bcbb-11e8-9dd6-5c5446051b87.png">|

with no flags active this will be the output.

<img width="395" alt="screen shot 2018-09-20 at 09 53 12" src="https://user-images.githubusercontent.com/24510543/45803772-b1ef7780-bcba-11e8-816c-967d74296d5a.png">

A .cor will be created with the bot name.

#### The Following is the bytecode for bot "zork.cor"

<img width="687" alt="screen shot 2018-09-20 at 08 23 50" src="https://user-images.githubusercontent.com/24510543/45799640-82d30900-bcae-11e8-95d3-783d7581dbce.png">

---

# The Vm
The virtual machine: It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.

<img width="1650" alt="screen shot 2018-09-20 at 08 14 32" src="https://user-images.githubusercontent.com/24510543/45799585-4ef7e380-bcae-11e8-96db-551222cf704b.png">
