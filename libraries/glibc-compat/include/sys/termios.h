/* FIXME: From sys/sysvi386/sys */
#ifndef	_SYS_TERMIOS_H
# define _SYS_TERMIOS_H

# define _XCGETA (('x'<<8)|1)
# define _XCSETA (('x'<<8)|2)
# define _XCSETAW (('x'<<8)|3)
# define _XCSETAF (('x'<<8)|4)
# define _TCSBRK (('T'<<8)|5)
# define _TCFLSH (('T'<<8)|7)
# define _TCXONC (('T'<<8)|6)

# define TCOOFF	0
# define TCOON	1
# define TCIOFF	2
# define TCION	3

# define TCIFLUSH	0
# define TCOFLUSH	1
# define TCIOFLUSH	2

# define NCCS 32

# define TCSAFLUSH	_XCSETAF
# define TCSANOW	_XCSETA
# define TCSADRAIN	_XCSETAW
# define TCSADFLUSH	_XCSETAF

# define IGNBRK	000001
# define BRKINT	000002
# define IGNPAR	000004
# define PARMRK 000010
# define INPCK	000020
# define ISTRIP	000040
# define INLCR	000100
# define IGNCR	000200
# define ICRNL	000400
# define IXON	002000
# define IXANY  004000
# define IUTF8  004000
# define IXOFF	010000

# define OPOST	000001
# define OCRNL	000004
# define ONLCR	000010
# define ONOCR	000020
# define TAB3	014000

# define CLOCAL	004000
# define CREAD	000200
# define PARODD 001000
# define CSIZE	000060
# define CS5	0
# define CS6	020
# define CS7	040
# define CS8	060
# define CSTOPB	000100
# define HUPCL	002000
# define PARENB	000400
# define PAODD	001000

# define ECHO	 0000010
# define ECHOE	 0000020
# define ECHOK	 0000040
# define ECHONL	 0000100
# define ICANON	 0000002
# define IEXTEN  0100000   /* anybody know *what* this does?! */
# define ISIG	 0000001
# define NOFLSH	 0000200
# define TOSTOP  0000400
# define ECHOCTL 0001000
# define ECHOPRT 0002000
# define ECHOKE  0004000
# define FLUSHO  0010000
# define PENDIN  0040000

# define VINTR 0
# define VQUIT 1
# define VERASE 2
# define VKILL 3
# define VEOF 4
# define VTIME 5
# define VMIN 6
# define VSWTC 7
# define VSTART 8
# define VSTOP 9
# define VSUSP 10
# define VEOL 11
# define VREPRINT 12
# define VDISCARD 13
# define VWERASE 14
# define VLNEXT 15
# define VEOL2 16

# define B0	000000
# define B50	000001
# define B75	000002
# define B110	000003
# define B134	000004
# define B150	000005
# define B200	000006
# define B300	000007
# define B600	000010
# define B1200	000011
# define B1800	000012
# define B2400	000013
# define B4800	000014
# define B9600	000015
# define B19200	000016
# define B38400	000017

typedef unsigned char cc_t;
typedef unsigned short tcflag_t;
typedef char speed_t;

struct termios {
	tcflag_t	c_iflag;
	tcflag_t	c_oflag;
	tcflag_t	c_cflag;
	tcflag_t	c_lflag;
	char		c_line;
	cc_t		c_cc[NCCS];
	speed_t		c_ispeed;
	speed_t		c_ospeed;
};

# ifndef _NO_MACROS

#  define cfgetospeed(tp)	((tp)->c_ospeed)
#  define cfgetispeed(tp)	((tp)->c_ispeed)
#  define cfsetospeed(tp,s)	(((tp)->c_ospeed = (s)), 0)
#  define cfsetispeed(tp,s)	(((tp)->c_ispeed = (s)), 0)
#  define tcdrain(fd)		_ioctl (fd, _TCSBRK, 1)
# endif	/* _NO_MACROS */

int tcgetattr(int fd,struct termios *termios_p);
int tcsetattr(int fd,int optional_actions,const struct termios *termios_p);

#endif	/* _SYS_TERMIOS_H */

