/*
 * Copyright (c) 1988, 2012, Oracle and/or its affiliates. All rights reserved.
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any	*/
/*	actual or intended publication of such source code.	*/

#ifndef _CURSES_H
#define	_CURSES_H

#pragma ident	"@(#)curses.h	1.32	04/04/29 SMI"	/* SVr4.0 1.58	*/

/*
 * curses.h - this file is automatically made from caps and
 *	curses.ed. Don't make changes directly to curses.h!
 */

#include <widec.h>

#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	CSMAX   4

/*
 * This trick is used to distinguish between SYSV and V7 systems.
 * We assume that L_ctermid is only defined in stdio.h in SYSV
 * systems, but not in V7 or Berkeley UNIX.
 */
#ifdef L_ctermid
#ifdef SYSV
#undef SYSV
#endif
#define	SYSV
#endif
/* Some V7 systems define	L_ctermid - we list those here */
#ifdef BSD
#undef SYSV
#endif

#ifdef SYSV

#ifndef VINTR
#include <termio.h>
#endif /* VINTR */
typedef struct termio SGTTY;
typedef struct termios SGTTYS;

#else /* !SYSV */

#ifndef _SGTTYB_
#include <sgtty.h>
#endif /* _SGTTYB_ */
typedef struct sgttyb SGTTY;

/*
 * Here we attempt to improve portability by providing some #defines
 * for SYSV functions on non-SYSV systems.
 */
#define	memcpy(dst, src, len)	bcopy((src), (dst), (len))
#define	strchr			index
#define	strrchr			rindex
#endif /* SYSV */

/*
 * bool is a built-in type in standard C++ and as such is not
 * defined here when using standard C++. However, the GNU compiler
 * fixincludes utility nonetheless creates it's own version of this
 * header for use by gcc and g++. In that version it adds a redundant
 * guard for __cplusplus. To avoid the creation of a gcc/g++ specific
 * header we need to include the following magic comment:
 *
 * we must use the C++ compiler's type
 *
 * The above comment should not be removed or changed until GNU
 * gcc/fixinc/inclhack.def is updated to bypass this header.
 */
#if !defined(__cplusplus) && !defined(_BOOL)
typedef	char bool;
#endif /* !defined(__cplusplus) && !defined(_BOOL) */

#define	_VR3_COMPAT_CODE
/*
 * chtype is the type used to store a character together with attributes.
 * It can be set to "char" to save space, or "long" to get more attributes.
 */
#ifdef	CHTYPE
typedef	CHTYPE chtype;
#else
#ifdef _LP64
typedef unsigned int chtype;
#else
typedef unsigned long chtype;
#endif /* _LP64 */
#endif /* CHTYPE */

/*
 *	Define for the 'old' definition of chtype is required
 *	when we are running in compatibility mode
 */
#ifdef _VR3_COMPAT_CODE
typedef unsigned short _ochtype;
#endif

/* TRUE and FALSE get defined so many times, */
/* let's not get in the way of other definitions. */
#if	!defined(TRUE) || ((TRUE) != 1)
#define	TRUE	(1)
#endif
#if	!defined(FALSE) || ((FALSE) != 0)
#define	FALSE	(0)
#endif
#if	!defined(ERR) || ((ERR) != -1)
#define	ERR	(-1)
#endif
#if	!defined(OK) || ((OK) != 0)
#define	OK	(0)
#endif

/* short-hand notations */
typedef struct _win_st	WINDOW;
typedef struct screen	SCREEN;
typedef struct _Mouse	MOUSE_STATUS;

struct _win_st
{
	short		_cury, _curx;	/* current coordinates */
	short		_maxy, _maxx;	/* max coordinates */
	short		_begy, _begx;	/* (0,0) screen coordinates */
	char		_flags;
	short		_yoffset;	/* actual begy is _begy+_yoffset */
	bool		_clear,		/* clearok() info */
			_leave,		/* leaveok() info */
			_immed,		/* window in immediate mode */
			_sync;		/* auto syncup of parent */
	WINDOW		*_padwin;	/* "pad" area for current window */
#ifdef	_VR3_COMPAT_CODE
	_ochtype	**_y16;		/* MUST stay at this offset in WINDOW */
#endif
	short		*_firstch;	/* first change in line */
	short		*_lastch;	/* last change in line */
	short		_tmarg, _bmarg;	/* scrolling region bounds */
					/* MUST stay at this offset in WINDOW */
	unsigned	_scroll		: 1;	/* scrollok() info */
	unsigned	_use_idl	: 1;
	unsigned	_use_keypad	: 1;
	unsigned	_notimeout	: 1;
	unsigned	_use_idc	: 1;
	chtype		_attrs;		/* current window attributes */
	chtype		_bkgd;		/* background, normally blank */
	int		_delay;		/* delay period on wgetch */
					/* 0:  for nodelay */
					/* <0: for infinite delay */
					/* >0: delay time in millisec */
	short		_ndescs;	/* number of descendants */
	short		_parx, _pary;	/* coords relative to parent (0,0) */
	WINDOW		*_parent;	/* the parent if this is a subwin */
	chtype		**_y;		/* lines of data */
	short		_nbyte;		/* number of bytes to come */
	short		_index;		/* index to hold coming char */
	char		_waitc[CSMAX];	/* array to hold partial m-width char */
	bool		_insmode;	/* TRUE for inserting, */
					/* FALSE for adding */
};

/* _lastch is initially set to this, _firstch is set to win->_maxx */
#define	_NOCHANGE	-1
#define	_INFINITY	16000	/* no line can be longer than this */

/* values for win->_flags */
#define	_ISPAD		001
#define	_WINCHANGED	002
#define	_WINMOVED	004
#define	_WINSDEL	010
#define	_CANT_BE_IMMED	020
#define	_WIN_ADD_ONE	040
#define	_WIN_INS_ONE	100

struct _Mouse {
	int x, y;
	short button[3];
	int   changes;
};

#define	CURS_STUPID	0
#define	CURS_UNKNOWN	1
#define	CURS_BAD_MALLOC	2

/*
 * Various tricks to shut up lint about things that are perfectly fine.
 */
#if defined(__lint) && !defined(CURSES) /* if not internal to curses source */
struct screen {
	int _nobody_;
};
#endif /* __lint */

/* common external variables */

extern	int	LINES, COLS, TABSIZE, COLORS, COLOR_PAIRS;

extern	short	curs_errno;

extern WINDOW *stdscr, *curscr;

extern  MOUSE_STATUS	Mouse_status;

extern char ttytype[];

extern char	curs_parm_err[],
		*curs_err_strings[];

/* Function declarations */

#ifdef	_VR3_COMPAT_CODE

extern	_ochtype	*acs_map;
extern chtype 	*acs32map;

/* definitions for Vr3 source compatibility */

#define	initscr		initscr32
#define	newterm		newterm32
#define	waddch		w32addch
#define	wechochar	w32echochar
#define	pechochar	p32echochar
#define	winsch		w32insch
#define	vidputs		vid32puts
#define	vidattr		vid32attr
#define	wattroff	w32attroff
#define	wattron		w32attron
#define	wattrset	w32attrset
#define	acs_map		acs32map
#define	box		box32

#ifdef	__STDC__
extern WINDOW *initscr(void);
extern	SCREEN	*newterm(char *, FILE *, FILE *);
#else
extern WINDOW *initscr();
extern	SCREEN	*newterm();
#endif

/* declarations for mini-curses */

#ifdef	__STDC__
extern	WINDOW 	*m_initscr(void);

extern	SCREEN	*m_newterm(char *, FILE *, FILE *);

extern	int	m_addch(int), m_addstr(char *), m_clear(void), m_erase(void),
		m_move(int, int), m_refresh(void);

#else  /* __STDC__ */
extern	WINDOW	*m_initscr();

extern	SCREEN	*m_newterm();

extern	int	m_addch(), m_addstr(), m_clear(), m_erase(),
		m_move(), m_refresh();

#endif /* __STDC__ */

#else	/* _VR3_COMPAT_CODE */

extern chtype *acs_map;

#endif	/* _VR3_COMPAT_CODE */

#ifdef __STDC__

extern SCREEN *newscreen(char *, int, int, int, FILE *, FILE *);
extern SCREEN *setcurscreen(SCREEN *);

