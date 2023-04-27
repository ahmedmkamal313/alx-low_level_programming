; 101-hello_holberton.asm
; A 64-bit program in assembly that prints Hello, Holberton, followed by a new line.

global main
	extern printf

section .data
	msg: db "Hello, Holberton", 10, 0

section .text

main:
mov rdi, msg
xor rax, rax

call printf

mov rax, 60
xor rdi, rdi
syscall
