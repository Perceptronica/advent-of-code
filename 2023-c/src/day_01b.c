#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *words[] = {"one", "two",   "three", "four", "five",
                 "six", "seven", "eight", "nine"};

int f(char *c) {
  bool first_found = false;
  int a = 0, b = 0;
  for (int i = 0; i < strlen(c); ++i) {
    if ('0' <= c[i] && c[i] <= '9') {
      char current = c[i];
      if (!first_found) {
        first_found = true;
        a = atoi(&current);
      }
      b = atoi(&current);
    } else {
      for (int j = 0; j < 9; ++j) {
        char *occ = strstr(&c[i], words[j]);
        if (occ == &c[i]) {
          b = j + 1;
          if (!first_found) {
            first_found = true;
            a = j + 1;
          }
        }
      }
    }
  }
  printf("%d %d\n", a, b);
  return a * 10 + b;
}

int main(int argc, char *argv[]) {
  char *input = "../sample_tests/day_01.input";
  if (argc > 1) {
    input = argv[1];
  }
  FILE *fp;
  fp = fopen(input, "r");

  char s[1024];
  int answer = 0;
  while (fgets(s, sizeof(s), fp) != NULL) {
    answer += f(s);
  }
  printf("%d\n", answer);
}
