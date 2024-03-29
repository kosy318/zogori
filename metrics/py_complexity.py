import ply.lex as lex
import py_tokrules
import re
import sys
import math
from collections import deque
import chardet


def cal_complexity(read_file):
    lexer = lex.lex(module=py_tokrules) #, debug=1)

    data = ''
    LOC = 0
    rawdata = open(read_file, 'rb').read()
    
    # read encoding of data with chardet module
    result = chardet.detect(rawdata)
    enc = result['encoding']

    with open(read_file, 'r', encoding=enc) as file:
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

    conditional = ['IF', 'ELIF', 'WHILE']
    forelse = ['FOR','ELSE']
    brackets = ['BRACKET','BRACE','LPAREN','RPAREN']
    operands =['STRING', 'ID', 'NUMBER']

    operatorType = []
    operandType = []
    indentionValue = []
    functionValue = []
    variableValue = []

    CCM = 1
    comments = 0
    operand = 0
    operator = 0
    functionNumber = 0
    variable = 0

    prevLineno = 0
    nowLineno = 0
    depth = 0
    maxdepth = 0
    prevIndention = 0
    indentQueue = deque()


    # tokenize and count features
    while True:
        tok = lexer.token()
        if not tok:
            break 
        nowLineno = tok.lineno
        if tok.type != 'INDENTION' and prevLineno < nowLineno and prevIndention > 0:
            nowIndention = 0
            for i in range(int(prevIndention - nowIndention)):
                indentQueue.append(")")
                depth -= 1
            prevIndention = 0

        if tok.type == 'INDENTION':
            nowIndention = len(tok.value)/4
            if nowIndention > prevIndention:
                indentQueue.append("(")
                depth += 1
            elif nowIndention < prevIndention:
                for i in range(int(prevIndention - nowIndention)):
                    indentQueue.append(")")
                    depth -= 1
            if depth > maxdepth:
                maxdepth = depth
            prevIndention = nowIndention
            indentionValue.append(tok.value)

        elif tok.type in conditional:
            CCM += 1
            indentQueue.append(tok.type)
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        elif tok.type in forelse:
            indentQueue.append(tok.type)
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        elif tok.type in operands:
            if tok.type == 'ID':
                variable += 1
                if tok.value not in variableValue:
                    variableValue.append(tok.value)
            operand+=1
            if tok.value not in operandType:
                operandType.append(tok.value)
        
        elif tok.type == "MULTISTRING":
            LOC = LOC - tok.value.count('\n') + 1
            operand+=1
            if tok.value not in operandType:
                operandType.append(tok.value)

        elif tok.type == "COMMENT":
            LOC -= 1

        elif tok.type == 'FUNCTION':
            operator+=1.5
            functionNumber += 1
            funcName = str(tok.value).rstrip("(")
            if funcName not in operatorType:
                operatorType.append(funcName)
                if funcName not in functionValue:
                    functionValue.append(funcName)

        elif tok.type in brackets:
            operator+=0.5
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        else:
            operator += 1
            if tok.value not in operatorType:
                    operatorType.append(tok.value)


        prevLineno = tok.lineno

    #draw tree string using Queue
    treeString = ""
    for i in range(len(indentQueue)):
        treeString += indentQueue.popleft()
    for i in range(depth):
        treeString+= ")"

    V = len(variableValue)
    Vd = variable
    F = len(functionValue)
    Fd = functionNumber
    D = maxdepth

    ele_score = 100*(((V + Vd + Vd/V + F + Fd + Fd/F)/100)**math.log(D))

    n_1,n_2 = operator, operand
    N_1, N_2 = len(operatorType), len(operandType)
    vocabulary = n_1 + n_2
    length = N_1 + N_2
    estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
    volume = length * math.log2(vocabulary)
    difficulty = (n_1 / 2) * (N_2 / n_2)
    effort = difficulty * volume

    #return key-value(dictionary) object to make json easily
    complexity = {
        "file_name":('__'.join(read_file.split('/')[-1].split('__')[1:])),
        "language":"py",
        "distinct_func": functionValue,
        "distinct_var": variableValue,
        "number_func": functionNumber,
        "number_var": variable,
        "depth": maxdepth,
        "LOC": LOC,
        "ele_score": ele_score,
    }

    return complexity

