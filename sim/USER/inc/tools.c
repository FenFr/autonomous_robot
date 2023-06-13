
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

int ferr( char *txt, char *cmt, int para )
    {
       fflush( stdout );
       fprintf( stderr, "sorry fatal error: %s (%s) (%d)\n", txt,cmt,para );
       perror( "perror" );
       exit( 1 );
    }

char *m_alloc( int size, char *name )
     {
//        char *malloc();
        char *p = malloc( size );
        if ( p == 0 )
           ferr( "can't alloc enough memory", name, size );
        return( p );
     }

char *m_free( char *p, char *name )
     {
//        char *free();
        if ( p == 0 )
           ferr( "can't free zero pointer", "", 0 );
	else free( p );
        return( p );
     }

char *tst_opt( char *opt, char *name )
     {
        while( *name && *opt == *name )
        {
	   opt++; name++;
        }
        return( (! *name && *opt == '=')? opt + 1: 0 );
     }

int prt_dot( int run )
    {
       fprintf( stderr, "%c", ((run + 1) % 10)? '.':'|' );
       fflush( stderr );
    }

int i_arg( char *opt, int *var, char *name )
    {
       if (( opt = tst_opt( opt, name )))
	  *var = strtol( opt, (char **) 0, 0 );
       return( (opt)? 1: 0 );
    }

int f_arg( char *opt, double *var, char *name )
    {
       double atof();
       if (( opt = tst_opt( opt, name )))
	  *var = atof( opt );
       return( (opt)? 1: 0 );
    }

char *mk_name( char *n1, char *n2 )
     {
        char *p = m_alloc( strlen( n1 ) + strlen( n2 ) + 1, "mk_name" );
        sprintf( p, "%s.%s", n1, n2 );
        return( p );
     }

