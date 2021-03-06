/*----------------------------------------------------------------------
  $Id: os-sol.h 13025 2003-05-23 16:05:21Z hubert $

            T H E    P I N E    M A I L   S Y S T E M

   Laurence Lundblade and Mike Seibel
   Networks and Distributed Computing
   Computing and Communications
   University of Washington
   Administration Builiding, AG-44
   Seattle, Washington, 98195, USA
   Internet: lgl@CAC.Washington.EDU
             mikes@CAC.Washington.EDU

   Please address all bugs and comments to "pine-bugs@cac.washington.edu"


   Pine and Pico are registered trademarks of the University of Washington.
   No commercial use of these trademarks may be made without prior written
   permission of the University of Washington.

   Pine, Pico, and Pilot software and its included text are Copyright
   1989-1998 by the University of Washington.

   The full text of our legal notices is contained in the file called
   CPYRIGHT, included with this distribution.


   Pine is in part based on The Elm Mail System:
    ***********************************************************************
    *  The Elm Mail System  -  Revision: 2.13                             *
    *                                                                     *
    * 			Copyright (c) 1986, 1987 Dave Taylor              *
    * 			Copyright (c) 1988, 1989 USENET Community Trust   *
    ***********************************************************************
 

  ----------------------------------------------------------------------*/

#ifndef _OS_INCLUDED
#define _OS_INCLUDED

#include "../c-client/osdep.h"


/*----------------------------------------------------------------------

   This first section has some constants that you may want to change
   for your configuration.  This is the Sun Solaris version of the os.h file.
   Further down in the file are os-dependent things that need to be set up
   correctly for each os.  They aren't interesting, they just have to be
   right.  There are also a few constants down there that may be of
   interest to some.

 ----*/

/*----------------------------------------------------------------------
   Define this if you want the disk quota to be checked on startup.
   Of course, this only makes sense if your system has quotas.  If it doesn't,
   there should be a dummy disk_quota() routine in os-xxx.c so that defining
   this won't be harmful anyway.
 ----*/
/* #define USE_QUOTAS */



/*----------------------------------------------------------------------
   Define this if you want to be sure to not allow users to change their
   From header line when they send out mail. Even if you don't define
   this the default is to not allow From to be changed. The user would have
   to edit (by hand) "allow-changing-from" into their .pinerc feature list
   or the sys-admin would have to include it in the default feature-list.
   Even after that, the user still has to include it in either their
   default-composer-hdrs or customized-hdrs to get at it. Instead of
   defining NEVER_ALLOW_CHANGING_FROM, an easier way of preventing From
   changing is to put the feature "no-allow-changing-from" in the
   /usr/local/lib/pine.conf.fixed file.
 ----*/
/* #define NEVER_ALLOW_CHANGING_FROM */



/*----------------------------------------------------------------------
   Define this if you want to allow users to turn on the feature that
   enables sending to take place in a fork()'d child.  This may reduce
   the time on the user's wall clock it takes to post mail.
   NOTE: You'll also have to make sure the appropriate osdep/postreap.*
         file is included in the os-*.ic file for your system.
 ----*/
#define BACKGROUND_POST



/*----------------------------------------------------------------------
    Turn this on if you want to disable the keyboard lock function.
 ----*/
/* #define NO_KEYBOARD_LOCK */



/*----------------------------------------------------------------------
    Turn this on to trigger QP encoding of sent message text if it contains
  "From " at the beginning of a line or "." on a line by itself.
 ----*/
/* #define ENCODE_FROMS */



/*----------------------------------------------------------------------
    Timeouts (seconds)
 ----*/
#ifndef DF_MAILCHECK
#define DF_MAILCHECK      "150" /* How often to check for new mail, by
				   default.  There's some expense in doing
				   this so it shouldn't be done too
				   frequently.  (Can be set in config
				   file now.)  */
#endif

/*----------------------------------------------------------------------
    Check pointing (seconds)
 ----*/
#define CHECK_POINT_TIME (7*60) /* Check point the mail file (write changes
				   to disk) if more than CHECK_POINT_TIME
				   seconds have passed since the first
				   change was made.  Depending on what is
				   happening, we may wait up to three times
				   this long, since we don't want to do the
				   slow check pointing and irritate the user. */
                                     
#define CHECK_POINT_FREQ   (12) /* Check point the mail file if there have been
                                   at least this many (status) changes to the
				   current mail file.  We may wait longer if
				   it isn't a good time to do the checkpoint. */



/*----------------------------------------------------------------------
 In scrolling through text, the number of lines from the previous
 screen to overlap when showing the next screen.  Usually set to two.
 ----*/
#define	DF_OVERLAP	"2"



/*----------------------------------------------------------------------
 When scrolling screens, the number of lines from top and bottom of
 the screen to initiate single-line scrolling.
 ----*/
#define	DF_MARGIN	"0"



/*----------------------------------------------------------------------
 Default fill column for pine composer and maximum fill column.  The max
 is used to stop people from setting their custom fill column higher than
 that number.  Note that DF_FILLCOL is a string but MAX_FILLCOL is an integer.
 ----*/
#define	DF_FILLCOL	"74"
#define	MAX_FILLCOL	80



/*----- System-wide config file ----------------------------------------*/
#ifndef SYSTEM_PINERC
#define SYSTEM_PINERC             "/usr/local/lib/pine.conf"
#endif
#ifndef SYSTEM_PINERC_FIXED
#define SYSTEM_PINERC_FIXED       "/usr/local/lib/pine.conf.fixed"
#endif