extern WINDOW *initscr(void);
extern WINDOW *newwin(int, int, int, int);
extern WINDOW *newpad(int, int);
extern WINDOW *derwin(WINDOW *, int, int, int, int);
extern WINDOW *dupwin(WINDOW *);
extern WINDOW *getwin(FILE *);

extern int wgetch(WINDOW *); /* it can return KEY_*, for instance. */

extern char *longname(void);	/* long name of terminal */
extern char *termname(void);	/* effective terminal name */
extern char *keyname(int); 	/* name of token returned by wgetch() */
extern char *slk_label(int);
extern char erasechar(void);
extern char killchar(void);
extern char *unctrl(int);

extern chtype termattrs(void);

extern void vidupdate(chtype, chtype, int (*)(char));
extern void wsyncup(WINDOW *);
extern void wsyncdown(WINDOW *);
extern void delscreen(SCREEN *);
extern void curserr(void);
extern void _setqiflush(int);
extern void wcursyncup(WINDOW *);

extern int cbreak(void);
extern int nocbreak(void);
extern int reset_prog_mode(void);
extern int reset_shell_mode(void);
extern int def_prog_mode(void);
extern int _setecho(int);
extern int _setnonl(int);
extern int def_shell_mode(void);
extern int raw(void);
extern int savetty(void);
extern int traceon(void);
extern int _meta(int);
extern int traceoff(void);
extern int noraw(void);
extern int flushinp(void);
extern int _getsyx(int *, int *);
extern int _ring(bool);
extern int resetty(void);
extern int ripoffline(int, int (*)(WINDOW *, int));
extern int setsyx(int, int);
extern int slk_refresh(void);
extern int slk_restore(void);
extern int wstandend(WINDOW *);
extern int wstandout(WINDOW *);
extern int wattroff(WINDOW *, chtype);
extern int wattron(WINDOW *, chtype);
extern int wattrset(WINDOW *, chtype);
extern int wrefresh(WINDOW *);

extern int copywin(WINDOW *, WINDOW *, int, int, int, int, int, int, int);
extern int curs_set(int);
extern int delay_output(int);
extern int delwin(WINDOW *);
extern int doupdate(void);
extern int drainio(int);
extern int endwin(void);
extern int isendwin(void);
extern int baudrate(void);
extern int has_ic(void);
extern int has_il(void);
extern int keypad(WINDOW *, bool);
extern int mvcur(int, int, int, int);

extern int mvprintw(int, int, ...);
extern int mvscanw(int, int, ...);
extern int mvwprintw(WINDOW *, int, int, ...);
extern int mvwscanw(WINDOW *, int, int, ...);
extern int printw(char *, ...);
extern int scanw(char *, ...);
extern int wprintw(WINDOW *, ...);
extern int wscanw(WINDOW *, ...);

		/* __va_list is the ANSI-C safe definition of the	*/
		/* va_list type as allowed to be defined in stdlib.h.	*/
		/* <stdio.h> provides the nested include of <va_list.h>	*/
		/* which provides this namespace safe definition.	*/
		/* Either <stdarg.h> or <varargs.h> must be included to	*/
		/* use these interfaces.				*/

extern int vwprintw(WINDOW *, char *, __va_list);
extern int vwscanw(WINDOW *, char *, __va_list);

extern int mvwin(WINDOW *, int, int);
extern int mvderwin(WINDOW *, int, int);
extern int napms(int);
extern int newkey(char *, short, bool);
extern int filter(void);
extern int pechochar(WINDOW *, chtype);
extern int pnoutrefresh(WINDOW *, int, int, int, int, int, int);
extern int prefresh(WINDOW *, int, int, int, int, int, int);

extern int putwin(WINDOW *, FILE *);
extern int wredrawln(WINDOW *, int, int);
extern int scr_dump(char *);
extern int setupterm(char *, int, int *);

extern int slk_attron(chtype);
extern int slk_attroff(chtype);
extern int slk_attrset(chtype);
extern int slk_clear(void);
extern int slk_noutrefresh(void);
extern int slk_set(int, char *, int);
extern int slk_start(int, int *);
extern int slk_touch(void);
extern int start_color(void);
extern int typeahead(int);

extern bool can_change_color(void);
extern bool has_colors(void);

extern int waddch(WINDOW *, chtype);
extern int waddchnstr(WINDOW *, chtype *, int);
extern int waddnstr(WINDOW *, char *, int);
extern int wbkgd(WINDOW *, chtype);
extern int wborder(WINDOW *, chtype, chtype, chtype, chtype,
		chtype, chtype, chtype, chtype);
extern int wclrtobot(WINDOW *);
extern int wclrtoeol(WINDOW *);
extern int wdelch(WINDOW *);
extern int wechochar(WINDOW *, chtype);
extern int wgetstr(WINDOW *, char *);
extern int wgetnstr(WINDOW *, char *, int);
extern int whline(WINDOW *, chtype, int);
extern int wvline(WINDOW *, chtype, int);
extern int winchnstr(WINDOW *, chtype *, int);
extern int winchstr(WINDOW *, chtype *);
extern int winnstr(WINDOW *, char *, int);
extern int winsch(WINDOW *, chtype);
extern int winsdelln(WINDOW *, int);		/* internal */
extern int winsnstr(WINDOW *, char *, int);
extern int winstr(WINDOW *, char *);
extern int wmove(WINDOW *, int, int);
extern int wnoutrefresh(WINDOW *);
extern int wredrawln(WINDOW *, int, int);
extern int wscrl(WINDOW *, int);
extern int wsetscrreg(WINDOW *, int, int);
extern int wtouchln(WINDOW *, int, int, int);

extern int crmode(void);
extern int nocrmode(void);
extern int ungetch(int);

extern int mouse_set(long int);
extern int mouse_on(long int);
extern int mouse_off(long int);
extern int request_mouse_pos(void);
extern int map_button(unsigned long);

extern void wmouse_position(WINDOW *, int *, int *);

extern unsigned long getmouse(void), getbmap(void);

		/* the following declarations take integers as arguments  */
		/* to keep the CI5 compiler happy.  what we really want   */
		/* to pass is given in comments.  (by the way, we don't   */
		/* save anything by passing short or bool, since compiler */
		/* expands them to integers any way			  */

extern int pair_content(short, short *, short *);
extern int color_content(short, short *, short *, short *); /* as above */
extern int init_color(short, short, short, short);
extern int init_pair(short, short, short);
extern int idlok(WINDOW *, bool);

extern void immedok(WINDOW *, bool);

extern chtype winwch(WINDOW *);

extern int pechowchar(WINDOW *, chtype);
extern int ungetwch(const wchar_t);
extern int waddnwstr(WINDOW *, wchar_t *, int);
extern int waddwch(WINDOW *, chtype);
extern int waddwchnstr(WINDOW *, chtype *, int);
extern int wechowchar(WINDOW *, chtype);
extern int wgetnwstr(WINDOW *, wchar_t *, int);
extern int wgetwch(WINDOW *);
extern int wgetwstr(WINDOW *, wchar_t *);
extern int winnwstr(WINDOW *, wchar_t *, int);
extern int winsnwstr(WINDOW *, wchar_t *, int);
extern int winswch(WINDOW *, chtype);
extern int winwchnstr(WINDOW *, chtype *, int);
extern int winwstr(WINDOW *, wchar_t *);

#else /* __STDC__ */

extern	SCREEN	*newscreen(),	/* termname, lines, cols, tabsiz, fout, fin */
		*setcurscreen(); /* screenptr */

extern	WINDOW 	*initscr(),
		*newwin(),		/* nlines, ncols, begy, begx */
		*newpad(),		/* nlines, ncols */
		*derwin(),		/* orig, nlines, ncols, begy, begx */
		*dupwin(),		/* orig */
		*getwin();		/* file */

extern	int	wgetch(); /* because it can return KEY_*, for instance. */

extern	char	*longname(),	/* long name of terminal */
		*termname(),	/* effective terminal name */
		*keyname(),	/* (int)  name of token returned by wgetch() */
		*slk_label(),	/* index */
		erasechar(),
		killchar(),
		*unctrl();

extern	chtype	termattrs();

extern	void	vidupdate(), wsyncup(), wsyncdown(),
		delkeymap(),
		delscreen(), curserr(),
		_setqiflush(),
		immedok(),
		wcursyncup();

