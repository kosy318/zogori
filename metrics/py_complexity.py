import ply.lex as lex
import py_tokrules
import re
import sys
import math
from collections import deque

def cal_complexity(filename):
    # Build the lexer
    lexer = lex.lex(module=py_tokrules) #, debug=1)

    data = ''
    LOC = 0
    read_file = sys.argv[1]
    with open(read_file, 'r', encoding="UTF-8") as file:
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
    distinct_func = []
    distinct_var = []

    CCM = 1
    comments = 0
    operand = 0
    operator = 0
    number_func = 0
    number_var = 0


    prevLineno = 0
    nowLineno = 0
    depth = 0
    maxdepth = 0
    prevIndention = 0
    indentQueue = deque()


    # Tokenize
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

        #조건문 세기 CCM
        elif tok.type in conditional:
            CCM += 1
            indentQueue.append(tok.type)
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        elif tok.type in forelse:
            indentQueue.append(tok.type)
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        #operand ( STRING OR ID OR NUMBER )
        elif tok.type in operands:
            # 변수만 따로 카운팅 ( ID )
            if tok.type == 'ID':
                number_var += 1
                if tok.value not in distinct_var:
                    distinct_var.append(tok.value)
            operand+=1
            if tok.value not in operandType:
                operandType.append(tok.value)
        
        #multistring
        elif tok.type == "MULTISTRING":
            LOC = LOC - tok.value.count('\n') + 1
            operand+=1
            if tok.value not in operandType:
                operandType.append(tok.value)

        #COMMENT
        elif tok.type == "COMMENT":
            LOC -= 1

        #function operator 점수 1.5
        elif tok.type == 'FUNCTION':
            operator+=1.5
            number_func += 1
            # 왼쪽 소괄호 제거
            funcName = str(tok.value).rstrip("(")
            if funcName not in operatorType:
                operatorType.append(funcName)
                if funcName not in distinct_func:
                    distinct_func.append(funcName)



        #괄호 0.5(function + 닫는 괄호 => 2)
        elif tok.type in brackets:
            operator+=0.5
            if tok.value not in operatorType:
                operatorType.append(tok.value)

        #나머지 operator
        else:
            operator += 1
            if tok.value not in operatorType:
                    operatorType.append(tok.value)


        prevLineno = tok.lineno



    # indentQueue pop하면서 트리 string 형식으로 표현
    treeString = ""
    for i in range(len(indentQueue)):
        treeString += indentQueue.popleft()
    for i in range(depth):
        treeString+= ")"


    # print("number_var : ",number_var, " ", distinct_var)
    # print(distinct_func)
    # print(treeString)

    V = len(distinct_var)
    Vd = number_var
    F = len(distinct_func)
    Fd = number_func
    D = maxdepth
    elegance = 0



    # print("Program vocabulary : ", vocabulary)
    # print("Program length : ", length)
    # print("Estimated program length : ", estimated_length)
    # print("Difficulty : ", difficulty)
    # print("Effort : ", effort)
    # print("Functions : ", len(distinct_func), distinct_func)
    # print("total nb of Functions : ", volume)
    # print("Volume : ", number_func)
    # print("Variables : ", len(distinct_var),distinct_var)
    # print("nb of Variables : ", number_var)
    # print("Depth : ",maxdepth, treeString)
    # print("CCM : ", CCM)
    # print("LOC : ", LOC)


    n_1,n_2 = operator, operand
    N_1, N_2 = len(operatorType), len(operandType)
    vocabulary = n_1 + n_2
    length = N_1 + N_2
    estimated_length = n_1 * math.log2(n_1) + n_2 * math.log2(n_2)
    volume = length * math.log2(vocabulary)
    difficulty = (n_1 / 2) * (N_2 / n_2)
    effort = difficulty * volume


    #
    # print(f'''<tr><td>Program vocabulary</td><td>{vocabulary}</td></tr>
    # <tr><td>Program length</td><td>{length}</td></tr>
    # <tr><td>Estimated program length</td><td>{estimated_length}</td></tr>
    # <tr><td>Volume</td><td>{volume}</td></tr>
    # <tr><td>Difficulty</td><td>{difficulty}</td></tr>
    # <tr><td>Effort</td><td>{effort}</td></tr>
    # <tr><td>Functions</td><td>{len(distinct_func)}: {distinct_func}</td></tr>
    # <tr><td>total nb of Functions</td><td>{number_func}</td></tr>
    # <tr><td>Variables</td><td>{len(distinct_var)}: {distinct_var}</td></tr>
    # <tr><td>total nb of Variables</td><td>{number_var}</td></tr>
    # <tr><td>Depth</td><td>{maxdepth}: {treeString}</td></tr>
    # <tr><td>CCM</td><td>{CCM}</td></tr>
    # <tr><td>LOC</td><td>{LOC}</td></tr>
    # <tr><td>Elegancy</td><td>{elegance}</td></tr>''')

    # return distinct Function List, Function Number, distinct Variable List, Variable Number, Variable Number
    # depth, LOC, elegancy
    return distinct_func, number_func, distinct_var, number_var, maxdepth, LOC, elegance



