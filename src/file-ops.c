
#include <sys/types.h>
#include <fcntl.h>
#include <io.h>


ftruncate (fd, length)
     int fd;
     off_t length;
{
  return _chsize (fd, length);
}


