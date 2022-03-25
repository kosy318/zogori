# https://www.dabeaz.com/ply/ply.html#ply_nn13

# module: tokrules.py


# Declare the state
from ply.lex import TOKEN

# states = (
#     ('ccode', 'exclusive'),
# )

reserved = {
    'then': 'THEN',

    # 'void': 'VOID',
    # 'int': 'INT',
    # 'vector': 'VECTOR',
    # 'char': 'CHAR',
    # 'string': 'STRING',
}

# list of token names. this is always required
tokens = [
    'INCLUDE',
    'NAMESPACE',
    'FUNCTION',
    'VARIABLE',
    'ID',
    'IF',
    'ELSE_IF',
    'ELSE',
    'WHILE',
    'SWITCH',
    'FOR',
    'NUMBER',
    'OPERATION',
    'COMMA',
    'BRACE',
    'LPAREN',
    'RPAREN',
    'LINDEX',
    'RINDEX',
    'SEMICOLON',
    'STRING_VALUE',
    'CHAR_VALUE',
] + list(reserved.values())

t_OPERATION = r'[<>+\-*\/%|&!~^:=]+'
t_COMMA = r','
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_LINDEX = r'\['
t_RINDEX = r'\]'
t_SEMICOLON = r';'


def t_include(t):
    r'\#include.*'
    # print(t.value)
    t.type = reserved.get(t.value, 'INCLUDE')
    return t


def t_namespace(t):
    r'using.*'
    # print(t.value)
    t.type = reserved.get(t.value, 'NAMESPACE')
    return t


def t_if(t):
    r'if'
    t.type = reserved.get(t.value, 'IF')
    return t


def t_else_if(t):
    r'else if'
    t.type = reserved.get(t.value, 'ELSE_IF')
    return t


def t_else(t):
    r'if'
    t.type = reserved.get(t.value, 'ELSE')
    return t


def t_while(t):
    r'while'
    t.type = reserved.get(t.value, 'WHILE')
    return t


def t_switch(t):
    r'switch'
    t.type = reserved.get(t.value, 'SWITCH')
    return t


def t_for(t):
    r'for'
    t.type = reserved.get(t.value, 'FOR')
    return t


id = r'[a-zA-Z_][a-zA-Z_0-9]*'
function = r'[.]?' + id + '\('#'(.|\n)*?\)'


@TOKEN(function)
def t_FUNCTION(t):
    t.type = reserved.get(t.value, 'FUNCTION')
    return t


variable = r'[a-zA-Z]+[<>a-zA-Z]*'+'\s'+id
@TOKEN(variable)
def t_VARIABLE(t):
    # print(t.value)
    t.type = reserved.get(t.value, 'VARIABLE')
    return t


# a regular expression rule with some action code
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type = reserved.get(t.value, 'ID')  # Check for reserved words
    return t


# this rule matches numbers and convers the string into a python integer.
def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t


# define a rule so we can track line numbers
# 잘 안돼서 제외...
# def t_newline(t):
#     r'\n+'
#     t.lexer.lineno += len(t.value)


# def t_COMMENT(t):
#     r'\#.*'
#     print('commnet line: "%s"' %t.value)
#     pass
#     # No return value. Token discarded


# a string containing ignored characters(spaces and tabs)
# write in string
t_ignore = ' \t\n'
# t_ccode_ignore = ' \t\n'


# Error handling rule
def t_error(t):
    print('illegal character "%s"<br>' % t.value[0])
    t.lexer.skip(1)


def t_BRACE(t):
    r'[\{\}]'
    t.type = reserved.get(t.value, 'BRACE')  # Check for reserved words
    return t



# Match the first {. Enter ccode state.
# def t_ccode(t):
#     r'\{'
#     t.lexer.code_start = t.lexer.lexpos - 1  # Record the starting position
#     t.lexer.level = 1  # Initial brace level
#     t.lexer.begin('ccode')  # Enter 'ccode' state


# Rules for the ccode state
# def t_ccode_lbrace(t):
#     r'\{'
#     t.lexer.level += 1
#
#
# def t_ccode_rbrace(t):
#     r'\}'
#     t.lexer.nested.append(t.lexer.level)
#     t.lexer.level -= 1
#
#     # If closing brace, return the code fragment
#     if t.lexer.level == 0:
#         t.value = t.lexer.lexdata[t.lexer.code_start+1:t.lexer.lexpos-1]
#         t.type = "CCODE"
#         t.lexer.begin('INITIAL')
#         return t


# C or C++ comment (ignore)
# t_ccode_comment로 하니까 안됨... 왜?
# t_comment로 하니까 line count가 제대로 안됨.. 왜???
# 전체 데이터에서 \n을 count 하고 comment의 \n을 count해서 빼주기로 결정
def t_comment(t):
    r'(/\*(.|\n)*?\*/)|(//.*)'
    pass


# C string
def t_string_value(t):
    r'\"([^\\\n]|(\\.))*?\"'
    t.type = reserved.get(t.value, 'STRING_VALUE')
    return t


# C character literal
def t_ccode_char(t):
    r'\'([^\\\n]|(\\.))*?\''
    t.type = reserved.get(t.value, 'CHAR_VALUE')
    return t
#
#
# # Any sequence of non-whitespace characters (not braces, strings)
# def t_ccode_nonspace(t):
#     r'[^\s\{\}\'\"]+'


# # For bad characters, we just skip over it
# def t_ccode_error(t):
#     t.lexer.skip(1)
