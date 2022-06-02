import math
import ply.lex as lex
import cpp_tokrules
import re
import numpy as np
import sys
from collections import deque
import chardet


def cal_complexity(file_name):
    # Build the lexer
    lexer = lex.lex(module=cpp_tokrules)  # , debug=1)

    data = ''
    LOC = 0

    rawdata = open(file_name, 'rb').read()
    result = chardet.detect(rawdata)
    enc = result['encoding']
    with open(file_name, 'r', encoding=enc) as file:
        # get LOC
        comment_start = False
        for line in file.readlines():
            enter = re.fullmatch("[ \t\n]+", line)
            one_line_comment = re.match("^[ \t]*//.*", line)
            if not comment_start:
                comment_start = re.match("^[ \t]*/(\*).*", line)
            comment_end = re.match("(.|\n)*?(\*)/.*", line)
            if not comment_end and comment_start:
                continue
            elif comment_end and comment_start:
                comment_start = False
                continue

            if not enter and not one_line_comment:
                data += line
                LOC += 1

    # Give the lexer input
    lexer.input(data)

    decision_func = ['IF', 'ELSE_IF', 'WHILE', 'SWITCH', 'FOR']

    result = {'CCM': [], 'INCLUDE': [], 'NAMESPACE': [], 'DOT_OP': [], 'ID': [], 'TYPE': [], 'FUNCTION': [], }
    # Tokenize
    while True:
        tok = lexer.token()
        if not tok:
            break  # No more input

        # result의 해당 token type에 token value 입력
        if tok.type not in result:
            result[tok.type] = [tok.value]
        else:
            result[tok.type].append(tok.value)

        # 변수 선언
        if tok.type == 'VARIABLE':
            var = result['VARIABLE'][-1]

            if var.split()[0] != 'return' and var.split()[0] != 'goto':
                result['TYPE'].append(' '.join(var.split()[:-1]))

            if var.split()[-1] == 'struct':
                result['TYPE'][-1] = var.split()[-1]
            elif var.split()[-1] != 'main':
                if var.split()[-1].split("<<")[0] == "cout":
                    result['FUNCTION'].append("cout")
                elif var.split()[-1].split(">>")[0] == "cin":
                    result['FUNCTION'].append("cin")
                else:
                    result['ID'].append(var.split()[-1])

        # ignore continue, break, return
        if tok.type == 'ID' and (tok.value in ['continue', 'break', 'return']):
            result['ID'].pop()
            pass

        if tok.type in decision_func:
            result['CCM'].append(tok.value)

        if tok.type == 'FUNCTION' and tok.value[0] == '.':
            result['DOT_OP'].append('.')

        if tok.type == 'FUNCTION_DECLARATION' and tok.value.split()[0] != 'template':
            print(tok.value)
            try:
                result['FUNCTION'].append(tok.value.split()[1][:-1])
            except:
                pass

    LOC -= (len(result['INCLUDE']) + len(result['NAMESPACE']))

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

    # HCM
    vocabulary = n_1 + n_2
    length = N_1 + N_2
    estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
    volume = length * math.log2(vocabulary)
    difficulty = (n_1 / 2) * (N_2 / n_2)
    effort = difficulty * volume

    def cal_elegance(res):
        if res['number_var'] == 0:
            res['number_var'] = 1
        if res['number_func'] == 0:
            res['number_func'] = 1
        eleg = res['number_var'] + len(res['distinct_var']) + len(res['distinct_var']) / res['number_var']
        eleg += res['number_func'] + len(res['distinct_func']) + len(res['distinct_func']) / res['number_func']
        eleg += res['LOC']
        eleg = 100 * pow(eleg / 100, np.log(res['depth']))

        return eleg

    complexity = {
        "distinct_func": set(result['FUNCTION']),
        "distinct_var": set(result['ID']),
        "number_func": len(result['FUNCTION']),
        "number_var": len(result['ID']),
        "depth": depth,
        "LOC": LOC,
        "elegance": 0,

        "CCM": len(result['CCM']),
        "length": length,
        "estimated_length": estimated_length,
        "volume": volume,
        "difficulty": difficulty,
        "effort": effort,
    }

    complexity['elegance'] = cal_elegance(complexity)

    return complexity