extern	int	cbreak(), nocbreak(),
		reset_prog_mode(), reset_shell_mode(), def_prog_mode(),
		_setecho(), _setnonl(),
		def_shell_mode(), raw(),
		savetty(), traceon(), _meta(),
		traceoff(), noraw(), flushinp(), _getsyx(),
		_ring(), resetty(), ripoffline(), setsyx(), slk_refresh(),
		slk_restore(), wstandend(), wstandout(),
		wattroff(), wattron(), wattrset(), wrefresh();

extern	int	color_cont(), copywin(), curs_set(), delay_output(), delwin(),
		doupdate(), drainio(), endwin(), isendwin(),
		baudrate(), has_ic(), has_il(), idlok(),
		init_color(), init_pair(), keypad(), mvcur();

extern	int	mvprintw(), mvscanw(), mvwprintw(), mvwscanw(),
		printw(), scanw(), wprintw(), wscanw(), vwprintw(), vwscanw();

extern	int	mvwin(), mvderwin(), napms(), newkey(), filter(),
		pair_content(), pechochar(), pnoutrefresh(), prefresh();

extern 	int	putwin(), wredrawln(), scr_dump(), setupterm();

extern	int	slk_attrof(), slk_attrof(), slk_attrset(),
		slk_clear(), slk_noutrefresh(), slk_set(),
		slk_start(), slk_touch(), start_color(),
		typeahead();

extern	bool	can_change_color(), has_colors();

extern	int	waddch(), waddchnstr(), waddnstr(), wbkgd(),
		wborder(), wclrtobot(), wclrtoeol(), wdelch(), wechochar(),
		wgetstr(), wgetnstr(), whline(), wvline(), winchnstr(),
		winchstr(), winnstr(), winsch(),
		winsdelln(),		/* internal */
		winsnstr(), winstr(), wmove(), wnoutrefresh(), wredrawln(),
		wscrl(), wsetscrreg(), wtouchln();

extern	int	crmode(), nocrmode(), ungetch();

extern	int	mouse_set(), mouse_on(), mouse_off(),
		request_mouse_pos(), map_button();

extern void	wmouse_position();

extern unsigned long getmouse(), getbmap();

extern chtype	winwch();

extern int	pechowchar(), ungetwch(), waddnwstr(), waddwch(),
		waddwchnstr(), wechowchar(), wgetnwstr(), wgetwch(),
		wgetwstr(), winnwstr(), winsnwstr(), winswch(),
		winwchnstr(), winwstr();

#endif /* __STDC__ */

#define	getsyx(y, x)		_getsyx(&(y), &(x))

/*
 * Functions to get at the window structure.
 */

#define	getyx(win, y, x)	((y) = getcury(win), (x) = getcurx(win))
#define	getbegyx(win, y, x)	((y) = getbegy(win), (x) = getbegx(win))
#define	getmaxyx(win, y, x)	((y) = getmaxy(win), (x) = getmaxx(win))
#define	getparyx(win, y, x)	((y) = getpary(win), (x) = getparx(win))

#if	defined(CURS_PERFORMANCE) && !defined(__lint)
#define	getcury(win)		((win)->_cury)
#define	getcurx(win)		((win)->_curx)
#define	getbegy(win)		((win)->_begy)
#define	getbegx(win)		((win)->_begx)
#define	getmaxy(win)		((win)->_maxy)
#define	getmaxx(win)		((win)->_maxx)
#define	getpary(win)		((win)->_pary)
#define	getparx(win)		((win)->_parx)
#define	getbkgd(win)		((win)->_bkgd)
#define	getattrs(win)		((win)->_attrs)
#else 	/* defined(CURS_PERFORMANCE) && !defined(__lint) */

#ifdef __STDC__
extern int getcury(WINDOW *);
extern int getcurx(WINDOW *);
extern int getbegy(WINDOW *);
extern int getbegx(WINDOW *);
extern int getmaxy(WINDOW *);
extern int getmaxx(WINDOW *);
extern int getpary(WINDOW *);
extern int getparx(WINDOW *);

extern chtype getbkgd(WINDOW *);
extern chtype getattrs(WINDOW *);

#else  /* __STDC__ */
extern	int	getcury(), getcurx(), getbegy(), getbegx(),
		getmaxy(), getmaxx(), getpary(), getparx();

extern chtype	getbkgd(), getattrs();

#endif  /* __STDC__ */
#endif	/* defined(CURS_PERFORMANCE) && !defined(__lint) */

#if	defined(NOMACROS) || defined(__lint)

#ifdef __STDC__

extern	SCREEN	*newterm(char *, FILE *, FILE *);
extern	SCREEN  *set_term(SCREEN *);

extern WINDOW *subpad(WINDOW *, int, int, int, int);
extern WINDOW *subwin(WINDOW *, int, int, int, int);

extern char *unctrl(int);

extern chtype inch(void);
extern chtype winch(WINDOW *);
extern chtype mvinch(int, int);
extern chtype mvwinch(WINDOW *, int, int);

extern int addch(chtype);
extern int addchnstr(chtype *, int);
extern int addchstr(chtype *);
extern int addnstr(char *, int);
extern int addstr(char *);
extern int attroff(chtype);
extern int attron(chtype);
extern int attrset(chtype);
extern int beep(void);
extern int bkgd(chtype);
extern int border(chtype, chtype, chtype, chtype,
		chtype, chtype, chtype, chtype);
extern int box(WINDOW *, chtype, chtype);
extern int clear(void);
extern int clearok(WINDOW *, bool);
extern int clrtobot(void);
extern int clrtoeol(void);
extern int crmode(void);
extern int delch(void);
extern int deleteln(void);
extern int echo(void);
extern int echochar(chtype);
extern int erase(void);
extern int fixterm(void);
extern int flash(void);
extern int garbagedlines(WINDOW *, int, int);
extern int garbagedwin(WINDOW *);
extern int getch(void);
extern int getstr(char *);
extern int gettmode(void);
extern int halfdelay(int);
extern int hline(chtype, int);
extern int inchnstr(chtype *, int);
extern int inchstr(chtype *);
extern int innstr(char *, int);
extern int insch(chtype);
extern int insdelln(int);
extern int insertln(void);
extern int insnstr(char *, int);
extern int insstr(char *);
extern int instr(char *);
extern int intrflush(WINDOW *, int);
extern int is_linetouched(WINDOW *, int);
extern int is_wintouched(WINDOW *);
extern int leaveok(WINDOW *, bool);
extern int meta(WINDOW *, int);
extern int move(int, int);
extern int mvaddch(int, int, chtype);
extern int mvaddchnstr(int, int, chtype *, int);
extern int mvaddchstr(int, int, chtype *);
extern int mvaddnstr(int, int, char *, int);
extern int mvaddstr(int, int, char *);
extern int mvdelch(int, int);
extern int mvgetch(int, int);
extern int mvgetstr(int, int, char *);
extern int mvhline(int, int, chtype, int);
extern int mvinchnstr(int, int, chtype *, int);
extern int mvinchstr(int, int, chtype *);
extern int mvinnstr(int, int, char *, int);
extern int mvinsch(int, int, chtype);
extern int mvinsnstr(int, int, char *, int);
extern int mvinsstr(int, int, char *);
extern int mvinstr(int, int, char *);
extern int mvvline(int, int, chtype, int);
extern int mvwaddch(WINDOW *, int, int, chtype);
extern int mvwaddchnstr(WINDOW *, int, int, chtype *, int);
extern int mvwaddchstr(WINDOW *, int, int, chtype *);
extern int mvwaddnstr(WINDOW *, int, int, char *, int);
extern int mvwaddstr(WINDOW *, int, int, char *);
extern int mvwdelch(WINDOW *, int, int);
extern int mvwgetch(WINDOW *, int, int);
extern int mvwgetstr(WINDOW *, int, int, char *);
extern int mvwhline(WINDOW *, int, int, chtype, int);
extern int mvwinchnstr(WINDOW *, int, int, chtype *, int);
extern int mvwinchstr(WINDOW *, int, int, chtype *);
extern int mvwinnstr(WINDOW *, int, int, char *, int);
extern int mvwinsch(WINDOW *, int, int, chtype);
extern int mvwinsnstr(WINDOW *, int, int, char *, int);
extern int mvwinsstr(WINDOW *, int, int, char *);
extern int mvwinstr(WINDOW *, int, int, char *);
extern int mvwvline(WINDOW *, int, int, chtype, int);
extern int nl(void);
extern int nocrmode(void);
extern int nodelay(WINDOW *, bool);
extern int noecho(void);
extern int nonl(void);
extern int notimeout(WINDOW *, bool);
extern int overlay(WINDOW *, WINDOW *);
extern int overwrite(WINDOW *, WINDOW *);
extern int redrawwin(WINDOW *);
extern int refresh(void);
extern int resetterm(void);
extern int saveterm(void);
extern int scr_init(char *);
extern int scr_restore(char *);
extern int scr_set(char *);
extern int scrl(int);
extern int scroll(WINDOW *);
extern int scrollok(WINDOW *, bool);
extern int setscrreg(int, int);
extern int setterm(char *);
extern int slk_init(int);
extern int standend(void);
extern int standout(void);
extern int syncok(WINDOW *, bool);
extern int touchline(WINDOW *, int, int);
extern int touchwin(WINDOW *);
extern int untouchwin(WINDOW *);
extern int vline(chtype, int);
extern int waddchstr(WINDOW *, chtype *);
extern int waddstr(WINDOW *, char *);
extern int wclear(WINDOW *);
extern int wdeleteln(WINDOW *);
extern int werase(WINDOW *);
extern int winchstr(WINDOW *, chtype *);
extern int winsertln(WINDOW *);
extern int winsstr(WINDOW *, char *);
extern int winstr(WINDOW *, char *);
extern int wstandend(WINDOW *);
extern int wstandout(WINDOW *);

