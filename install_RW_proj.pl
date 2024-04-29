#!/usr/bin/perl
use strict;
use warnings;

# Script ver. 0.6

not system("apt install libneo4j-client") or die "Unable to install the libneo4j .so (DLL for Linux) files.";
not system("apt install libneo4j-client-dev") or die "Unable to install the libneo4j SDK";
not system("gcc -o RW_App RW_App_main.c -lneo4j-client -lssl -lcrypto") or die "Compilation of the app failed.";

exit 0;
