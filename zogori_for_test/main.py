import ply.lex as lex
import tokrules
import sys

# make python exe file
# on powerShell : pip install pyinstaller
# on powerShell : pyinstaller -F main.py tokrules.py

# Build the lexer
lexer = lex.lex(module=tokrules)  # , debug=1)
lexer.nested = []


def tokenizing(res, tok):
    if not tok:
        return False

    # print(tok.type, "\t\t", tok.value, "  \t", tok.lineno)#,tok.lexpos)
    if tok.type not in res:
        res[tok.type] = [tok.value]
    else:
        res[tok.type].append(tok.value)

    if tok.type in decision_func:
        res['CCM'].append(tok.value)
    elif tok.type == 'CCODE':
        inside = lex.lex(module=tokrules)  # , debug=1)
        inside.nested = []
        print(tok.value)
        inside.input(tok.value)
        tokenizing(res, inside.token())


# Test it out
data = ''
with open("iron.cpp", 'r') as file:
    for line in file.readlines():
        data += line

# read_file = sys.argv[1]
# with open(read_file, 'r') as file:
#     for line in file.readlines():
#         data += line


# Give the lexer some input
lexer.input(data)

decision_func = ['IF', 'ELSE_IF', 'ELSE', 'WHILE', 'SWITCH', 'FOR']

result = {'CCM': [], 'CCODE': []}

# Tokenize
while True:
    tok = lexer.token()
    if not tok:
        break  # No more input
    #
    # # print(tok.type, "\t\t", tok.value, "  \t", tok.lineno)#,tok.lexpos)
    # if tok.type not in result:
    #     result[tok.type] = [tok.value]
    # else:
    #     result[tok.type].append(tok.value)
    #
    # if tok.type in decision_func:
    #     result['CCM'].append(tok.value)
    tokenizing(result, tok)


for keys in result.keys():
    print(f'{keys: <15}{len(result[keys]): <5}<br>')
    for val in result[keys]:
        print(f'{" " * 10}>>   {val}<br>')

LOC = data.count('\n')
CCM = len(result['CCM']) + 1

#   대괄호{}     함수, 괄호()
# n_1 = 1 + len(set(result['FUNCTION']))*2 +
print(f'nested {lexer.nested}')
print(f'LOC : {LOC}<br>')
print(f'CCM : {CCM}<br>')
