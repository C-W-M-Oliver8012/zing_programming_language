import os, sys

cc = "clang"
cflags = "-g -std=c17 -Wall -Wextra -O2"
cfiles = "main.c string.c"
command = "%s %s %s -o zing" % (cc, cflags, cfiles)

if len(sys.argv) >= 2:
    if sys.argv[1] == "windows":
        command = "%s %s %s -o zing.exe" % (cc, cflags, cfiles)

os.system(command)

print(command)
