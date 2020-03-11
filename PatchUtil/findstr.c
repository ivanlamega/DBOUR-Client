//-------------------------------------------------------------------------
//
//  Program:     FINDSTR ( Find String )
//
//  Description: Locates a given string within a file
//
//  Syntax:      FINDSTR  filename string
//
//
//  (c) Copyright 1991-2002, Pocket Soft, Inc.  ALL RIGHTS RESERVED
//
//-------------------------------------------------------------------------

# include       <stdio.h>
# include       <fcntl.h>
# include       <sys\types.h>
# include       <sys\stat.h>
# include       <io.h>
# include	<string.h>
# include	<process.h>
# include	<stdlib.h>


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


void  _cdecl main( SHRT ArgCount, UCHAR *ArgVec[] );
SHRT   OpenFile( UCHAR * Name );
SHRT   CloseFile( void );
UCHAR  *GetData( LONG Offset, SHRT Length );

# define	FALSE		0
# define	TRUE		1

# define	BINBUFSIZE	1024

static  SHRT     FileDesc = -1;
static  LONG    FilePos;
static  SHRT     FileChars;
static  UCHAR    FileBuffer[ BINBUFSIZE ];


//-------------------------------------------------------------------------
//  main
//-------------------------------------------------------------------------
void _cdecl main ( ArgCount, ArgVec )

SHRT	ArgCount;
UCHAR	*ArgVec[];

{
    LONG        RecPos;
    UCHAR        *RecPtr;
    SHRT		Len;
    SHRT	        NeverFound = TRUE;

    // print banner
    printf( "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n" );
# ifdef NONPRO
    printf( "           FINDSTR Version 6.50 - RTPatch(R) Software Update System\n");
# else
    printf( "   FINDSTR Version 6.50 - RTPatch(R) Professional - Software Update System\n");
# endif
    printf( "       (C) Copyright Pocket Soft, Inc., 1991-2002.  All Rights Reserved.\n" );
    printf( "컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�\n\n" );

    // Check for Valid Input
    if ( ArgCount != 3 )
    {
        fprintf( stderr, "SYNTAX : FINDSTR <FileName> <String>\n\n" );
        fprintf( stderr, "<FileName> - File to be searched\n");
        fprintf( stderr, "<String>   - String to search for in file\n");
        exit( 1 );
    }

    Len = strlen( ArgVec[2] );

    // open file
    if ( OpenFile( ArgVec[1] ) )
    {
	fprintf( stderr, "Cannot open '%s' .... not processed\n", ArgVec[1] );
	exit(1);
    }

    // scan file
    for ( RecPos = 0 ;
          RecPtr = GetData( RecPos, Len ) ;
	  RecPos++ )
    {
      if ( !memcmp( RecPtr, ArgVec[2], Len ) )
      {
          NeverFound = FALSE;

          printf( "  String Found at Position %lxH\n", RecPos );
      }
    }


    if ( NeverFound )
    {
      printf( "  String Not Found.\n");
    }

    // close file
    CloseFile();
}

//------------------------------------------------------------------------
//  OpenFile
//------------------------------------------------------------------------
SHRT     OpenFile ( UCHAR * Name )
{
    /* There is already a file opened */
    if ( FileDesc != -1 )
    {  
      return ( -1 );
    }

    /* Cannot open the file */
    if ( ( FileDesc = open( Name, O_RDONLY | O_BINARY )) < 0 )
    {
      return( -1 );
    }

    /* Success */
    FilePos   = 0;
    FileChars = 0;

    return( 0 );
}

//------------------------------------------------------------------------
//  CloseFile
//------------------------------------------------------------------------
SHRT     CloseFile ()
{
    if ( FileDesc == -1 )
    {  
      return( -1 );
    }

    close( FileDesc );

    FileDesc = -1;

    return( 0 );
}

//------------------------------------------------------------------------
//  GetData
//------------------------------------------------------------------------
UCHAR    *GetData ( LONG Offset,
                   SHRT  Length )

{
    if ( Offset >= FilePos
           && Offset+Length <= FilePos+FileChars )
    {
        /* The requested information is already in the buffer,
            just return a pointer to it */

        return( FileBuffer + (SHRT) (Offset - FilePos) );
    }
    else
    {
        /* All of the requested information is not in the buffer,
            must read the file */
        FilePos = Offset;

        lseek( FileDesc, FilePos, SEEK_SET );

        if ( (FileChars = read( FileDesc, FileBuffer, BINBUFSIZE )) <= 0 )
	{
            /* Not enough characters were read - return error */
            return( (UCHAR *) NULL );
	}
        else
	{
            return( FileBuffer );
	}
    }
}


