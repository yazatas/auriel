# auriel

Implementation of ISO C and POSIX standards for the most part

This library doesn't try to compete with glibc, musl or any other implementation in any way.
I just want to implement the parts from these standards that I'm using to get a better understanding of them.

NB: because micael is still a little baby and thus cannot host a unit testing framework, all kernel-related calls are forwarded to Linux and only the API/intermediate functionality between caller and kernel is tested. Once micael is capable of running these unit tests, all kernel-related parts will be rewritten to use micael's API instead.

## What is ready

* ctype.h

## What is not ready

everything else
