#include <chopsui/util/list.h>
#include <chopsui/node.h>

void node_detach(struct sui_node *node) {
	if (!node || !node->parent) {
		return;
	}
	for (size_t i = 0; i < node->parent->children->length; ++i) {
		struct sui_node *n = node->parent->children->items[i];
		if (n == node) {
			list_del(node->parent->children, i);
			node->parent = NULL;
			return;
		}
	}
}
