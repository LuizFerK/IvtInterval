#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
  float x, y, e, distance, center, tmp;
  e = 2.718282;

  float ivt(float z) {
    return pow(e, -z) - 2 * pow(z, 2) + 4;
  };

  bool isOpposite(float cond1, float cond2) {
    if ((cond1 <= 0 && cond2 >= 0) || (cond1 >= 0 && cond2 <= 0)) {
      return true;
    } else {
      return false;
    }
  }
  
  printf("Digite os valores do intervalo:\n");
  scanf("%f %f", &x, &y);

  if (x > y) {
    tmp = x;
    x = y;
    y = tmp;
  }

  if (isOpposite(ivt(x), ivt(y))) {
    distance = y - x;

    while (distance > 0.1) {
      center = x + distance / 2;

      if (isOpposite(ivt(x), ivt(center))) {
        y = center;
      } else if (isOpposite(ivt(center), ivt(y))) {
        x = center;
      }

      distance = y - x;
    }

    printf("A equação tem pelo menos uma solução neste intervalo: [%f, %f]\n", x, y);
  } else {
    printf("Não é possível afirmar que existe solução neste intervalo, tente outros dois números.\n");
  }

  return 0;
}