#ifndef EX01_HPP
#define EX01_HPP
#include <string.h>

template <typename T>
int compare(const T &p1, const T &p2){
  if (p1 == p2)
    return (0);
  return (p1 < p2 ? -1 : 1);
}

template <>
int compare<const char*>(const char *p1, const char *p2){
  int comp = strcmp(p1, p2);

  if (comp == 0)
    return (0);
  return (comp < 0 ? p2 : p1);
}

#endif
