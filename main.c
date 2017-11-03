#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
  
  // OPEN DIRECTORY
  // EDIT DIRECTORY HERE
  DIR * d = opendir( "." );

  // DIRECTORY INFO STRUCT
  struct dirent * file = readdir( d );
  // FILE INFO STRUCT
  struct stat sb;

  printf( "Statistics for directory: %s\n", file->d_name );

  // DIRECTORY SIZE
  int size = 0;
  while ( file ) {
    stat( file->d_name, &sb );
    if ( file->d_type == DT_REG ) size += sb.st_size;
    file = readdir( d );
  }
  printf( "Total directory size: %d bytes\n", size );

  // RESET ENTRY
  closedir( d );

  // EDIT DIRECTORY HERE
  d = opendir( "." );
  file = readdir( d );
  
  // DIRECTORIES AND FILES
  printf( "Displaying Contents of: %s\n", file->d_name );
  while ( file ) {
    
    // DIRECTORIES
    if ( file->d_type == DT_DIR ) {
      printf( "\tDIRECTORY:\t%s\n", file->d_name );
    }
    // REGULAR FILES
    else if ( file->d_type == DT_REG ) {
      stat( file->d_name, &sb );
      printf( "\tFILE:\t%s  \t%lld bytes\n", file->d_name, sb.st_size );
    }

    // SET TO NEXT ENTRY
    file = readdir( d );
  }

  // CLOSE
  closedir( d );
  
  return 0;
}
