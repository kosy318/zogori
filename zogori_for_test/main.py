import ply.lex as lex
import tokrules
import re
import sys

# make python exe file
# on powerShell : pip install pyinstaller
# on powerShell : pyinstaller -F main.py tokrules.py

# Build the lexer
lexer = lex.lex(module=tokrules)  # , debug=1)
lexer.nested = []

# Test it out
data = ''
LOC = 0
with open("iron.cpp", 'r') as file:
    comment_start = False
    comment_end = False
    for line in file.readlines():
        enter = re.fullmatch("[ \t\n]+", line)
        one_line_comment = re.match("^[ \t]*//.*", line)
        if not comment_start:
            comment_start = re.match("^[ \t]*/(\*).*", line)
        comment_end = re.match("^[ \t]*(\*)/.*", line)
        if not comment_end and comment_start:
            continue
        elif comment_end and comment_start:
            comment_end = False
            comment_start = False
            continue

        if not enter and not one_line_comment:
            data += line
            LOC += 1


print(data)

# read_file = sys.argv[1]
# with open(read_file, 'r') as file:
#     comment_start = False
#     comment_end = False
#     for line in file.readlines():
#         enter = re.fullmatch("[ \t\n]+", line)
#         one_line_comment = re.match("^[ \t]*//.*", line)
#         if not comment_start:
#             comment_start = re.match("^[ \t]*/(\*).*", line)
#         comment_end = re.match("^[ \t]*(\*)/.*", line)
#         if not comment_end and comment_start:
#             continue
#         elif comment_end and comment_start:
#             comment_end = False
#             comment_start = False
#             continue
#
#         if not enter and not one_line_comment:
#             data += line
#             LOC += 1


# Give the lexer some input
lexer.input(data)

decision_func = ['IF', 'ELSE_IF', 'ELSE', 'WHILE', 'SWITCH', 'FOR']

result = {'CCM': [], 'DOT_OP': [], }
# Tokenize
while True:
    tok = lexer.token()
    if not tok:
        break  # No more input

    # print(tok.type, "\t\t", tok.value, "  \t", tok.lineno)#,tok.lexpos)
    if tok.type not in result:
        result[tok.type] = [tok.value]
    else:
        result[tok.type].append(tok.value)

    if tok.type in decision_func:
        result['CCM'].append(tok.value)

    if tok.type == 'FUNCTION' and tok.value[0] == '.':
        result['DOT_OP'].append('.')


for keys in result.keys():
    print(f'{keys: <15}{len(result[keys]): <5}<br>')
    for val in result[keys]:
        print(f'{" " * 10}>>   {val}<br>')

LOC -= (len(result['INCLUDE']) + len(result['NAMESPACE']))
CCM = len(result['CCM']) + 1

# inside_n1 = ['FUNCTION', 'OPERATION', 'INT', 'STRING', 'VECTOR', 'SEMICOLON']
n_1 = 1 + len(set(result['FUNCTION']))*2 + len(set(result['OPERATION']))
print(f'nested {lexer.nested}')
print(f'LOC : {LOC}<br>')
print(f'CCM : {CCM}<br>')
