#include <stdio.h>
#include <stdlib.h>

int f(const char* c) {
  int a = -1, b = -1;
  for (int i = 0; c[i] != '\0'; i++) {
    if ('0' <= c[i] && c[i] <= '9') {
      // without the line below `atoi(const char*)` just reads everything
      // numeric until it's not, so I should restrict it by giving only
      // one character
      char curr = c[i];
      if (a == -1) {
        a = atoi(&curr);
        b = atoi(&curr);
      } else {
        b = atoi(&curr);
      }
    }
  }
  // printf("%d %d\n", a, b);
  return a * 10 + b;
}

int main(int argc, char* argv[]) {
  char* input = "../sample_tests/day01.in";
  if (argc > 1) {
    input = argv[1];
  }

  FILE* fp;
  char s[1024];
  int answer = 0;

  fp = fopen(input, "r");
  while (fgets(s, sizeof(s), fp) != NULL) {
    answer += f(s);
  }

  printf("%d\n", answer);
}