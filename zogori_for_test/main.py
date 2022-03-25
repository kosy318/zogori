import math
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
# with open("iron.cpp", 'r') as file:
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

data = ''
LOC = 0
read_file = sys.argv[1]
with open(read_file, 'r') as file:
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

    if tok.type == 'VARIABLE':
        result['VARIABLE'][-1] = result['VARIABLE'][-1].split()[0]

    if tok.type in decision_func:
        result['CCM'].append(tok.value)

    if tok.type == 'FUNCTION' and tok.value[0] == '.':
        result['DOT_OP'].append('.')


# for keys in result.keys():
#     print(f'{keys: <15}{len(result[keys]): <5}<br>')
#     for val in result[keys]:
#         print(f'{" " * 10}>>   {val}<br>')

LOC -= (len(result['INCLUDE']) + len(result['NAMESPACE']))
CCM = len(result['CCM']) + 1

n_1 = 0
N_1 = 0
inside_n1 = ['BRACE', 'RPAREN', 'LINDEX', 'RINDEX', 'FUNCTION', 'OPERATION', 'VARIABLE', 'SEMICOLON', 'COMMA', 'DOT_OP']
for ele in inside_n1:
    if ele in result.keys():
        # print(list(set(result[ele])))
        n_1 += len(set(result[ele]))
        N_1 += len(result[ele])
n_2 = 0
N_2 = 0
inside_n2 = ['ID', 'STRING_VALUE', 'CHAR_VALUE', 'NUMBER']
for ele in inside_n2:
    if ele in result.keys():
        # print(list(set(result[ele])))
        n_2 += len(set(result[ele]))
        N_2 += len(result[ele])

# print(f'nested {lexer.nested}')
print(f'n_1 = {n_1}, n_2 = {n_2}, N_1 = {N_1}, N_2 = {N_2}')

vocabulary = n_1 + n_2
length = N_1 + N_2
estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
volume = length * math.log2(vocabulary)
difficulty = (n_1 / 2) * (N_2 / n_2)
effort = difficulty * volume

print(f'''Program vocabulary: {vocabulary}
Program length: {length}
Calculated estimated program length: {estimated_length}
Volume: {volume}
Difficulty: {difficulty}
Effort: {effort}''')
print(f'LOC : {LOC}<br>')
print(f'CCM : {CCM}<br>')
