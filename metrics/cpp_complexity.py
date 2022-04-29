import math
import ply.lex as lex
import cpp_tokrules
import re
import sys
from collections import deque
from cpp_elegancy import cal_elegancy


# make python exe file
# on powerShell : pip install pyinstaller
# on powerShell : pyinstaller -F main.py tokrules.py

def cal_complexity(file_name):
    # Build the lexer
    lexer = lex.lex(module=cpp_tokrules)  # , debug=1)
    lexer.nested = []

    data = ''
    LOC = 0
    # Test it out
    with open(file_name, 'r') as file:
        comment_start = False
        comment_end = False
        for line in file.readlines():
            enter = re.fullmatch("[ \t\n]+", line)
            one_line_comment = re.match("^[ \t]*//.*", line)
            if not comment_start:
                comment_start = re.match("^[ \t]*/(\*).*", line)
            comment_end = re.match("(.|\n)*?(\*)/.*", line)
            if not comment_end and comment_start:
                continue
            elif comment_end and comment_start:
                comment_end = False
                comment_start = False
                continue

            if not enter and not one_line_comment:
                data += line
                LOC += 1

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

    decision_func = ['IF', 'ELSE_IF', 'WHILE', 'SWITCH', 'FOR']

    result = {'CCM': [], 'NAMESPACE': [], 'DOT_OP': [], 'ID': [], 'TYPE': [], 'FUNCTION': [], }
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
            # print(tok.value,': ')
            var = result['VARIABLE'][-1]

            if var.split()[0] != 'return' and var.split()[0] != 'goto':
                result['TYPE'].append(' '.join(var.split()[:-1]))
            # print(var.split()[:-1], var.split()[-1])

            if var.split()[-1] == 'struct':
                result['TYPE'][-1] = var.split()[-1]
            elif var.split()[-1] != 'main':
                result['ID'].append(var.split()[-1])

        if tok.type == 'ID' and (tok.value in ['continue', 'break', 'return']):
            result['ID'].pop()
            pass

        if tok.type in decision_func:
            result['CCM'].append(tok.value)

        if tok.type == 'FUNCTION' and tok.value[0] == '.':
            result['DOT_OP'].append('.')

        if tok.type == 'FUNCTION_DECLARATION' and tok.value.split()[0] != 'template':
            try:
                result['FUNCTION'].append(tok.value.split()[1][:-1])
            except:
                pass

    dq = deque()
    depth = 0
    cnt = 0
    for b in result['BRACE']:
        if b == '}':
            if len(dq) != 0:
                dq.pop()
            else:
                cnt += 1

            if depth < cnt:
                depth = cnt
            cnt -= 1
        elif b == '{':
            dq.append(b)
            cnt += 1
        else:
            print('<script>window.alert("DEPTH FINDING ERROR")</script>')

    # for keys in result.keys():
    #     print(f'{keys: <15}{len(result[keys]): <5}<br>')
    #     for val in result[keys]:
    #         print(f'{" " * 10}>>   {val}<br>')

    LOC -= (len(result['INCLUDE']) + len(result['NAMESPACE']))

    n_1 = 0
    N_1 = 0
    inside_n1 = ['IF', 'ELSE_IF', 'ELSE', 'WHILE', 'SWITCH', 'FOR', 'BRACE', 'RPAREN', 'LINDEX', 'RINDEX', 'FUNCTION',
                 'OPERATION', 'TYPE', 'SEMICOLON', 'COMMA', 'DOT_OP']
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

    # print(f'n_1 = {n_1}, n_2 = {n_2}, N_1 = {N_1}, N_2 = {N_2}<br>')
    # print(result['TYPE'])
    vocabulary = n_1 + n_2
    length = N_1 + N_2
    estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
    volume = length * math.log2(vocabulary)
    difficulty = (n_1 / 2) * (N_2 / n_2)
    effort = difficulty * volume
    
    complexity = {
        "distinct_func": set(result['FUNCTION']),
        "distinct_var": set(result['ID']),
        "number_func": len(result['FUNCTION']),
        "number_var": len(result['ID']),
        "depth": depth,
        "LOC": LOC,
        "elegancy": 0,
    }

    complexity['elegancy'] = cal_elegancy(complexity)

    # print(f'{result["BRACE"]}')
    # print(f'''<tr><td>Program vocabulary</td><td>{vocabulary}</td></tr>
    # <tr><td>Program length</td><td>{length}</td></tr>
    # <tr><td>Estimated program length</td><td>{estimated_length}</td></tr>
    # <tr><td>Volume</td><td>{volume}</td></tr>
    # <tr><td>Difficulty</td><td>{difficulty}</td></tr>
    # <tr><td>Effort</td><td>{effort}</td></tr>
    # <tr><td>Functions</td><td>{len(set(result['FUNCTION']))}: {set(result['FUNCTION'])}</td></tr>
    # <tr><td>total nb of Functions</td><td>{len(result['FUNCTION'])}</td></tr>
    # <tr><td>Variables</td><td>{len(set(result['ID']))}: {set(result['ID'])}</td></tr>
    # <tr><td>total nb of Variables</td><td>{len(result['ID'])}</td></tr>
    # <tr><td>Depth</td><td>{depth}</td></tr>
    # <tr><td>CCM</td><td>{CCM}</td></tr>
    # <tr><td>LOC</td><td>{LOC}</td></tr>''')

    return complexity
