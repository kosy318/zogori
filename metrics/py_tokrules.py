
from ply.lex import TOKEN


states = (
    ('multistring1', 'exclusive'),
    ('multistring2', 'exclusive'),
)

reserved = {
    'elif':'ELIF',
    'else':'ELSE',
    'then': 'THEN',
    'for': 'FOR',
    'del':"DEL",
    'is':"IS",
    'not':"NOT",
    'in':"IN",
    'global':"GLOBAL",
    'and':"AND",
    'or':"OR",

}

tokens = [
    'ID',
    'NUMBER',
    'LPAREN',
    'RPAREN',
    'COMMENT',
    'STRING',
    'FUNCTION',
    'MULTISTRING',
    'OPERATOR',
    'BRACE',
    'BRACKET',
    'INDENTION',
    'WHITESPACE',
    'IF',
    'WHILE',
    'MODULE',
    'FLOWCONTROL',
] + list(reserved.values())


t_LPAREN = r'\('
t_RPAREN = r'\)'
t_BRACKET = r'[\[\]]'
t_BRACE = r'[\{\}]'
t_OPERATOR = r'[+/&%^~\-|*=<->!,]+'
t_COMMENT = r'\#.*?\n'
t_STRING = r'\".*?\"|\'.*?\''
id = r'[a-zA-Z_][a-zA-Z_0-9]*'
function =r'' + id + '\(' #(.|\n)*?\)'


def t_MODULE(t):
    r'(from\s[^\s]+)?\simport\s[^\n]+'
    t.type = reserved.get(t.value,"MODULE")
    return t

# Write on top of function to filter out ahead of function because of if() expression
def t_IF(t):
    r'if'
    t.type = reserved.get(t.value,'IF')
    return t

def t_WHILE(t):
    r'while'
    t.type = reserved.get(t.value,'WHILE')
    return t
    
def t_FLOWCONTROL(t):
    r'(pass)|(continue)|(return)|(break)'
    return t

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



def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_INDENTION(t):
    r'(\s\s\s\s)+'
    return t
def t_WHITESPACE(t):
    r'\s'
    pass




# Error handling rule
def t_error(t):
    print('illegal character "%s"' %t.value[0])
    t.lexer.skip(1)

def t_multistring1(t):
    r'\'{3}'
    t.lexer.code_start  = t.lexer.lexpos-3
    t.lexer.begin('multistring1')

def t_multistring1_end(t):
    r'.*?\'{3}\n?'
    t.value = t.lexer.lexdata[t.lexer.code_start:t.lexer.lexpos]
    t.type = "MULTISTRING"
    t.lexer.begin('INITIAL')
    return t

def t_multistring1_str(t):
    r'.*?\n'


def t_multistring2(t):
    r'\"{3}'
    t.lexer.code_start = t.lexer.lexpos-3
    # Record the starting position
    t.lexer.begin('multistring2')


def t_multistring2_end(t):
    r'.*?\"{3}\n?'
    t.value = t.lexer.lexdata[t.lexer.code_start:t.lexer.lexpos]
    t.type = "MULTISTRING"
    t.lexer.begin('INITIAL')
    return t

def t_multistring2_str(t):
    r'.*?\n'

t_ignore = '\t:.'
#t_ignore_COMMENT = r'\#.*'

