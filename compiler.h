/*
 * compiler.h
 *
 *  Created on: 2013年7月18日
 *      Author: liutos
 */

#ifndef COMPILER_H_
#define COMPILER_H_

#include "type.h"

extern lt *compile_as_lambda(lt *);
extern lt *compile_object(lt *, lt *);

#endif /* COMPILER_H_ */
