#ifndef _NODE_INTERNAL_H
#define _NODE_INTERNAL_H
#include <stdbool.h>
#include <chopsui/node.h>
#include <chopsui/css.h>

struct sui_type {
	const struct sui_type_impl *impl;
	struct sui_type *next;
};

#endif
