/*
 * prototype.c
 *
 * A Simple Byte Code Compiler for Lisp
 *
 * Copyright (C) 2013-06-07 liutos <mat.liutos@gmail.com>
 */
#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type.h"
#include "compiler.h"
#include "vm.h"
#include "object.h"
#include "prims.h"

int main(int argc, char *argv[])
{
  char *inputs[] = {
      "(read-from-string \"`(a ,b ,@c d)\")",
      "(expand-macro '`(a ,b ,@c d))",
//      "`(a ,b ,@c d)",
      "(read-from-string \"`,'*standard-out*\")",
      "(expand-macro '`,'*standard-out*)",
      "`,'*standard-out*",
  };
  init_global_variable();
  init_prims();
  init_macros();
  for (int i = 0; i < sizeof(inputs) / sizeof(char *); i++) {
    writef(standard_out, ">> %s\n", make_string(inputs[i]));
    lisp_object_t *expr = read_object_from_string(inputs[i]);
    expr = compile_to_bytecode(expr);
    expr = run_by_llam(expr);
    if (is_signaled(expr))
      writef(standard_out, "%?\n", expr);
    else
      writef(standard_out, "=> %?\n", expr);
  }
  return 0;
}