extern void bkgdset(chtype);
extern void idcok(WINDOW *, bool);
extern void noqiflush(void);
extern void wbkgdset(WINDOW *, chtype);
extern void qiflush(void);
extern void timeout(int);
extern void wtimeout(WINDOW *, int);
extern void use_env(int);			/* int sb. char */

extern chtype inwch(void);
extern chtype mvinwch(int, int);
extern chtype mvwinwch(WINDOW *, int, int);

extern int addnwstr(wchar_t *, int);
extern int addwch(chtype);
extern int addwchnstr(chtype *, int);
extern int addwchstr(chtype *);
extern int addwstr(wchar_t *);
extern int echowchar(chtype);
extern int getnwstr(wchar_t *, int);
extern int getwch(void);
extern int getwstr(wchar_t *);
extern int innwstr(wchar_t *, int);
extern int insnwstr(wchar_t *, int);
extern int inswch(chtype);
extern int inswstr(wchar_t *);
extern int inwchnstr(chtype *, int);
extern int inwchstr(chtype *);
extern int inwstr(wchar_t *);
extern int mvaddnwstr(int, int, wchar_t *, int);
extern int mvaddwch(int, int, chtype);
extern int mvaddwchnstr(int, int, chtype *, int);
extern int mvaddwchstr(int, int, chtype *);
extern int mvaddwstr(int, int, wchar_t *);
extern int mvgetnwstr(int, int, wchar_t *, int);
extern int mvgetwch(int, int);
extern int mvgetwstr(int, int, wchar_t *);
extern int mvinnwstr(int, int, wchar_t *, int);
extern int mvinsnwstr(int, int, wchar_t *, int);
extern int mvinswch(int, int, chtype);
extern int mvinswstr(int, int, wchar_t *);
extern int mvinwchnstr(int, int, chtype *, int);
extern int mvinwchstr(int, int, chtype *);
extern int mvinwstr(int, int, wchar_t *);
extern int mvwaddnwstr(WINDOW *, int, int, wchar_t *, int);
extern int mvwaddwch(WINDOW *, int, int, chtype);
extern int mvwaddwchnstr(WINDOW *, int, int, chtype *, int);
extern int mvwaddwchstr(WINDOW *, int, int, chtype *);
extern int mvwaddwstr(WINDOW *, int, int, wchar_t *);
extern int mvwgetnwstr(WINDOW *, int, int, wchar_t *, int);
extern int mvwgetwch(WINDOW *, int, int);
extern int mvwgetwstr(WINDOW *, int, int, wchar_t *);
extern int mvwinnwstr(WINDOW *, int, int, wchar_t *, int);
extern int mvwinsnwstr(WINDOW *, int, int, wchar_t *, int);
extern int mvwinswch(WINDOW *, int, int, chtype);
extern int mvwinswstr(WINDOW *, int, int, wchar_t *);
extern int mvwinwchnstr(WINDOW *, int, int, chtype *, int);
extern int mvwinwchstr(WINDOW *, int, int, chtype *);
extern int mvwinwstr(WINDOW *, int, int, wchar_t *);
extern int waddwchstr(WINDOW *, chtype *);
extern int waddwstr(WINDOW *, wchar_t *);
extern int winswstr(WINDOW *, wchar_t *);
extern int winwchstr(WINDOW *, chtype *);

#else /* __STDC__ */

extern	SCREEN	*newterm(),		/* termname, fout, fin */
extern	SCREEN	*set_term();		/* screenptr */

extern	WINDOW	*subpad(),
extern	WINDOW	*subwin();

extern	chtype	inch(), winch(), mvinch(), mvwinch();

extern	char	*unctrl();

extern	int	addch(), addchnstr(), addchstr(), addnstr(), addstr(),
		attroff(), attron(), attrset(), beep(), bkgd(),
		border(), box(), clear(), clearok(), clrtobot(), clrtoeol(),
		crmode(), delch(), deleteln(), echo(), echochar(),
		erase(),
/* MORE */	fixterm(),
		flash(), garbagedlines(), garbagedwin(),
		getch(), getstr(), gettmode(), halfdelay(), hline(),
		inchnstr(), inchstr(), innstr(), insch(),
		insdelln(), insertln(), insnstr(), insstr(), instr(),
		intrflush(),
		is_linetouched(), is_wintouched(), leaveok(), meta(),
		move(), mvaddch(), mvaddchnstr(), mvaddchstr(), mvaddnstr(),
		mvaddstr(), mvdelch(), mvgetch(), mvgetstr(), mvhline(),
		mvinchnstr(), mvinchstr(), mvinnstr(), mvinsch(), mvinsnstr(),
		mvinsstr(), mvinstr(), mvvline(), mvwaddch(), mvwaddchnstr(),
		mvwaddchstr(), mvwaddnstr(), mvwaddstr(), mvwdelch(),
		mvwgetch(), mvwgetstr(), mvwhline(), mvwinchnstr(),
		mvwinchstr(), mvwinnstr(), mvwinsch(), mvwinsnstr(),
		mvwinsstr(), mvwinstr(), mvwvline(),
		nl(), nocrmode(), nodelay(),
		noecho(), nonl(), notimeout(),
		overlay(), overwrite(), redrawwin(), refresh(),
		resetterm(), saveterm(), scr_init(),
		scr_restore(), scr_set(), scrl(),
		scroll(), scrollok(), setscrreg(), setterm(),
		slk_init(), standend(), standout(),
		syncok(), touchline(), touchwin(), untouchwin(), vline(),
		waddchstr(), waddstr(), wclear(),
		wdeleteln(), werase(), winchstr(), winsertln(),
		winsstr(), winstr(), wstandend(), wstandout();

extern	void	bkgdset(), wbkgdset(), idcok(), noqiflush(),
		qiflush(), timeout(), wtimeout(), use_env();

extern unsigned long getmouse(), getbmap();

extern chtype   inwch(), mvinwch(), mvwinwch();

extern int	addnwstr(), addwch(), addwchnstr(), addwchstr(),
		addwstr(), echowchar(), getnwstr(), getwch(),
		getwstr(), innwstr(), insnwstr(), inswch(),
		inswstr(), inwchnstr(), inwchstr(), inwstr(),
		mvaddnwstr(), mvaddwch(), mvaddwchnstr(), mvaddwchstr(),
		mvaddwstr(), mvgetnwstr(), mvgetwch(), mvgetwstr(),
		mvinnwstr(), mvinsnwstr(), mvinswch(), mvinswstr(),
		mvinwchnstr(), mvinwchstr(), mvinwstr(), mvwaddnwstr(),
		mvwaddwch(), mvwaddwchnstr(), mvwaddwchstr(), mvwaddwstr(),
		mvwgetnwstr(), mvwgetwch(), mvwgetwstr(), mvwinnwstr(),
		mvwinsnwstr(), mvwinswch(), mvwinswstr(), mvwinwchnstr(),
		mvwinwchstr(), mvwinwstr(), waddwchstr(), waddwstr(),
		winswstr(), winwchstr();

