# https://www.dabeaz.com/ply/ply.html#ply_nn13

# module: tokrules.py


# Declare the state
from ply.lex import TOKEN
import re

reserved = {
}

# list of token names. this is always required
tokens = [
             'INCLUDE',
             'NAMESPACE',
             'FUNCTION',
             'FUNCTION_DECLARATION',
             'VARIABLE',
             'TYPE',
             'ID',
             'ELSE_IF',
             'IF',
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
             'ENDL',
             'MAIN',
             'STRING_VALUE',
             'CHAR_VALUE',
             'SHARP',
         ] + list(reserved.values())

t_OPERATION = r'[<>+\-*\/%|&!~^:=]+'
t_COMMA = r','
t_LPAREN = r'\('
t_RPAREN = r'\)'
t_LINDEX = r'\['
t_RINDEX = r'\]'
t_SEMICOLON = r';'
t_SHARP = r'\#.*'


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


def t_else_if(t):
    r'else\sif[^a-zA-Z]'
    t.type = reserved.get(t.value, 'ELSE_IF')
    return t


def t_if(t):
    r'(if[^a-zA-Z])|(\?)'
    t.type = reserved.get(t.value, 'IF')
    return t


def t_else(t):
    r'else'
    t.type = reserved.get(t.value, 'ELSE')
    return t


def t_while(t):
    r'while[^a-zA-Z]'
    t.type = reserved.get(t.value, 'WHILE')
    return t


def t_switch(t):
    r'switch[^a-zA-Z]'
    t.type = reserved.get(t.value, 'SWITCH')
    return t


def t_for(t):
    r'for[^a-zA-Z]'
    t.type = reserved.get(t.value, 'FOR')
    return t


id = r'[a-zA-Z_][a-zA-Z_0-9]*'
variable = r'([a-zA-Z]+<.*>[*]?[\s]*' + id + ')|([a-zA-Z]+[\s]<.*>[*]?[\s]*' + id + ')|([a-zA-Z]+[*]?' + '\s' + id + ')'
function = r'([.]?' + id + '[\s]*\()|(\.' + id + ')|(cin)|(cout)'
function_declaration = r'' + variable + '\('


@TOKEN(function_declaration)
def t_FUNCTION_DECLARATION(t):
    # print("function_D", t.value)
    t.type = reserved.get(t.value, 'FUNCTION_DECLARATION')
    return t


@TOKEN(function)
def t_FUNCTION(t):
    # print("function", t.value)
    t.value = re.sub(r"[^a-zA-Z0-9]", "", t.value)
    t.type = reserved.get(t.value, 'FUNCTION')
    return t


def t_ENDL(t):
    r'endl'
    t.type = reserved.get(t.value, 'STRING_VALUE')
    return t


@TOKEN(variable)
def t_VARIABLE(t):
    t.value = re.sub(r"[*]", "", t.value)
    # print("variable", t.value)
    t.type = reserved.get(t.value, 'VARIABLE')
    return t


type = r'\(' + id + '\)'


@TOKEN(type)
def t_TYPE(t):
    t.value = re.sub(r"[\(\)]", "", t.value)
    # print("type", t.value)
    t.type = reserved.get(t.value, 'TYPE')
    return t


# a regular expression rule with some action code
def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    # print("id", t.value)
    t.type = reserved.get(t.value, 'ID')  # Check for reserved words
    return t


# this rule matches numbers and convers the string into a python integer.
def t_NUMBER(t):
    r'[+-]?([0-9]*[.])?[0-9]+'
    try:
        t.value = int(t.value)
    except (ValueError):
        t.value = float(t.value)
    return t


# a string containing ignored characters(spaces and tabs)
# write in string
t_ignore = '. \t\n'


# Error handling rule
def t_error(t):
    print('<script>console.log(illegal character "%s")</script>' % t.value[0])
    t.lexer.skip(1)


def t_BRACE(t):
    r'[\{\}]'
    t.type = reserved.get(t.value, 'BRACE')  # Check for reserved words
    return t


# # C or C++ comment (ignore)
# def t_comment(t):
#     r'(/\*(.|\n)*?\*/)|(//.*)'
#     pass


# C string
def t_string_value(t):
    r'\"([^\\\n]|(\\.))*?\"'
    t.type = reserved.get(t.value, 'STRING_VALUE')
    return t
