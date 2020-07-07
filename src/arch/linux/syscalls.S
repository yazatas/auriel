.section .text

.global read
.global write
.global fork
.global execv
.global _exit
.global wait

# TODO
read:
    mov $0, %rax   # syscall number
    mov %rdx, %rcx # buffer length
    mov %rdi, %rdx # file descriptor
    mov %rsi, %rbx # buffer of data
    int $0x80
    ret

write:
    mov $1, %rax
    syscall
    ret

# TODO
fork:
    mov $2, %rax    # syscall number
    int $0x80
    ret

# TODO
execv:
    mov $3, %rax    # syscall number
    mov %rdi, %rbx  # file path
    mov %rsi, %rcx  # argv
    int $0x80
    ret

# TODO
_exit:
    mov $6, %rax   # syscall number
    mov %rdi, %rbx # status
    int $0x80
    ret

# TODO
wait:
    mov $7, %rax   # syscall number
    mov %rdi, %rbx # wstatus pointer
    int $0x80
    ret