#endif /* __STDC__ */

#else	/* NOMACROS || __lint */

/*
 * The defines from here down to the #endif for NOMACROS
 * define	macros, which may be more efficient than their
 * function versions. The functions may be accessed by defining
 * NOMACROS in C code. This is useful for debugging purposes.
 */

#include  <unctrl.h>

/* pseudo functions for stdscr */
#define	addch(ch)	waddch(stdscr, ch)
#define	addnstr(s, n)	waddnstr(stdscr, s, n)
#define	addstr(str)	waddstr(stdscr, str)
#define	attroff(at)	wattroff(stdscr, at)
#define	attron(at)	wattron(stdscr, at)
#define	attrset(at)	wattrset(stdscr, at)
#define	bkgd(c)		wbkgd(stdscr, c)
#define	border(ls, rs, ts, bs, tl, tr, bl, br) \
	wborder(stdscr, ls, rs, ts, bs, tl, tr, bl, br)
#define	clear()		wclear(stdscr)
#define	clrtobot()	wclrtobot(stdscr)
#define	clrtoeol()	wclrtoeol(stdscr)
#define	delch()		wdelch(stdscr)
#define	deleteln()	wdeleteln(stdscr)
#define	echochar(ch)	wechochar(stdscr, ch)
#define	erase()		werase(stdscr)
#define	getch()		wgetch(stdscr)
#define	getstr(str)	wgetstr(stdscr, str)
#define	inch()		winch(stdscr)
#define	insch(c)	winsch(stdscr, c)
#define	insdelln(id)	winsdelln(stdscr, id)
#define	insertln()	winsertln(stdscr)
#define	insnstr(s, n)	winsnstr(stdscr, s, n)
#define	insstr(s)	winsstr(stdscr, s)
#define	move(y, x)	wmove(stdscr, y, x)
#define	refresh()	wrefresh(stdscr)
#define	scrl(n)		wscrl(stdscr, n)
#define	setscrreg(t, b)	wsetscrreg(stdscr, t, b)
#define	standend()	wstandend(stdscr)
#define	standout()	wstandout(stdscr)
#define	timeout(tm)	wtimeout(stdscr, tm)
#define	hline(c, num)	whline(stdscr, c, num)
#define	vline(c, num)	wvline(stdscr, c, num)
#define	addchstr(str)	waddchstr(stdscr, str)
#define	addchnstr(str, n)	waddchnstr(stdscr, str, n)
#define	instr(str)	winstr(stdscr, (str))
#define	innstr(str, n)	winnstr(stdscr, (str), (n))
#define	inchstr(str)	winchstr(stdscr, str)
#define	inchnstr(str, n)	winchnstr(stdscr, str, n)
#define	bkgdset(c)	wbkgdset(stdscr, c)

#define	addnwstr(ws, n)	waddnwstr(stdscr, ws, n)
#define	addwch(ch)	waddwch(stdscr, ch)
#define	addwchnstr(str, n)	waddwchnstr(stdscr, str, n)
#define	addwchstr(str)	waddwchstr(stdscr, str)
#define	addwstr(ws)	waddwstr(stdscr, ws)
#define	echowchar(ch)	wechowchar(stdscr, ch)
#define	getnwstr(ws, n)	wgetnwstr(stdscr, ws, n)
#define	getwch()	wgetwch(stdscr)
#define	getwstr(ws)	wgetwstr(stdscr, ws)
#define	innwstr(ws, n)	winnwstr(stdscr, ws, n)
#define	insnwstr(ws, n)	winsnwstr(stdscr, ws, n)
#define	inswch(c)	winswch(stdscr, c)
#define	inswstr(ws)	winswstr(stdscr, ws)
#define	inwch()	winwch(stdscr)
#define	inwchnstr(str, n)	winwchnstr(stdscr, str, n)
#define	inwchstr(str)	winwchstr(stdscr, str)
#define	inwstr(ws)	winwstr(stdscr, ws)

#define	adjcurspos()	wadjcurspos(stdscr)
#define	movenextch()	wmovenextch(stdscr)
#define	moveprevch()	wmoveprevch(stdscr)

/* functions to define	environment flags of a window */
#ifdef	CURS_PERFORMANCE
#define	wbkgdset(win, c) \
	(((win)->_attrs = (((win)->_attrs & ~((win)->_bkgd & A_ATTRIBUTES)) | \
	    (c & A_ATTRIBUTES))), ((win)->_bkgd = (c)))
#define	syncok(win, bf)		((win)->_parent ? (win)->_sync = (bf) : ERR)
#define	notimeout(win, bf) \
	(((win)->_notimeout = ((bf) ? TRUE : FALSE)), OK)
#define	clearok(win, bf)	(((win)->_clear = (bf)), OK)
#define	leaveok(win, bf)	(((win)->_leave = (bf)), OK)
#define	scrollok(win, bf)	(((win)->_scroll = ((bf) ? TRUE : FALSE)), OK)
#define	idcok(win, bf)		((win)->_use_idc = ((bf) ? TRUE : FALSE))
#define	nodelay(win, bf)	(((win)->_delay = (bf) ? 0 : -1), OK)
#define	is_wintouched(win)	((win)->_flags & _WINCHANGED)
#define	is_linetouched(win, line) \
	((((line) >= (win)->_maxy) || ((line) < 0)) ? ERR : \
	    (((win)->_firstch[(line)] == _INFINITY) ? FALSE : TRUE))

#define	subwin(win, nl, nc, by, bx) \
	derwin((win), (nl), (nc), (by-win->_begy), (bx-win->_begx))
#define	touchwin(win)		wtouchln((win), 0, (win)->_maxy, TRUE)
#define	redrawwin(win)		wredrawln((win), 0, (win)->_maxy)
#define	winchstr(win, str) \
	winchnstr((win), str, ((win)->_maxx - (win)->_curx))
#define	winstr(win, str) \
	winnstr((win), str, ((win)->_maxx - (win)->_curx))
#define	untouchwin(win)		wtouchln((win), 0, ((win)->_maxy), FALSE)
#define	winch(win)		((win)->_y[(win)->_cury][(win)->_curx])

#define	wtimeout(win, tm)	((win)->_delay = (tm))
#define	use_env(bf)		(_use_env = (bf))

#else	/* CURS_PERFORMANCE */

#ifdef __STDC__

extern void wbkgdset(WINDOW *, chtype);
extern void idcok(WINDOW *, bool);
extern void wtimeout(WINDOW *, int);
extern void use_env(int);			 /* int sb. char */

extern int syncok(WINDOW *, bool);
extern int notimeout(WINDOW *, bool);
extern int clearok(WINDOW *, bool);
extern int leaveok(WINDOW *, bool);
extern int scrollok(WINDOW *, bool);
extern int nodelay(WINDOW *, bool);
extern int is_linetouched(WINDOW *, int);
extern int is_wintouched(WINDOW *);
extern int touchwin(WINDOW *);
extern int redrawwin(WINDOW *);
extern int winchstr(WINDOW *, chtype *);
extern int winstr(WINDOW *, char *);
extern int untouchwin(WINDOW *);

extern chtype winch(WINDOW *);

extern WINDOW *subwin(WINDOW *, int, int, int, int);

#else  /* __STDC__ */

extern	void	wbkgdset(), idcok(), wtimeout(), use_env();

extern	int	syncok(), notimeout(), clearok(), leaveok(),
		scrollok(), nodelay(), is_linetouched(), is_wintouched(),
		touchwin(), redrawwin(), winchstr(), winstr(),
		untouchwin();

extern  chtype  winch();

extern WINDOW *subwin();

#endif /* __STDC__ */

#endif	/* CURS_PERFORMANCE */

/* functions for move and update */
#define	mvaddch(y, x, ch) \
	mvwaddch(stdscr, y, x, ch)
#define	mvaddnstr(y, x, s, n) \
	mvwaddnstr(stdscr, y, x, s, n)
#define	mvaddstr(y, x, str) \
	mvwaddstr(stdscr, y, x, str)