/*----------------------------------------------------------------------
   The default folder names and folder directories (some for backwards
   compatibility).  Think hard before changing any of these.
 ----*/
#define DF_DEFAULT_FCC            "sent-mail"
#define DEFAULT_SAVE              "saved-messages"
#define POSTPONED_MAIL            "postponed-mail"
#define POSTPONED_MSGS            "postponed-msgs"
#define INTERRUPTED_MAIL          ".pine-interrupted-mail"
#define DEADLETTER                "dead.letter"
#define DF_MAIL_DIRECTORY         "mail"
#define INBOX_NAME                "INBOX"
#define DF_SIGNATURE_FILE         ".signature"
#define DF_ELM_STYLE_SAVE         "no"
#define DF_HEADER_IN_REPLY        "no"
#define DF_OLD_STYLE_REPLY        "no"
#define DF_USE_ONLY_DOMAIN_NAME   "no"
#define DF_FEATURE_LEVEL          "sapling"
#define DF_SAVE_BY_SENDER         "no"
#define DF_SORT_KEY               "arrival"
#define DF_AB_SORT_RULE           "fullname-with-lists-last"
#define DF_FLD_SORT_RULE          "alphabetical"
#define DF_SAVED_MSG_NAME_RULE    "default-folder"
#define DF_FCC_RULE               "default-fcc"
#define DF_STANDARD_PRINTER       "lp"
#define ANSI_PRINTER              "attached-to-ansi"
#define DF_ADDRESSBOOK            ".addressbook"
#define DF_BUGS_FULLNAME          "Pine Developers"
#define DF_BUGS_ADDRESS           "pine-bugs@cac.washington.edu"
#define DF_SUGGEST_FULLNAME       "Pine Developers"
#define DF_SUGGEST_ADDRESS        "pine-suggestions@cac.washington.edu"
#define DF_PINEINFO_FULLNAME      "Pine-Info News Group"
#define DF_PINEINFO_ADDRESS       "pine-info@cac.washington.edu"
#define DF_LOCAL_FULLNAME         "Local Support"
#define DF_LOCAL_ADDRESS          "postmaster"
#define DF_KBLOCK_PASSWD_COUNT    "1"
#define DF_REMOTE_ABOOK_HISTORY   "3"

/*----------------------------------------------------------------------
   The default printer when pine starts up for the first time with no printer
 ----*/
#define DF_DEFAULT_PRINTER        ANSI_PRINTER



/*----- The usual sendmail configuration for sending mail on Unix ------*/
#ifndef SENDMAIL
#define SENDMAIL	"/usr/lib/sendmail"
#endif
#ifndef SENDMAILFLAGS
#define SENDMAILFLAGS	"-bs -odb -oem"	/* send via smtp with backgroud
					   delivery and mail back errors */
#endif


/*----------------------------------------------------------------------
   If no nntp-servers are defined, this program will be used to post news.
 ----*/
/* #define SENDNEWS	"/usr/local/bin/inews -h" */


/*--------- Program employed by users to change their password ---------*/
#ifndef	PASSWD_PROG
#define	PASSWD_PROG	"/bin/passwd"
#endif


/*-------------- A couple constants used to size arrays ----------------*/
#include <sys/param.h>          /* Get it from param.h if available */
#undef MAXPATH                  /* Sometimes defined in param.h differently */
#define MAXPATH MAXPATHLEN      /* Longest pathname we ever expect */
/* #define MAXPATH        (512) */ /* Longest pathname we ever expect */
#define MAXFOLDER      (128)    /* Longest foldername we ever expect */  


/*-- Max screen pine will display on. Used to define some array sizes --*/
#define MAX_SCREEN_COLS  (170) 
#define MAX_SCREEN_ROWS  (200) 


/*----------------------------------------------------------------------
    Where to put the output of pine in debug mode. Files are created
 in the user's home directory and have a number appended to them when
 there is more than one.
 ----*/
#define DEBUGFILE	".pine-debug"

/*----------------------------------------------------------------------
    The number of debug files to save in the user's home diretory. The files
 are useful for figuring out what a user did when he complains that something
 went wrong. It's important to keep a bunch around, usually 4, so that the
 debug file in question will still be around when the problem gets 
 investigated. Users tend to go in and out of Pine a few times and there
 is one file for each pine invocation
 ----*/
#define NUMDEBUGFILES 4

/*----------------------------------------------------------------------
   The default debug level to set (approximate meanings):
       1 logs only highest level events and errors
       2 logs events like file writes
       3
       4 logs each command
       5
       6 
       7 logs details of command execution (7 is highest to run any production)
       8
       9 logs gross details of command execution
 ----*/
#define DEFAULT_DEBUG 2



/*----------------------------------------------------------------------
    Various maximum field lengths, probably shouldn't be changed.
 ----*/
#define MAX_FULLNAME     (100) 
#define MAX_NICKNAME      (80)
#define MAX_ADDRESS      (500)
#define MAX_NEW_LIST     (500)  /* Max addrs to be added when creating list */
#define MAX_SEARCH       (100)  /* Longest string to search for             */
#define MAX_ADDR_EXPN   (1000)  /* Longest expanded addr                    */
#define MAX_ADDR_FIELD (10000)  /* Longest fully-expanded addr field        */


#endif /* _OS_INCLUDED */
