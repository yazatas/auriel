.section .text

.global read
.global write
.global fork
.global execv
.global _exit
.global wait

read:
    mov $0, %eax       # syscall number
    mov 4(%esp), %edx  # file descriptor
    mov 8(%esp), %ebx  # buffer of data
    mov 12(%esp), %ecx # buffer length
    int $0x80
    ret

write:
    mov $1, %eax       # syscall number
    mov 4(%esp), %edx  # file descriptor
    mov 8(%esp), %ebx  # buffer of data
    mov 12(%esp), %ecx # buffer length
    int $0x80
    ret

fork:
    mov $2, %eax       # syscall number
    int $0x80
    ret

execv:
    mov $3, %eax       # syscall number
    mov 4(%esp), %ebx  # file path
    mov 8(%esp), %ecx  # argv
    int $0x80
    ret

_exit:
    mov $6, %eax      # syscall number
    mov 4(%esp), %ebx # status
    int $0x80
    ret

wait:
    mov $7, %eax      # syscall number
    mov 4(%esp), %ebx # wstatus pointer
    int $0x80
    ret