#define	mvdelch(y, x) \
	mvwdelch(stdscr, y, x)
#define	mvgetch(y, x) \
	mvwgetch(stdscr, y, x)
#define	mvgetstr(y, x, str) \
	mvwgetstr(stdscr, y, x, str)
#define	mvinch(y, x) \
	mvwinch(stdscr, y, x)
#define	mvinsch(y, x, c) \
	mvwinsch(stdscr, y, x, c)
#define	mvinsnstr(y, x, s, n) \
	mvwinsnstr(stdscr, y, x, s, n)
#define	mvinsstr(y, x, s) \
	mvwinsstr(stdscr, y, x, s)
#define	mvaddchstr(y, x, str) \
	mvwaddchstr(stdscr, y, x, str)
#define	mvaddchnstr(y, x, str, n) \
	mvwaddchnstr(stdscr, y, x, str, n)
#define	mvinstr(y, x, str) \
	mvwinstr(stdscr, y, x, (str))
#define	mvinnstr(y, x, str, n) \
	mvwinnstr(stdscr, y, x, (str), (n))
#define	mvinchstr(y, x, str) \
	mvwinchstr(stdscr, y, x, str)
#define	mvinchnstr(y, x, str, n) \
	mvwinchnstr(stdscr, y, x, str, n)
#define	mvhline(y, x, c, num) \
	mvwhline(stdscr, y, x, c, num)
#define	mvvline(y, x, c, num) \
	mvwvline(stdscr, y, x, c, num)

#define	mvaddnwstr(y, x, ws, n) \
	mvwaddnwstr(stdscr, y, x, ws, n)
#define	mvaddwch(y, x, ch) \
	mvwaddwch(stdscr, y, x, ch)
#define	mvaddwchnstr(y, x, str, n) \
	mvwaddwchnstr(stdscr, y, x, str, n)
#define	mvaddwchstr(y, x, str) \
	mvwaddwchstr(stdscr, y, x, str)
#define	mvaddwstr(y, x, ws) \
	mvwaddwstr(stdscr, y, x, ws)
#define	mvgetnwstr(y, x, ws, n) \
	mvwgetnwstr(stdscr, y, x, ws, n)
#define	mvgetwch(y, x) \
	mvwgetwch(stdscr, y, x)
#define	mvgetwstr(y, x, ws) \
	mvwgetwstr(stdscr, y, x, ws)
#define	mvinnwstr(y, x, ws, n) \
	mvwinnwstr(stdscr, y, x, ws, n)
#define	mvinsnwstr(y, x, ws, n) \
	mvwinsnwstr(stdscr, y, x, ws, n)
#define	mvinswch(y, x, c) \
	mvwinswch(stdscr, y, x, c)
#define	mvinswstr(y, x, ws) \
	mvwinswstr(stdscr, y, x, ws)
#define	mvinwch(y, x) \
	mvwinwch(stdscr, y, x)
#define	mvinwchnstr(y, x, str, n) \
	mvwinwchnstr(stdscr, y, x, str, n)
#define	mvinwchstr(y, x, str) \
	mvwinwchstr(stdscr, y, x, str)
#define	mvinwstr(y, x, ws) \
	mvwinwstr(stdscr, y, x, ws)

#define	mvwaddch(win, y, x, ch) \
	(wmove(win, y, x) == ERR ? ERR : waddch(win, ch))
#define	mvwaddnstr(win, y, x, s, n) \
	(wmove(win, y, x) == ERR ? ERR : waddnstr(win, s, n))
#define	mvwaddstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : waddstr(win, str))
#define	mvwdelch(win, y, x) \
	(wmove(win, y, x) == ERR ? ERR : wdelch(win))
#define	mvwgetch(win, y, x) \
	(wmove(win, y, x) == ERR ? ERR : wgetch(win))
#define	mvwgetstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : wgetstr(win, str))
#define	mvwinch(win, y, x) \
	(wmove(win, y, x) == ERR ? (chtype)ERR : winch(win))
#define	mvwinsch(win, y, x, c) \
	(wmove(win, y, x) == ERR ? ERR : winsch(win, c))
#define	mvwinsnstr(win, y, x, s, n) \
	(wmove(win, y, x) == ERR ? ERR : winsnstr(win, s, n))
#define	mvwinsstr(win, y, x, s) \
	(wmove(win, y, x) == ERR ? ERR : winsstr(win, s))
#define	mvwhline(win, y, x, c, num) \
	(wmove(win, y, x) == ERR ? ERR : whline(win, c, num))
#define	mvwvline(win, y, x, c, num) \
	(wmove(win, y, x) == ERR ? ERR : wvline(win, c, num))
#define	mvwaddchstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : waddchstr(win, str))
#define	mvwaddchnstr(win, y, x, str, n) \
	(wmove(win, y, x) == ERR ? ERR : waddchnstr(win, str, n))
#define	mvwinstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : winstr(win, str))
#define	mvwinnstr(win, y, x, str, n) \
	(wmove(win, y, x) == ERR ? ERR : winnstr(win, str, n))
#define	mvwinchstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : winchstr(win, str))
#define	mvwinchnstr(win, y, x, str, n) \
	(wmove(win, y, x) == ERR ? ERR : winchnstr(win, str, n))
#define	mvwaddnwstr(win, y, x, ws, n) \
	(wmove(win, y, x) == ERR ? ERR : waddnwstr(win, ws, n))
#define	mvwaddwch(win, y, x, ch) \
	(wmove(win, y, x) == ERR ? ERR : waddwch(win, ch))
#define	mvwaddwchnstr(win, y, x, str, n) \
	(wmove(win, y, x) == ERR ? ERR : waddwchnstr(win, str, n))
#define	mvwaddwchstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : waddwchstr(win, str))
#define	mvwaddwstr(win, y, x, ws) \
	(wmove(win, y, x) == ERR ? ERR : waddwstr(win, ws))
#define	mvwgetnwstr(win, y, x, ws, n) \
	(wmove(win, y, x) == ERR ? ERR : wgetnwstr(win, ws, n))
#define	mvwgetwch(win, y, x) \
	(wmove(win, y, x) == ERR ? ERR : wgetwch(win))
#define	mvwgetwstr(win, y, x, ws) \
	(wmove(win, y, x) == ERR ? ERR : wgetwstr(win, ws))
#define	mvwinnwstr(win, y, x, ws, n) \
	(wmove(win, y, x) == ERR ? ERR : winnwstr(win, ws, n))
#define	mvwinsnwstr(win, y, x, ws, n) \
	(wmove(win, y, x) == ERR ? ERR : winsnwstr(win, ws, n))
#define	mvwinswch(win, y, x, c) \
	(wmove(win, y, x) == ERR ? ERR : winswch(win, c))
#define	mvwinswstr(win, y, x, ws) \
	(wmove(win, y, x) == ERR ? ERR : winswstr(win, ws))
#define	mvwinwch(win, y, x) \
	(wmove(win, y, x) == ERR ?(chtype) ERR : winwch(win))
#define	mvwinwchnstr(win, y, x, str, n) \
	(wmove(win, y, x) == ERR ? ERR : winwchnstr(win, str, n))
#define	mvwinwchstr(win, y, x, str) \
	(wmove(win, y, x) == ERR ? ERR : winwchstr(win, str))
#define	mvwinwstr(win, y, x, ws) \
	(wmove(win, y, x) == ERR ? ERR : winwstr(win, ws))

#define	waddwchstr(win, str)	waddwchnstr(win, str, -1)
#define	winwchstr(win, str)	winwchnstr(win, str, -1)
#define	waddwstr(win, ws)	waddnwstr(win, ws, -1)
#define	winswstr(win, ws)	winsnwstr(win, ws, -1)

#ifdef CURS_MACROS
#define	overlay(src, dst)	_overlap((src), (dst), TRUE)
#define	overwrite(src, dst)	_overlap((src), (dst), FALSE)
#define	wdeleteln(win)		winsdelln((win), -1)
#define	winsertln(win)		winsdelln((win), 1)
#define	wstandend(win)		wattrset((win), A_NORMAL)
#define	wstandout(win)		wattron((win), A_STANDOUT)
#define	beep()			_ring(TRUE)
#define	flash()			_ring(FALSE)
#define	scroll(win)		wscrl((win), 1)
#define	slk_init(f)		slk_start(((f == 0) ? 3 : 2), NULL)
#define	scr_init(file)		_scr_all(file, 0)
#define	scr_restore(file)	_scr_all(file, 1)
#define	scr_set(file)		_scr_all(file, 2)
#define	subpad(win, nl, nc, by, bx) derwin((win), (nl), (nc), (by), (bx))
#define	box(win, v, h)		wborder((win), (v), (v), (h), (h), 0, 0, 0, 0)
#define	newterm(type, fout, fin) newscreen((type), 0, 0, 0, (fout), (fin))
#define	touchline(win, y, n)	wtouchln((win), (y), (n), TRUE)

