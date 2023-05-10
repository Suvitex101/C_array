#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t read_textfile(const *filename, size_t letters);
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        dprintf(2, "Usage: %s filename\n", av[0]);
        exit(1);
    }
    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);
    return (0);
}

ssize_t read_textfile(const *filename, size_t letters)
{
    ssize_t op, rd, wr;
    char *buffer;
    
     if (filename == NULL)
          return (0);
          
    buffer = malloc(sizeof(char) *letters);
    
    if (buffer == NULL)
        return (0);
        
    
    op = open(filename, O_RDONLY);
    rd = read(op, buffer, letters);
    wr = write(STDOUT_FILENO, buffer, rd);
    
  if (op == - 1 || rd == - 1 || wr == - 1 || rd != wr) 
  {
    free(buffer);
    return (0);
  }
  
  free(buffer);
  close(op);
  
  return (wr);
}