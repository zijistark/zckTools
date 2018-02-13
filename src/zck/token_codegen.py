#!/usr/bin/python3

import sys
from pathlib import Path

list_scope_path = Path("./list_scope_tokens.txt")
keyword_bit = 13
list_scope_bit = 14

def main():
	if len(sys.argv) < 2:
		print("Error: Must specify an argument of either 'tokens' or 'emitters'!", file=sys.stderr)
		return 1

	list_scopes = set()

	with list_scope_path.open('r') as f:
		for line in f:
			line = line.strip()
			if line.startswith('#') or len(line) == 0:
				continue
			list_scopes.add(line)

	max_kw_len = max( len(kw) for kw in list_scopes )

	if sys.argv[1] == 'tokens':
		t_id = (1 << (keyword_bit - 1)) | (1 << (list_scope_bit-1))

		for t in sorted(list_scopes):
			print('  {:<{width}} = 0x{:4X};'.format(t.upper(), t_id, width=max_kw_len))
			t_id += 1

	elif sys.argv[1] == 'emitters':
		for t in sorted(list_scopes):
			print('  {:<{width}} => T_{}(Lexeme);'.format('"' + t + '"', t.upper(), width = max_kw_len + 2))
	else:
		print("Error: Must specify an argument of either 'tokens' or 'emitters'!", file=sys.stderr)
		return 1

	return 0


if __name__ == '__main__':
    sys.exit(main())