#define	waddstr(win, str)	waddnstr((win), (str), -1)
#define	werase(win)		(wmove((win), 0, 0), wclrtobot(win))
#define	wclear(win)		(clearok((win), TRUE), werase(win))
#define	intrflush(win, flag)	_setqiflush(flag)
#define	meta(win, flag)		_meta(flag)

#define	setterm(name)		setupterm((name), 1, (char *)NULL)
#define	gettmode()		(OK)
#define	halfdelay(tens)		ttimeout((tens)*100)

#define	echo()			_setecho(TRUE)
#define	noecho()		_setecho(FALSE)
#define	nl()			_setnonl(FALSE)
#define	nonl()			_setnonl(TRUE)

#else /* CURS_MACROS */

#ifdef __STDC__

extern int overlay(WINDOW *, WINDOW *);
extern int overwrite(WINDOW *, WINDOW *);
extern int wdeleteln(WINDOW *);
extern int winsertln(WINDOW *);
extern int wstandend(WINDOW *);
extern int wstandout(WINDOW *);
extern int beep(void);
extern int flash(void);
extern int scroll(WINDOW *);
extern int slk_init(int);
extern int scr_init(char *);
extern int scr_restore(char *);
extern int box(WINDOW *, chtype, chtype);
extern int touchline(WINDOW *, int, int);
extern int waddstr(WINDOW *, char *);
extern int werase(WINDOW *);
extern int wclear(WINDOW *);
extern int intrflush(WINDOW *, int);
extern int meta(WINDOW *, int);
extern int setterm(char *);
extern int gettmode(void);
extern int halfdelay(int);
extern int echo(void);
extern int noecho(void);
extern int nl(void);
extern int nonl(void);

extern WINDOW *subpad(WINDOW *, int, int, int, int);

extern  SCREEN *newterm(char *, FILE *, FILE *);

#else  /* __STDC__ */

extern	int	overlay(), overwrite(), wdeleteln(), winsertln(),
		wstandend(), wstandout(), beep(), flash(),
		scroll(), slk_init(), scr_init(), scr_restore(),
		box(), touchline(), waddstr(), werase(),
		wclear(), intrflush(), meta(), setterm(), gettmode(),
		halfdelay(), echo(), noecho(), nl(), nonl();

extern	WINDOW *subpad();

extern  SCREEN  *newterm();

#endif /* __STDC__ */
#endif /* CURS_MACROS */

#define	garbagedlines		wredrawln
#define	garbagedwin		redrawwin

#define	crmode			cbreak
#define	nocrmode		nocbreak
#define	saveterm		def_prog_mode
#define	fixterm			reset_prog_mode
#define	resetterm		reset_shell_mode

#define	waddchstr(win, str)	waddchnstr((win), (str), -1)
#define	winsstr(win, str)	winsnstr((win), (str), -1)

/* iocontrol functions */
#define	qiflush()		_setqiflush(TRUE)
#define	noqiflush()		_setqiflush(FALSE)

#define	set_term		setcurscreen

#endif	/* NOMACROS || __lint */

/*
 * Standard alternate character set.  The current ACS world is evolving,
 * so we support only a widely available subset: the line drawing characters
 * from the VT100, plus a few from the Teletype 5410v1.  Eventually there
 * may be support of more sophisticated ACS line drawing, such as that
 * in the Teletype 5410, the HP line drawing set, and the like.  There may
 * be support for some non line oriented characters as well.
 *
 * Line drawing ACS names are of the form ACS_trbl, where t is the top, r
 * is the right, b is the bottom, and l is the left.  t, r, b, and l might
 * be B (blank), S (single), D (double), or T (thick).  The subset defined
 * here only uses B and S.
 */

#define	ACS_BSSB	(acs_map['l'])
#define	ACS_SSBB	(acs_map['m'])
#define	ACS_BBSS	(acs_map['k'])
#define	ACS_SBBS	(acs_map['j'])
#define	ACS_SBSS	(acs_map['u'])
#define	ACS_SSSB	(acs_map['t'])
#define	ACS_SSBS	(acs_map['v'])
#define	ACS_BSSS	(acs_map['w'])
#define	ACS_BSBS	(acs_map['q'])
#define	ACS_SBSB	(acs_map['x'])
#define	ACS_SSSS	(acs_map['n'])

/*
 * Human readable names for the most commonly used characters.
 * "Upper", "right", etc. are chosen to be consistent with the vt100 manual.
 */

#define	ACS_ULCORNER	ACS_BSSB
#define	ACS_LLCORNER	ACS_SSBB
#define	ACS_URCORNER	ACS_BBSS
#define	ACS_LRCORNER	ACS_SBBS
#define	ACS_RTEE	ACS_SBSS
#define	ACS_LTEE	ACS_SSSB
#define	ACS_BTEE	ACS_SSBS
#define	ACS_TTEE	ACS_BSSS
#define	ACS_HLINE	ACS_BSBS
#define	ACS_VLINE	ACS_SBSB
#define	ACS_PLUS	ACS_SSSS
#define	ACS_S1		(acs_map['o'])	/* scan line 1 */
#define	ACS_S9		(acs_map['s'])	/* scan line 9 */
#define	ACS_DIAMOND	(acs_map['`'])	/* diamond */
#define	ACS_CKBOARD	(acs_map['a'])	/* checker board (stipple) */
#define	ACS_DEGREE	(acs_map['f'])	/* degree symbol */
#define	ACS_PLMINUS	(acs_map['g'])	/* plus/minus */
#define	ACS_BULLET	(acs_map['~'])	/* bullet */
	/* Teletype 5410v1 symbols */
#define	ACS_LARROW	(acs_map[','])	/* arrow pointing left */
#define	ACS_RARROW	(acs_map['+'])	/* arrow pointing right */
#define	ACS_DARROW	(acs_map['.'])	/* arrow pointing down */
#define	ACS_UARROW	(acs_map['-'])	/* arrow pointing up */
#define	ACS_BOARD	(acs_map['h'])	/* board of squares */
#define	ACS_LANTERN	(acs_map['i'])	/* lantern symbol */
#define	ACS_BLOCK	(acs_map['0'])	/* solid square block */

/* Funny "characters" enabled for various special function keys for input */
/* This list is created from caps and curses.ed. Do not edit it! */
#define	KEY_MIN		0401		/* Minimum curses key */
#define	KEY_BREAK	0401		/* break key (unreliable) */
#define	KEY_DOWN	0402		/* Sent by terminal down arrow key */
#define	KEY_UP		0403		/* Sent by terminal up arrow key */
#define	KEY_LEFT	0404		/* Sent by terminal left arrow key */
#define	KEY_RIGHT	0405		/* Sent by terminal right arrow key */
#define	KEY_HOME	0406		/* Sent by home key. */
#define	KEY_BACKSPACE	0407		/* Sent by backspace key */
#define	KEY_F0		0410		/* function key f0. */
#define	KEY_F(n)	(KEY_F0+(n))	/* Space for 64 function keys */
					/* is reserved. */
