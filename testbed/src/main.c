#include <core/logger.h>
#include <core/asserts.h>

int main()
{
  KFATAL("Fatal message. %f", 3.14f);
  KASSERT(1 == 2);
  return 0;
}