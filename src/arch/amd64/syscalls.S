.section .text

.global read
.global write
.global fork
.global execv
.global _exit
.global wait
.global socket
.global bind
.global send
.global sendto
.global recv
.global recvfrom
.global connect
.global listen
.global accept

read:
    mov $0, %rax   # syscall number
    mov %rdx, %rcx # buffer length
    mov %rdi, %rdx # file descriptor
    mov %rsi, %rbx # buffer of data
    int $0x80
    ret

write:
    mov $1, %rax   # syscall number
    mov %rdx, %rcx # buffer length
    mov %rdi, %rdx # file descriptor
    mov %rsi, %rbx # buffer of data
    int $0x80
    ret

fork:
    mov $2, %rax    # syscall number
    int $0x80
    ret

execv:
    mov $3, %rax    # syscall number
    mov %rdi, %rbx  # file path
    mov %rsi, %rcx  # argv
    int $0x80
    ret

_exit:
    mov $6, %rax   # syscall number
    mov %rdi, %rbx # status
    int $0x80
    ret

wait:
    mov $7, %rax   # syscall number
    mov %rdi, %rbx # wstatus pointer
    int $0x80
    ret

socket:
    mov $8, %rax
    mov %rdx, %rcx # buffer length
    mov %rdi, %rdx # file descriptor
    mov %rsi, %rbx # buffer of data
    int $0x80
    ret

bind:
    mov $9, %rax
    int $0x80
    ret

send:
    mov $10, %rax
    int $0x80
    ret

sendto:
    mov $11, %rax
    int $0x80
    ret

recv:
    mov $12, %rax
    int $0x80
    ret

recvfrom:
    mov $13, %rax
    int $0x80
    ret

connect:
    mov $14, %rax
    int $0x80
    ret

listen:
    mov $15, %rax
    int $0x80
    ret

accept:
    mov $16, %rax
    int $0x80
    ret
