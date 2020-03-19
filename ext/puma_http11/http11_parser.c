/**
* Copyright (c) 2005 Zed A. Shaw
* You can redistribute it and/or modify it under the same terms as Ruby.
* License 3-clause BSD
*/
#include "http11_parser.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
* capitalizes all lower-case ASCII characters,
* converts dashes to underscores.
*/
static void snake_upcase_char(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	*c &= ~0x20;
	else if (*c == '-')
	*c='_';
}

#define LEN(AT, FPC) (FPC - buffer - parser->AT)
#define MARK(M,FPC) (parser->M = (FPC) - buffer)
#define PTR_TO(F) (buffer + parser->F)

/** Machine **/



/** Data **/

static const int puma_parser_start = 1;
static const int puma_parser_first_final = 46;
static const int puma_parser_error = 0;

static const int puma_parser_en_main = 1;

static const char _puma_parser_nfa_targs[] = {
	0, 0
};

static const char _puma_parser_nfa_offsets[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

static const char _puma_parser_nfa_push_actions[] = {
	0, 0
};

static const char _puma_parser_nfa_pop_trans[] = {
	0, 0
};



int puma_parser_init(puma_parser *parser)  {
	int cs=0;
	
	{
		cs = (int)puma_parser_start;
	}
	
	parser->cs = cs;
	parser->body_start=0;
	parser->content_len=0;
	parser->mark=0;
	parser->nread=0;
	parser->field_len=0;
	parser->field_start=0;
	parser->request = Qnil;
	parser->body = Qnil;
	
	return 1;
}


/** exec **/
size_t puma_parser_execute(puma_parser *parser, const char *buffer, size_t len, size_t off)  {
	const char *p, *pe;
	int cs = parser->cs;
	
	assert(off <= len && "offset past end of buffer");
	
	p = buffer+off;
	pe = buffer+len;
	
	/* assert(*pe == '\0' && "pointer does not end on NUL"); */
	assert((size_t) (pe - p) == len - off && "pointers aren't same distance");
	
	
	{
		if ( p == pe )
		goto _test_eof;
		switch ( cs )
		{
			case 1:
			goto st_case_1;
			case 0:
			goto st_case_0;
			case 2:
			goto st_case_2;
			case 3:
			goto st_case_3;
			case 4:
			goto st_case_4;
			case 5:
			goto st_case_5;
			case 6:
			goto st_case_6;
			case 7:
			goto st_case_7;
			case 8:
			goto st_case_8;
			case 9:
			goto st_case_9;
			case 10:
			goto st_case_10;
			case 11:
			goto st_case_11;
			case 12:
			goto st_case_12;
			case 13:
			goto st_case_13;
			case 14:
			goto st_case_14;
			case 15:
			goto st_case_15;
			case 16:
			goto st_case_16;
			case 46:
			goto st_case_46;
			case 17:
			goto st_case_17;
			case 18:
			goto st_case_18;
			case 19:
			goto st_case_19;
			case 20:
			goto st_case_20;
			case 21:
			goto st_case_21;
			case 22:
			goto st_case_22;
			case 23:
			goto st_case_23;
			case 24:
			goto st_case_24;
			case 25:
			goto st_case_25;
			case 26:
			goto st_case_26;
			case 27:
			goto st_case_27;
			case 28:
			goto st_case_28;
			case 29:
			goto st_case_29;
			case 30:
			goto st_case_30;
			case 31:
			goto st_case_31;
			case 32:
			goto st_case_32;
			case 33:
			goto st_case_33;
			case 34:
			goto st_case_34;
			case 35:
			goto st_case_35;
			case 36:
			goto st_case_36;
			case 37:
			goto st_case_37;
			case 38:
			goto st_case_38;
			case 39:
			goto st_case_39;
			case 40:
			goto st_case_40;
			case 41:
			goto st_case_41;
			case 42:
			goto st_case_42;
			case 43:
			goto st_case_43;
			case 44:
			goto st_case_44;
			case 45:
			goto st_case_45;
		}
		goto st_out;
		st_case_1:
		switch( ( (*( p))) ) {
			case 36: {
				goto ctr0;
			}
			case 95: {
				goto ctr0;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto ctr0;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto ctr0;
			}
		} else {
			goto ctr0;
		}
		{
			goto st0;
		}
		st_case_0:
		st0:
		cs = 0;
		goto _out;
		ctr0:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st2;
		st2:
		p+= 1;
		if ( p == pe )
		goto _test_eof2;
		st_case_2:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st27;
			}
			case 95: {
				goto st27;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st27;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st27;
			}
		} else {
			goto st27;
		}
		{
			goto st0;
		}
		ctr2:
		{
			#line 48 "ext/puma_http11/http11_parser.rl"
			
			parser->request_method(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st3;
		st3:
		p+= 1;
		if ( p == pe )
		goto _test_eof3;
		st_case_3:
		switch( ( (*( p))) ) {
			case 42: {
				goto ctr4;
			}
			case 43: {
				goto ctr5;
			}
			case 47: {
				goto ctr6;
			}
			case 58: {
				goto ctr7;
			}
		}
		if ( ( (*( p))) < 65 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto ctr5;
			}
		} else if ( ( (*( p))) > 90 ) {
			if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
				goto ctr5;
			}
		} else {
			goto ctr5;
		}
		{
			goto st0;
		}
		ctr4:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st4;
		st4:
		p+= 1;
		if ( p == pe )
		goto _test_eof4;
		st_case_4:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr8;
			}
			case 35: {
				goto ctr9;
			}
		}
		{
			goto st0;
		}
		ctr8:
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		ctr31:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		{
			#line 54 "ext/puma_http11/http11_parser.rl"
			
			parser->fragment(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		ctr33:
		{
			#line 54 "ext/puma_http11/http11_parser.rl"
			
			parser->fragment(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		ctr37:
		{
			#line 67 "ext/puma_http11/http11_parser.rl"
			
			parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		ctr41:
		{
			#line 58 "ext/puma_http11/http11_parser.rl"
			MARK(query_start, p); }
		{
			#line 59 "ext/puma_http11/http11_parser.rl"
			
			parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		ctr44:
		{
			#line 59 "ext/puma_http11/http11_parser.rl"
			
			parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st5;
		st5:
		p+= 1;
		if ( p == pe )
		goto _test_eof5;
		st_case_5:
		if ( ( (*( p))) == 72 ) {
			goto ctr10;
		}
		{
			goto st0;
		}
		ctr10:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st6;
		st6:
		p+= 1;
		if ( p == pe )
		goto _test_eof6;
		st_case_6:
		if ( ( (*( p))) == 84 ) {
			goto st7;
		}
		{
			goto st0;
		}
		st7:
		p+= 1;
		if ( p == pe )
		goto _test_eof7;
		st_case_7:
		if ( ( (*( p))) == 84 ) {
			goto st8;
		}
		{
			goto st0;
		}
		st8:
		p+= 1;
		if ( p == pe )
		goto _test_eof8;
		st_case_8:
		if ( ( (*( p))) == 80 ) {
			goto st9;
		}
		{
			goto st0;
		}
		st9:
		p+= 1;
		if ( p == pe )
		goto _test_eof9;
		st_case_9:
		if ( ( (*( p))) == 47 ) {
			goto st10;
		}
		{
			goto st0;
		}
		st10:
		p+= 1;
		if ( p == pe )
		goto _test_eof10;
		st_case_10:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto st11;
		}
		{
			goto st0;
		}
		st11:
		p+= 1;
		if ( p == pe )
		goto _test_eof11;
		st_case_11:
		if ( ( (*( p))) == 46 ) {
			goto st12;
		}
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto st11;
		}
		{
			goto st0;
		}
		st12:
		p+= 1;
		if ( p == pe )
		goto _test_eof12;
		st_case_12:
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto st13;
		}
		{
			goto st0;
		}
		st13:
		p+= 1;
		if ( p == pe )
		goto _test_eof13;
		st_case_13:
		if ( ( (*( p))) == 13 ) {
			goto ctr18;
		}
		if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
			goto st13;
		}
		{
			goto st0;
		}
		ctr18:
		{
			#line 63 "ext/puma_http11/http11_parser.rl"
			
			parser->http_version(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st14;
		ctr26:
		{
			#line 44 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		{
			#line 45 "ext/puma_http11/http11_parser.rl"
			
			parser->http_field(parser, PTR_TO(field_start), parser->field_len, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st14;
		ctr29:
		{
			#line 45 "ext/puma_http11/http11_parser.rl"
			
			parser->http_field(parser, PTR_TO(field_start), parser->field_len, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st14;
		st14:
		p+= 1;
		if ( p == pe )
		goto _test_eof14;
		st_case_14:
		if ( ( (*( p))) == 10 ) {
			goto st15;
		}
		{
			goto st0;
		}
		st15:
		p+= 1;
		if ( p == pe )
		goto _test_eof15;
		st_case_15:
		switch( ( (*( p))) ) {
			case 13: {
				goto st16;
			}
			case 33: {
				goto ctr21;
			}
			case 124: {
				goto ctr21;
			}
			case 126: {
				goto ctr21;
			}
		}
		if ( ( (*( p))) < 45 ) {
			if ( ( (*( p))) > 39 ) {
				if ( 42 <= ( (*( p))) && ( (*( p))) <= 43 ) {
					goto ctr21;
				}
			} else if ( ( (*( p))) >= 35 ) {
				goto ctr21;
			}
		} else if ( ( (*( p))) > 46 ) {
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto ctr21;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 94 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto ctr21;
				}
			} else {
				goto ctr21;
			}
		} else {
			goto ctr21;
		}
		{
			goto st0;
		}
		st16:
		p+= 1;
		if ( p == pe )
		goto _test_eof16;
		st_case_16:
		if ( ( (*( p))) == 10 ) {
			goto ctr22;
		}
		{
			goto st0;
		}
		ctr22:
		{
			#line 71 "ext/puma_http11/http11_parser.rl"
			
			parser->body_start = p - buffer + 1;
			parser->header_done(parser, p + 1, pe - p - 1);
			{p+= 1; cs = 46; goto _out;}
		}
		
		goto st46;
		st46:
		p+= 1;
		if ( p == pe )
		goto _test_eof46;
		st_case_46:
		{
			goto st0;
		}
		ctr21:
		{
			#line 38 "ext/puma_http11/http11_parser.rl"
			MARK(field_start, p); }
		{
			#line 39 "ext/puma_http11/http11_parser.rl"
			snake_upcase_char((char *)p); }
		
		goto st17;
		ctr23:
		{
			#line 39 "ext/puma_http11/http11_parser.rl"
			snake_upcase_char((char *)p); }
		
		goto st17;
		st17:
		p+= 1;
		if ( p == pe )
		goto _test_eof17;
		st_case_17:
		switch( ( (*( p))) ) {
			case 33: {
				goto ctr23;
			}
			case 58: {
				goto ctr24;
			}
			case 124: {
				goto ctr23;
			}
			case 126: {
				goto ctr23;
			}
		}
		if ( ( (*( p))) < 45 ) {
			if ( ( (*( p))) > 39 ) {
				if ( 42 <= ( (*( p))) && ( (*( p))) <= 43 ) {
					goto ctr23;
				}
			} else if ( ( (*( p))) >= 35 ) {
				goto ctr23;
			}
		} else if ( ( (*( p))) > 46 ) {
			if ( ( (*( p))) < 65 ) {
				if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
					goto ctr23;
				}
			} else if ( ( (*( p))) > 90 ) {
				if ( 94 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto ctr23;
				}
			} else {
				goto ctr23;
			}
		} else {
			goto ctr23;
		}
		{
			goto st0;
		}
		ctr24:
		{
			#line 40 "ext/puma_http11/http11_parser.rl"
			
			parser->field_len = LEN(field_start, p);
		}
		
		goto st18;
		ctr27:
		{
			#line 44 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st18;
		st18:
		p+= 1;
		if ( p == pe )
		goto _test_eof18;
		st_case_18:
		switch( ( (*( p))) ) {
			case 13: {
				goto ctr26;
			}
			case 32: {
				goto ctr27;
			}
		}
		{
			goto ctr25;
		}
		ctr25:
		{
			#line 44 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st19;
		st19:
		p+= 1;
		if ( p == pe )
		goto _test_eof19;
		st_case_19:
		if ( ( (*( p))) == 13 ) {
			goto ctr29;
		}
		{
			goto st19;
		}
		ctr9:
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st20;
		ctr38:
		{
			#line 67 "ext/puma_http11/http11_parser.rl"
			
			parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st20;
		ctr42:
		{
			#line 58 "ext/puma_http11/http11_parser.rl"
			MARK(query_start, p); }
		{
			#line 59 "ext/puma_http11/http11_parser.rl"
			
			parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st20;
		ctr45:
		{
			#line 59 "ext/puma_http11/http11_parser.rl"
			
			parser->query_string(parser, PTR_TO(query_start), LEN(query_start, p));
		}
		{
			#line 51 "ext/puma_http11/http11_parser.rl"
			
			parser->request_uri(parser, PTR_TO(mark), LEN(mark, p));
		}
		
		goto st20;
		st20:
		p+= 1;
		if ( p == pe )
		goto _test_eof20;
		st_case_20:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr31;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 127: {
				goto st0;
			}
		}
		if ( ( (*( p))) > 31 ) {
			if ( 34 <= ( (*( p))) && ( (*( p))) <= 35 ) {
				goto st0;
			}
		} else if ( ( (*( p))) >= 0 ) {
			goto st0;
		}
		{
			goto ctr30;
		}
		ctr30:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st21;
		st21:
		p+= 1;
		if ( p == pe )
		goto _test_eof21;
		st_case_21:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr33;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 127: {
				goto st0;
			}
		}
		if ( ( (*( p))) > 31 ) {
			if ( 34 <= ( (*( p))) && ( (*( p))) <= 35 ) {
				goto st0;
			}
		} else if ( ( (*( p))) >= 0 ) {
			goto st0;
		}
		{
			goto st21;
		}
		ctr5:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st22;
		st22:
		p+= 1;
		if ( p == pe )
		goto _test_eof22;
		st_case_22:
		switch( ( (*( p))) ) {
			case 43: {
				goto st22;
			}
			case 58: {
				goto st23;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st22;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( ( (*( p))) > 90 ) {
				if ( 97 <= ( (*( p))) && ( (*( p))) <= 122 ) {
					goto st22;
				}
			} else if ( ( (*( p))) >= 65 ) {
				goto st22;
			}
		} else {
			goto st22;
		}
		{
			goto st0;
		}
		ctr7:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st23;
		st23:
		p+= 1;
		if ( p == pe )
		goto _test_eof23;
		st_case_23:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr8;
			}
			case 34: {
				goto st0;
			}
			case 35: {
				goto ctr9;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 127: {
				goto st0;
			}
		}
		if ( 0 <= ( (*( p))) && ( (*( p))) <= 31 ) {
			goto st0;
		}
		{
			goto st23;
		}
		ctr6:
		{
			#line 35 "ext/puma_http11/http11_parser.rl"
			MARK(mark, p); }
		
		goto st24;
		st24:
		p+= 1;
		if ( p == pe )
		goto _test_eof24;
		st_case_24:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr37;
			}
			case 34: {
				goto st0;
			}
			case 35: {
				goto ctr38;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 63: {
				goto ctr39;
			}
			case 127: {
				goto st0;
			}
		}
		if ( 0 <= ( (*( p))) && ( (*( p))) <= 31 ) {
			goto st0;
		}
		{
			goto st24;
		}
		ctr39:
		{
			#line 67 "ext/puma_http11/http11_parser.rl"
			
			parser->request_path(parser, PTR_TO(mark), LEN(mark,p));
		}
		
		goto st25;
		st25:
		p+= 1;
		if ( p == pe )
		goto _test_eof25;
		st_case_25:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr41;
			}
			case 34: {
				goto st0;
			}
			case 35: {
				goto ctr42;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 127: {
				goto st0;
			}
		}
		if ( 0 <= ( (*( p))) && ( (*( p))) <= 31 ) {
			goto st0;
		}
		{
			goto ctr40;
		}
		ctr40:
		{
			#line 58 "ext/puma_http11/http11_parser.rl"
			MARK(query_start, p); }
		
		goto st26;
		st26:
		p+= 1;
		if ( p == pe )
		goto _test_eof26;
		st_case_26:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr44;
			}
			case 34: {
				goto st0;
			}
			case 35: {
				goto ctr45;
			}
			case 60: {
				goto st0;
			}
			case 62: {
				goto st0;
			}
			case 127: {
				goto st0;
			}
		}
		if ( 0 <= ( (*( p))) && ( (*( p))) <= 31 ) {
			goto st0;
		}
		{
			goto st26;
		}
		st27:
		p+= 1;
		if ( p == pe )
		goto _test_eof27;
		st_case_27:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st28;
			}
			case 95: {
				goto st28;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st28;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st28;
			}
		} else {
			goto st28;
		}
		{
			goto st0;
		}
		st28:
		p+= 1;
		if ( p == pe )
		goto _test_eof28;
		st_case_28:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st29;
			}
			case 95: {
				goto st29;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st29;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st29;
			}
		} else {
			goto st29;
		}
		{
			goto st0;
		}
		st29:
		p+= 1;
		if ( p == pe )
		goto _test_eof29;
		st_case_29:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st30;
			}
			case 95: {
				goto st30;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st30;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st30;
			}
		} else {
			goto st30;
		}
		{
			goto st0;
		}
		st30:
		p+= 1;
		if ( p == pe )
		goto _test_eof30;
		st_case_30:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st31;
			}
			case 95: {
				goto st31;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st31;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st31;
			}
		} else {
			goto st31;
		}
		{
			goto st0;
		}
		st31:
		p+= 1;
		if ( p == pe )
		goto _test_eof31;
		st_case_31:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st32;
			}
			case 95: {
				goto st32;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st32;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st32;
			}
		} else {
			goto st32;
		}
		{
			goto st0;
		}
		st32:
		p+= 1;
		if ( p == pe )
		goto _test_eof32;
		st_case_32:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st33;
			}
			case 95: {
				goto st33;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st33;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st33;
			}
		} else {
			goto st33;
		}
		{
			goto st0;
		}
		st33:
		p+= 1;
		if ( p == pe )
		goto _test_eof33;
		st_case_33:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st34;
			}
			case 95: {
				goto st34;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st34;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st34;
			}
		} else {
			goto st34;
		}
		{
			goto st0;
		}
		st34:
		p+= 1;
		if ( p == pe )
		goto _test_eof34;
		st_case_34:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st35;
			}
			case 95: {
				goto st35;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st35;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st35;
			}
		} else {
			goto st35;
		}
		{
			goto st0;
		}
		st35:
		p+= 1;
		if ( p == pe )
		goto _test_eof35;
		st_case_35:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st36;
			}
			case 95: {
				goto st36;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st36;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st36;
			}
		} else {
			goto st36;
		}
		{
			goto st0;
		}
		st36:
		p+= 1;
		if ( p == pe )
		goto _test_eof36;
		st_case_36:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st37;
			}
			case 95: {
				goto st37;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st37;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st37;
			}
		} else {
			goto st37;
		}
		{
			goto st0;
		}
		st37:
		p+= 1;
		if ( p == pe )
		goto _test_eof37;
		st_case_37:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st38;
			}
			case 95: {
				goto st38;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st38;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st38;
			}
		} else {
			goto st38;
		}
		{
			goto st0;
		}
		st38:
		p+= 1;
		if ( p == pe )
		goto _test_eof38;
		st_case_38:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st39;
			}
			case 95: {
				goto st39;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st39;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st39;
			}
		} else {
			goto st39;
		}
		{
			goto st0;
		}
		st39:
		p+= 1;
		if ( p == pe )
		goto _test_eof39;
		st_case_39:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st40;
			}
			case 95: {
				goto st40;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st40;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st40;
			}
		} else {
			goto st40;
		}
		{
			goto st0;
		}
		st40:
		p+= 1;
		if ( p == pe )
		goto _test_eof40;
		st_case_40:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st41;
			}
			case 95: {
				goto st41;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st41;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st41;
			}
		} else {
			goto st41;
		}
		{
			goto st0;
		}
		st41:
		p+= 1;
		if ( p == pe )
		goto _test_eof41;
		st_case_41:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st42;
			}
			case 95: {
				goto st42;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st42;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st42;
			}
		} else {
			goto st42;
		}
		{
			goto st0;
		}
		st42:
		p+= 1;
		if ( p == pe )
		goto _test_eof42;
		st_case_42:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st43;
			}
			case 95: {
				goto st43;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st43;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st43;
			}
		} else {
			goto st43;
		}
		{
			goto st0;
		}
		st43:
		p+= 1;
		if ( p == pe )
		goto _test_eof43;
		st_case_43:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st44;
			}
			case 95: {
				goto st44;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st44;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st44;
			}
		} else {
			goto st44;
		}
		{
			goto st0;
		}
		st44:
		p+= 1;
		if ( p == pe )
		goto _test_eof44;
		st_case_44:
		switch( ( (*( p))) ) {
			case 32: {
				goto ctr2;
			}
			case 36: {
				goto st45;
			}
			case 95: {
				goto st45;
			}
		}
		if ( ( (*( p))) < 48 ) {
			if ( 45 <= ( (*( p))) && ( (*( p))) <= 46 ) {
				goto st45;
			}
		} else if ( ( (*( p))) > 57 ) {
			if ( 65 <= ( (*( p))) && ( (*( p))) <= 90 ) {
				goto st45;
			}
		} else {
			goto st45;
		}
		{
			goto st0;
		}
		st45:
		p+= 1;
		if ( p == pe )
		goto _test_eof45;
		st_case_45:
		if ( ( (*( p))) == 32 ) {
			goto ctr2;
		}
		{
			goto st0;
		}
		st_out:
		_test_eof2: cs = 2; goto _test_eof; 
		_test_eof3: cs = 3; goto _test_eof; 
		_test_eof4: cs = 4; goto _test_eof; 
		_test_eof5: cs = 5; goto _test_eof; 
		_test_eof6: cs = 6; goto _test_eof; 
		_test_eof7: cs = 7; goto _test_eof; 
		_test_eof8: cs = 8; goto _test_eof; 
		_test_eof9: cs = 9; goto _test_eof; 
		_test_eof10: cs = 10; goto _test_eof; 
		_test_eof11: cs = 11; goto _test_eof; 
		_test_eof12: cs = 12; goto _test_eof; 
		_test_eof13: cs = 13; goto _test_eof; 
		_test_eof14: cs = 14; goto _test_eof; 
		_test_eof15: cs = 15; goto _test_eof; 
		_test_eof16: cs = 16; goto _test_eof; 
		_test_eof46: cs = 46; goto _test_eof; 
		_test_eof17: cs = 17; goto _test_eof; 
		_test_eof18: cs = 18; goto _test_eof; 
		_test_eof19: cs = 19; goto _test_eof; 
		_test_eof20: cs = 20; goto _test_eof; 
		_test_eof21: cs = 21; goto _test_eof; 
		_test_eof22: cs = 22; goto _test_eof; 
		_test_eof23: cs = 23; goto _test_eof; 
		_test_eof24: cs = 24; goto _test_eof; 
		_test_eof25: cs = 25; goto _test_eof; 
		_test_eof26: cs = 26; goto _test_eof; 
		_test_eof27: cs = 27; goto _test_eof; 
		_test_eof28: cs = 28; goto _test_eof; 
		_test_eof29: cs = 29; goto _test_eof; 
		_test_eof30: cs = 30; goto _test_eof; 
		_test_eof31: cs = 31; goto _test_eof; 
		_test_eof32: cs = 32; goto _test_eof; 
		_test_eof33: cs = 33; goto _test_eof; 
		_test_eof34: cs = 34; goto _test_eof; 
		_test_eof35: cs = 35; goto _test_eof; 
		_test_eof36: cs = 36; goto _test_eof; 
		_test_eof37: cs = 37; goto _test_eof; 
		_test_eof38: cs = 38; goto _test_eof; 
		_test_eof39: cs = 39; goto _test_eof; 
		_test_eof40: cs = 40; goto _test_eof; 
		_test_eof41: cs = 41; goto _test_eof; 
		_test_eof42: cs = 42; goto _test_eof; 
		_test_eof43: cs = 43; goto _test_eof; 
		_test_eof44: cs = 44; goto _test_eof; 
		_test_eof45: cs = 45; goto _test_eof; 
		
		_test_eof: {}
		_out: {}
	}
	
	
	if (!puma_parser_has_error(parser))
	parser->cs = cs;
	parser->nread += p - (buffer + off);
	
	assert(p <= pe && "buffer overflow after parsing execute");
	assert(parser->nread <= len && "nread longer than length");
	assert(parser->body_start <= len && "body starts after buffer end");
	assert(parser->mark < len && "mark is after buffer end");
	assert(parser->field_len <= len && "field has length longer than whole buffer");
	assert(parser->field_start < len && "field starts after buffer end");
	
	return(parser->nread);
}

int puma_parser_finish(puma_parser *parser)
{
	if (puma_parser_has_error(parser) ) {
		return -1;
	} else if (puma_parser_is_finished(parser) ) {
		return 1;
	} else {
		return 0;
	}
}

int puma_parser_has_error(puma_parser *parser) {
	return parser->cs == puma_parser_error;
}

int puma_parser_is_finished(puma_parser *parser) {
	return parser->cs >= puma_parser_first_final;
}
