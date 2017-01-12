#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "css.h"
#include "parser.h"
#include "subparser.h"
#include "util/list.h"
#include "util/unicode.h"
#include "util/errors.h"

stylesheet_t *css_parse(const char *source, errors_t **errs) {
	stylesheet_t *css = calloc(1, sizeof(stylesheet_t));
	css->rules = list_create();
	css->media_rules = list_create();
	css->keyframes = list_create();

	struct parser_state state;
	memset(&state, 0, sizeof(state));
	state.errs = errs;
	state.data = css;
	parser_init(&state, parse_document, css_parse_ch);

	while (*source) {
		uint32_t ch = utf8_decode(&source);
		parse_ch(&state, ch);
	}

	parser_cleanup(&state);
	return css;
}
