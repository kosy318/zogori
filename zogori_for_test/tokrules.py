# https://www.dabeaz.com/ply/ply.html#ply_nn13

# module: tokrules.py


# Declare the state
from ply.lex import TOKEN

states = (
    ('ccode', 'exclusive'),
)

reserved = {
    'if': 'IF',
    'then': 'THEN',
    'else': 'ELSE',
    'while': 'WHILE',
    'switch': 'SWITCH',
    'for': 'FOR',

    'int': 'INT',
    'vector': 'VECTOR',
    'char': 'CHAR',
    'string': 'STRING',
}



# list of token names. this is always required
tokens = [
    'CCODE',
    'ID',
    'NUMBER',
    'ARITHMETIC_OP',
    'EQ',
    'DOUBLE_EQ',
    'LESS_THAN',
    'GREATER_THAN',
    'LPAREN',
    'RPAREN',
    'SEMICOLON',
    'STRING_VALUE',
    'FUNCTION',
] + list(reserved.values())


t_ARITHMETIC_OP = r'[+\-*\/]'
t_DOUBLE_EQ = r'=='
t_EQ = r'='
t_LESS_THAN = '<'
t_GREATER_THAN = '>'
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_SEMICOLON = r';'


def t_include(t):
    r'\#include.*'
    # print(t.value)
    pass


def t_namespace(t):
    r'using.*'
    # print(t.value)
    pass


id = r'[a-zA-Z_][a-zA-Z_0-9]*'
function = r'' + id + '\((.|\n)*?\)'

@TOKEN(function)
def t_FUNCTION(t):
    t.type = reserved.get(t.value, 'FUNCTION')
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
t_ccode_ignore = ' \t\n'


# Error handling rule
def t_error(t):
    print('illegal character "%s"' %t.value[0])
    t.lexer.skip(1)


# Match the first {. Enter ccode state.
def t_ccode(t):
    r'\{'
    t.lexer.code_start = t.lexer.lexpos - 1  # Record the starting position
    t.lexer.level = 1  # Initial brace level
    t.lexer.begin('ccode')  # Enter 'ccode' state


# Rules for the ccode state
def t_ccode_lbrace(t):
    r'\{'
    t.lexer.level += 1


def t_ccode_rbrace(t):
    r'\}'
    t.lexer.level -= 1

    # If closing brace, return the code fragment
    if t.lexer.level == 0:
        t.value = t.lexer.lexdata[t.lexer.code_start:t.lexer.lexpos + 1]
        t.type = "CCODE"
        t.lexer.begin('INITIAL')
        return t


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


# Any sequence of non-whitespace characters (not braces, strings)
def t_ccode_nonspace(t):
    r'[^\s\{\}\'\"]+'


# For bad characters, we just skip over it
def t_ccode_error(t):
    t.lexer.skip(1)
