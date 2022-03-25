import ply.lex as lex
import pytokrules
import re
import sys
import math

# make python exe file
# on powerShell : pip install pyinstaller
# on powerShell : pyinstaller -F main.py tokrules.py

# Build the lexer
lexer = lex.lex(module=pytokrules) #, debug=1)

# Test it out
data = ''
LOC = 0
read_file = sys.argv[1]
with open(read_file, 'r') as file:
    comment_start = False
    comment_end = False
    for line in file.readlines():
        enter = re.fullmatch("[ \t\n]+", line)
        one_line_comment = re.match("^[ \t]*#.*", line)
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


conditional = ['IF', 'ELIF', 'WHITE']
brackets = ['BRACKET','BRACE','LPAREN','RPAREN']
variables =['STRING', 'ID', 'NUMBER']
operatorType = []
operandType = []

CCM = 1
comments = 0
operand = 0
operator = 0
# Tokenize
while True:
    tok = lexer.token()
    print(tok)
    if not tok:
        break  # No more input
    if tok.type in conditional:
        CCM += 1
        if tok.value not in operatorType:
            operatorType.append(tok.value)
    elif tok.type in variables:
        operand+=1
        if tok.value not in operandType:
            operandType.append(tok.value)
    elif tok.type == "MULTISTRING":
         LOC = LOC -tok.value.count('\n') + 1
         operand+=1
         if tok.value not in operandType:
            operandType.append(tok.value)
    elif tok.type == "COMMENT":
        LOC -= 1
    elif tok.type == 'FUNCTION':
        operator+=1.5
        if tok.value not in operatorType:
                operatorType.append(tok.value)

    elif tok.type in brackets:
        operator+=0.5
        if tok.value not in operatorType:
            operatorType.append(tok.value)

    else:
        operator += 1
        if tok.value not in operatorType:
                operatorType.append(tok.value)

n_1,n_2 = operator, operand
N_1, N_2 = len(operatorType), len(operandType)

vocabulary = n_1 + n_2
length = N_1 + N_2
estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
volume = length * math.log2(vocabulary)
difficulty = (n_1 / 2) * (N_2 / n_2)
effort = difficulty * volume

print(f'''{'Program vocabulary':<25}: {vocabulary}<br>
{'Program length':<25}: {length}<br>
{'Estimated program length':<25}: {estimated_length}<br>
{'Volume':<25}: {volume}<br>
{'Difficulty':<25}: {difficulty}<br>
{'Effort':<25}: {effort}<br><br>''')
print(f'CCM : {CCM}<br>')
print(f'LOC : {LOC}<br>')