#define	KEY_DL		0510		/* Sent by delete line key. */
#define	KEY_IL		0511		/* Sent by insert line. */
#define	KEY_DC		0512		/* Sent by delete character key. */
#define	KEY_IC		0513		/* Sent by ins char/enter mode key. */
#define	KEY_EIC		0514		/* Sent by rmir or smir in ins mode. */
#define	KEY_CLEAR	0515		/* Sent by clear screen or erase key. */
#define	KEY_EOS		0516		/* Sent by clear-to-end-of-screen. */
#define	KEY_EOL		0517		/* Sent by clear-to-end-of-line key. */
#define	KEY_SF		0520		/* Sent by scroll-forward/down key */
#define	KEY_SR		0521		/* Sent by scroll-backward/up key */
#define	KEY_NPAGE	0522		/* Sent by next-page key */
#define	KEY_PPAGE	0523		/* Sent by previous-page key */
#define	KEY_STAB	0524		/* Sent by set-tab key */
#define	KEY_CTAB	0525		/* Sent by clear-tab key */
#define	KEY_CATAB	0526		/* Sent by clear-all-tabs key. */
#define	KEY_ENTER	0527		/* Enter/send (unreliable) */
#define	KEY_SRESET	0530		/* soft (partial) reset (unreliable) */
#define	KEY_RESET	0531		/* reset or hard reset (unreliable) */
#define	KEY_PRINT	0532		/* print or copy */
#define	KEY_LL		0533		/* Sent by home-down key */
					/* The keypad is arranged like this: */
					/*    a1    up    a3   */
					/*   left   b2  right  */
					/*    c1   down   c3   */
#define	KEY_A1		0534		/* Upper left of keypad */
#define	KEY_A3		0535		/* Upper right of keypad */
#define	KEY_B2		0536		/* Center of keypad */
#define	KEY_C1		0537		/* Lower left of keypad */
#define	KEY_C3		0540		/* Lower right of keypad */
#define	KEY_BTAB	0541		/* Back tab key */
#define	KEY_BEG		0542		/* beg(inning) key */
#define	KEY_CANCEL	0543		/* cancel key */
#define	KEY_CLOSE	0544		/* close key */
#define	KEY_COMMAND	0545		/* cmd (command) key */
#define	KEY_COPY	0546		/* copy key */
#define	KEY_CREATE	0547		/* create key */
#define	KEY_END		0550		/* end key */
#define	KEY_EXIT	0551		/* exit key */
#define	KEY_FIND	0552		/* find key */
#define	KEY_HELP	0553		/* help key */
#define	KEY_MARK	0554		/* mark key */
#define	KEY_MESSAGE	0555		/* message key */
#define	KEY_MOVE	0556		/* move key */
#define	KEY_NEXT	0557		/* next object key */
#define	KEY_OPEN	0560		/* open key */
#define	KEY_OPTIONS	0561		/* options key */
#define	KEY_PREVIOUS	0562		/* previous object key */
#define	KEY_REDO	0563		/* redo key */
#define	KEY_REFERENCE	0564		/* ref(erence) key */
#define	KEY_REFRESH	0565		/* refresh key */
#define	KEY_REPLACE	0566		/* replace key */
#define	KEY_RESTART	0567		/* restart key */
#define	KEY_RESUME	0570		/* resume key */
#define	KEY_SAVE	0571		/* save key */
#define	KEY_SBEG	0572		/* shifted beginning key */
#define	KEY_SCANCEL	0573		/* shifted cancel key */
#define	KEY_SCOMMAND	0574		/* shifted command key */
#define	KEY_SCOPY	0575		/* shifted copy key */
#define	KEY_SCREATE	0576		/* shifted create key */
#define	KEY_SDC		0577		/* shifted delete char key */
#define	KEY_SDL		0600		/* shifted delete line key */
#define	KEY_SELECT	0601		/* select key */
#define	KEY_SEND	0602		/* shifted end key */
#define	KEY_SEOL	0603		/* shifted clear line key */
#define	KEY_SEXIT	0604		/* shifted exit key */
#define	KEY_SFIND	0605		/* shifted find key */
#define	KEY_SHELP	0606		/* shifted help key */
#define	KEY_SHOME	0607		/* shifted home key */
#define	KEY_SIC		0610		/* shifted input key */
#define	KEY_SLEFT	0611		/* shifted left arrow key */
#define	KEY_SMESSAGE	0612		/* shifted message key */
#define	KEY_SMOVE	0613		/* shifted move key */
#define	KEY_SNEXT	0614		/* shifted next key */
#define	KEY_SOPTIONS	0615		/* shifted options key */
#define	KEY_SPREVIOUS	0616		/* shifted prev key */
#define	KEY_SPRINT	0617		/* shifted print key */
#define	KEY_SREDO	0620		/* shifted redo key */
#define	KEY_SREPLACE	0621		/* shifted replace key */
#define	KEY_SRIGHT	0622		/* shifted right arrow */
#define	KEY_SRSUME	0623		/* shifted resume key */
#define	KEY_SSAVE	0624		/* shifted save key */
#define	KEY_SSUSPEND	0625		/* shifted suspend key */
#define	KEY_SUNDO	0626		/* shifted undo key */
#define	KEY_SUSPEND	0627		/* suspend key */
#define	KEY_UNDO	0630		/* undo key */
#define	KEY_MOUSE	0631		/* Mouse event has occured */
#define	KEY_MAX		0777		/* Maximum curses key */

/*
 *	The definition for 'reg' is not standard, and is provided for
 *	compatibility reasons. User's are discouraged from using this.
 */
#define	reg	register

/* Various video attributes */
#define	A_STANDOUT	000010000000
#define	_STANDOUT	A_STANDOUT    /* for compatability with old curses */
#define	A_UNDERLINE	000020000000
#define	A_REVERSE	000040000000
#define	A_BLINK		000100000000
#define	A_DIM		000200000000
#define	A_BOLD		000400000000
#define	A_ALTCHARSET	001000000000

/* The next two are subject to change so don't depend on them */
#define	A_INVIS		010000000000
#define	A_PROTECT	020000000000U

#define	A_NORMAL	000000000000
#define	A_ATTRIBUTES	031777700000U	/* 0xCFFF8000 */
#define	A_CHARTEXT	006000077777	/* 0x30007FFF */
#define	A_COLOR		000007700000

#define	A_WATTRIBUTES	031770000000U	/* 0xCFE00000 */
#define	A_WCHARTEXT	006007777777	/* 0x301FFFFF */

#define	COLOR_PAIR(n)	((n) << 15)
#define	PAIR_NUMBER(n)	(((n) & A_COLOR) >> 15)

/* definition of 8 basic color	*/
#define	COLOR_BLACK	0
#define	COLOR_RED	1
#define	COLOR_GREEN	2
#define	COLOR_YELLOW	3
#define	COLOR_BLUE	4
#define	COLOR_MAGENTA	5
#define	COLOR_CYAN	6
#define	COLOR_WHITE	7

/* mouse related macros: don't change these definitions or bit-masks.	*/
/* they are interdependent (used by _map_button() in tgetch()		*/
#define	BUTTON_RELEASED		0
#define	BUTTON_PRESSED		1
#define	BUTTON_CLICKED		2
#define	BUTTON_DOUBLE_CLICKED	3
#define	BUTTON_TRIPLE_CLICKED	4

#define	MOUSE_X_POS		(Mouse_status.x)
#define	MOUSE_Y_POS		(Mouse_status.y)
#define	A_BUTTON_CHANGED	(Mouse_status.changes & 7)
#define	MOUSE_MOVED		(Mouse_status.changes & 8)
#define	MOUSE_POS_REPORT	(Mouse_status.changes & 16)
#define	BUTTON_CHANGED(x)	(Mouse_status.changes & (1 << ((x) - 1)))
#define	BUTTON_STATUS(x)	(Mouse_status.button[(x)-1])

/* definition of mouse bit-masks	*/
#define	BUTTON1_RELEASED	000000000001
#define	BUTTON1_PRESSED		000000000002
#define	BUTTON1_CLICKED		000000000004
#define	BUTTON1_DOUBLE_CLICKED	000000000010
#define	BUTTON1_TRIPLE_CLICKED	000000000020
#define	BUTTON2_RELEASED	000000000040
#define	BUTTON2_PRESSED		000000000100
#define	BUTTON2_CLICKED		000000000200
#define	BUTTON2_DOUBLE_CLICKED	000000000400
#define	BUTTON2_TRIPLE_CLICKED	000000001000
#define	BUTTON3_RELEASED	000000002000
#define	BUTTON3_PRESSED		000000004000
#define	BUTTON3_CLICKED		000000010000
#define	BUTTON3_DOUBLE_CLICKED	000000020000
#define	BUTTON3_TRIPLE_CLICKED	000000040000
#define	ALL_MOUSE_EVENTS	000000077777
#define	REPORT_MOUSE_POSITION	000000100000

#ifdef	__cplusplus
}
#endif

#endif	/* _CURSES_H */
