//-------------------------------------------------------------------------
//
//  Program:     COMPFILE ( Compare Files )
//
//  Description: Compares two files and prints the locations where they
//               are different.
//
//  Syntax:      COMPFILE  <file1> <file2>
//
//
//  (c) Copyright 1991-2002, Pocket Soft, Inc.  ALL RIGHTS RESERVED
//
//-------------------------------------------------------------------------

# include	<stdio.h>
# include	<fcntl.h>
# include	<sys\types.h>
# include	<sys\stat.h>
# include	<io.h>
# include	<process.h>


# define CHAR   signed char
# define UCHAR  unsigned char
# define SHRT   signed short 
# define USHRT  unsigned short
# define LONG   signed long
# define ULONG  unsigned long

# ifdef _M_ALPHA
#  ifndef UNALIGNED
#    define UNALIGNED __unaligned
#  endif
# else
#  ifndef UNALIGNED
#    define UNALIGNED
#  endif
# endif

void _cdecl main(  SHRT argc,  UCHAR *argv[] );
SHRT  OpenBuffer ( SHRT Which, UCHAR *Name );
void NextChar (    SHRT Which );


# define	BUFSIZE		8 * 1024

# define	FILE1		0
# define	FILE2		1

# define	FALSE		0
# define	TRUE		1

struct
{
    SHRT	FD;
    LONG	Size;
    LONG	FilePos;
    SHRT	Eof;
    SHRT	c;
    SHRT	BChars;
    SHRT	BPos;
    UCHAR	Buffer[BUFSIZE];
} FileBuffer[2];


UCHAR Header[]  = "Mismatches found at the following places:\n\n";
UCHAR Format1[] = "  Position %lxH for %lxH bytes.\n";
UCHAR Format2[] = "  Position %lxH, extra %lxH bytes in file: %s\n";

//-----------------------------------------------------------------------
//  main
//----------------------------------------------------------------------
void _cdecl main ( SHRT   ArgCount,
           UCHAR *ArgVec[] )
{
    SHRT		i;
    SHRT         FirstMismatch = TRUE;
    LONG        Position;
    LONG        Length;
    SHRT		NoDifference = TRUE;


    // print banner
    printf( "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n" );
# ifdef NONPRO
    printf( "           COMPFILE Version 6.50 - RTPatch(R) Software Update System\n");
# else
    printf( "   COMPFILE Version 6.50 - RTPatch(R) Professional - Software Update System\n");
# endif
    printf( "       (C) Copyright Pocket Soft, Inc., 1991-2002.  All Rights Reserved.\n" );
    printf( "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\n" );

    // Check for Valid Input
    if ( ArgCount != 3 )
    {
    	fprintf( stderr, "Syntax : COMPFILE <FirstFile> <SecondFile>\n\n" );
    	fprintf( stderr, "<FirstFile>  - Original File\n" );
    	fprintf( stderr, "<SecondFile> - File to compare to Original File\n" );
	exit( 1 );
    }

    // Open Files
    for ( i=FILE1; i<=FILE2 ; i++ )
    {
	if ( OpenBuffer( i, ArgVec[i+1] ) )
	{
    	    fprintf( stderr,
	             "%s : cannot open '%s' .... abort\n",
	    	     ArgVec[0],
		     ArgVec[i+1] );

	    perror( ArgVec[i+1] );

	    exit( 1 );
	}
    }

    // Compare Files byte by byte
    for ( NextChar(FILE1),
              NextChar(FILE2),
	      Position = 0L ;
          !FileBuffer[FILE1].Eof && !FileBuffer[FILE2].Eof ;
    	  NextChar(FILE1),
	      NextChar(FILE2),
	      Position++ )
    {
      // if the bytes do not match its time to print a message
      if ( ( FileBuffer[FILE1].c & 0xff )
             != ( FileBuffer[FILE2].c&0xff ) )
      {
        NoDifference = FALSE;

        Length = 0;

	// Figure out how many mismatch at this position
        for ( Length = 0;
              ( ( FileBuffer[FILE1].c & 0xff ) != ( FileBuffer[FILE2].c&0xff ) )
	        && (!FileBuffer[FILE1].Eof && !FileBuffer[FILE2].Eof) ;
    	      NextChar(FILE1),
	          NextChar(FILE2),
		  Length ++ );

	if ( FirstMismatch )
	{
	    printf( Header );

	    FirstMismatch = FALSE;
	}

	printf ( Format1, Position, Length );

	Position += Length;
      }
    }

    if ( !FirstMismatch )
    {
        printf( "\n" );
    }

    for ( i=FILE1 ; i<=FILE2 ; i++ )
    {
        Length = 0;

    	while ( !FileBuffer[i].Eof )
	{
	  Length ++;
	  NextChar(i);
	}
	
 	if ( Length )
	{
	    printf( Format2, Position, Length, ArgVec[i+1]);

            NoDifference = FALSE;
	}
    }

    if ( NoDifference )
    {
      printf( "Files are identical!\n");
    }

    exit( 0 );
}

//-----------------------------------------------------------------------
//  OpenBuffer - Open Files for comparison
//----------------------------------------------------------------------
SHRT	OpenBuffer( SHRT   Which,
                    UCHAR *Name )
{
    struct	stat	STBuf;

    if ( (FileBuffer[Which].FD = open( Name, O_RDONLY | O_BINARY )) < 0 )
    {
    	return( -1 );
    }

    stat( Name, &STBuf );

    FileBuffer[Which].Size    = STBuf.st_size;
    FileBuffer[Which].FilePos = -1;
    FileBuffer[Which].Eof     = FALSE;
    FileBuffer[Which].BChars  = 0;
    FileBuffer[Which].BPos    = 0;

    return( 0 );
}

//-----------------------------------------------------------------------
//  NextChar - Get Next Character From File
//----------------------------------------------------------------------
void	NextChar ( SHRT Which )
{
    SHRT		TempFD;
    UCHAR	*TempBuf;
    SHRT		TempRead;

    FileBuffer[Which].BPos++;
    FileBuffer[Which].FilePos++;

    if ( FileBuffer[Which].BPos >= FileBuffer[Which].BChars )
    {
    	/* Must read more characters from file */
	FileBuffer[Which].BPos = 0;

	TempFD                   = FileBuffer[Which].FD;
	TempBuf                  = FileBuffer[Which].Buffer;
	TempRead                 = read( TempFD, TempBuf, BUFSIZE );
	FileBuffer[Which].BChars = TempRead;

	if ( FileBuffer[Which].BChars <= 0 )
	{
	    FileBuffer[Which].Eof = TRUE;
	    return;
	}
    }

    FileBuffer[Which].c = FileBuffer[Which].Buffer[FileBuffer[Which].BPos];
}


