import ply.lex as lex
import py_tokrules
import re
import sys
import math
from collections import deque

# Build the lexer

def cal_complexity(file_name):
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
                variable += 1
                if tok.value not in variableValue:
                    variableValue.append(tok.value)
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
            functionNumber += 1
            # 왼쪽 소괄호 제거
            funcName = str(tok.value).rstrip("(")
            if funcName not in operatorType:
                operatorType.append(funcName)
                if funcName not in functionValue:
                    functionValue.append(funcName)



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


    # print("variable : ",variable, " ", variableValue)
    # print(functionValue)
    # print(treeString)

    V = len(variableValue)
    Vd = variable
    F = len(functionValue)
    Fd = functionNumber
    D = maxdepth
    # print((V + Vd + Vd/V + F + Fd + Fd/F)**math.log(D+1))
    # print(((V + Vd + Vd/V + F + Fd + Fd/F)/100)**math.log(D+1))
    # print((V + Vd + Vd/V + F + Fd + Fd/F+LOC)**math.log(D+1))
    # print(((V + Vd + Vd/V + F + Fd + Fd/F+LOC)/100)**math.log(D+1))
    elegancy = ((V + Vd + Vd/V + F + Fd + Fd/F)/100)**math.log(D+1)


    # print("Program vocabulary : ", vocabulary)
    # print("Program length : ", length)
    # print("Estimated program length : ", estimated_length)
    # print("Difficulty : ", difficulty)
    # print("Effort : ", effort)
    # print("Functions : ", len(functionValue), functionValue)
    # print("total nb of Functions : ", volume)
    # print("Volume : ", functionNumber)
    # print("Variables : ", len(variableValue),variableValue)
    # print("nb of Variables : ", variable)
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



    print(f'''<tr><td>Program vocabulary</td><td>{vocabulary}</td></tr>
    <tr><td>Program length</td><td>{length}</td></tr>
    <tr><td>Estimated program length</td><td>{estimated_length}</td></tr>
    <tr><td>Volume</td><td>{volume}</td></tr>
    <tr><td>Difficulty</td><td>{difficulty}</td></tr>
    <tr><td>Effort</td><td>{effort}</td></tr>
    <tr><td>Functions</td><td>{len(functionValue)}: {functionValue}</td></tr>
    <tr><td>total nb of Functions</td><td>{functionNumber}</td></tr>
    <tr><td>Variables</td><td>{len(variableValue)}: {variableValue}</td></tr>
    <tr><td>total nb of Variables</td><td>{variable}</td></tr>
    <tr><td>Depth</td><td>{maxdepth}: {treeString}</td></tr>
    <tr><td>CCM</td><td>{CCM}</td></tr>
    <tr><td>LOC</td><td>{LOC}</td></tr>
    <tr><td>Elegancy</td><td>{elegancy}</td></tr>''')

return 0

