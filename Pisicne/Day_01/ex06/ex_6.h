#ifndef _EX_6_H_
# define _EX_6_H_

typedef union	s_foo3
{
  short		bar;
  short		foo;
}		t_foo3;

typedef struct	s_foo2
{
  short		foo;
  t_foo3	bar;
}		t_foo2;

typedef union s_foo
{
  t_foo2	foo;
  int		bar;
}		t_foo;

#endif /* _EX_6_H_ */
