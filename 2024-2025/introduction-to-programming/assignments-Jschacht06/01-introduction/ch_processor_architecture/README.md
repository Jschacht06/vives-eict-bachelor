# Processor Architecture

Search the Internet for the meaning of a "processor architecture". Find at least 3 different architectures. Try to find a small assembly example for each architecture.

## Solution

# Definition of a processor architecture:
The design and organization of the various components within a CPU, including the data paths, control unit, registers, and instruction set. It dictates how a processor executes instructions and interacts with other hardware components, significantly impacting performance, efficiency, and power consumption

# Most popular processor architectures:

# x86
# Assembly example:
movl $10, %ecx
.str:
.string ì%d \nî
.text:
movl $.str, %edi
movl %ecx, %esi
movq $0, %rax
call printf 


# ARM
# Assembly example for ADD operation
add     r0, r1, r2


# RISC-V
# Assembly code for Hello world

  .data         # declare and initialize variables
hello:  .asciz "Hello world!" # string with null terminator
 
  .text         # code starts here
main:           # label marking the entry point of the program
  la a0, hello  # load the address of hello into $a0 (1st argument)
  addi a7, zero, 4     # code to print the string at the address a0
  ecall         # make the system call
 
  addi a7, zero, 10    # code to exit
  ecall         # make the system call


