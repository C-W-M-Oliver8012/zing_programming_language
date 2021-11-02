import os

cc = "clang"
cflags = "-std=c17 -Wall -Wextra -O2"
cfiles = "main.c string.c"
command = "%s %s %s -o zing" % (cc, cflags, cfiles)

os.system(command)

print(command)
