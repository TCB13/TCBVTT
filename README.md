# TCB13's Virtual Terminal Tools

Small tools to interact in Virtual Terminals (eg. /dev/ttyXY or /dev/ptyXY) in a easy way.

**Why?** If a program uses a TTY device for command input and output it's hard to send commands to it. Sending output directly to a TTY with, for instance, `echo "text" > /dev/ttyXY` does not magicially make it input of that TTY. You may use `conspy` however that's an interactive program not suitable for bash scripts. The following tools aim to solve those problems.

**1. writevt**: based on ioctl and mostly ripped off of from the good old console-tools' `writevt.c`.

Compilation/Usage:
````
gcc writevt.c -o writevt
./writevt /dev/ttyXY text
````

**2. tiocsti.c**: another ioctl-based tool capable of using pipped data from stdin.

Compilation/Usage:
````
gcc tiocsti.c -o tiocsti
echo "text" | ./tiocsti > /dev/ttyXY
````

**Please note**: the usual way to receive commands in a program is to create a listening socket, not to hijack a TTY device. It works, but it's not really "best practice". Don't build new programs that do this.

Enjoy.
