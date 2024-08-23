/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void)
{
  char *buf, *A, *B, *method;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  int n1 = 0, n2 = 0;

  /* Extract the two arguments */
  if ((buf = getenv("QUERY_STRING")) != NULL)
  {
    A = strchr(buf, 'A');
    B = strchr(buf, 'B');
    *A = '\0';
    *B = '\0';
    strcpy(arg1, A + 2);
    strcpy(arg2, B + 2);
    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }
  method = getenv("REQUEST_METHOD");
  /* Make the response body */
  sprintf(content, "QUERY_STRING=%s", buf);
  sprintf(content, "Welcome to add.com: ");
  sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
  sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
  sprintf(content, "%sThanks for visiting!\r\n", content);
  /* Generate the HTTP response */
  printf("Connection: close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");

  // method가 GET일 경우에만 response body 보냄
  if (strcasecmp(method, "GET") == 0)
  {
    printf("%s", content);
  }
  fflush(stdout);

  exit(0);
}