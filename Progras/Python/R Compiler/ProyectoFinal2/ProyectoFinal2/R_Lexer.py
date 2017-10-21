
import sys
import ply.lex as lex
import math
sys.path.insert(0,"../..")


def find_tok_column(token):
    last_cr = lexer.lexdata.rfind('\n', 0, token.lexpos)
    if last_cr < 0:
      last_cr = 0
    return token.lexpos - last_cr

# Lista de Tokens
tokens = (
    # Palabras reservadas
    'FOR',
    'IN',
    'IF',
    'ELSE',
    'WHILE',
    'NEXT',
    'BREAK',
    'REPEAT',
    'PRINT',
    'LOG',
    'ABS',
    'FACTORIAL',
    'EXP',
    'TOLOWER',
    'TOUPPER',
    'TOSTRING',
    'FLOOR',
    'ATAN',
    'COS',
    'TAN',
    'SQRT',
    'LOG10',
    'LIST',
    
    
    #Condicional
    'FALSE',
    'TRUE',
    'SYMBOL',
    
    # Simbolos
    'END_OF_INPUT',
    #'ERROR',
    'STR_CONST',
    'NUM_CONST',
    'NULL_CONST',
    'FUNCTION',
    'LEFT_ASSIGN',
    'EQ_ASSIGN',
    'RIGHT_ASSIGN',
    'LBB',
    'RBB',
    'GT',
    'GE',
    'LT',
    'LE',
    'EQ',
    'NE',
    'AND',
    'OR',
    'AND2',
    'OR2',
    'NS_GET',
    'NS_GET_INT',
    #'COMMENT',
    #'SPACES',
    #'ROXYGEN_COMMENT',
    #'SYMBOL_FORMALS',
    #'EQ_FORMALS',
    #'EQ_SUB',
    #'SYMBOL_SUB',
    #'SYMBOL_FUNCTION_CALL',
    #'SYMBOL_PACKAGE',
    #'COLON_ASSIGN',
    #'SLOT',
    'NEWLINE',
    'LPAREN', 'RPAREN',
    'LBRACKET', 'RBRACKET',
    'LBRACE', 'RBRACE',
    'COMMA', 'PERIOD', 'SEMI', 'COLON',
    'PLUS','MINUS','TIMES','DIVIDE','TERNARY','MODULO',
    'XOR','ENNE','DOLLAR','ARROBA','END',    
    
)

# Expresiones regulares para las palabras reservadas
t_EQ_ASSIGN = r'='
t_LT        = r'<'
t_GT        = r'>'
t_OR        = r"\|"
t_AND       = r'&'
t_LBB       = r'\[\['

# Delimeters
t_LPAREN           = r'\('
t_RPAREN           = r'\)'
t_LBRACKET         = r'\['
t_RBRACKET         = r'\]'
t_LBRACE           = r'\{'
t_RBRACE           = r'\}'
t_COMMA            = r','
t_PERIOD           = r'\.'
t_SEMI             = r';'
t_COLON            = r':'

# Operaciones
t_PLUS      = r'\+'
t_MINUS     = r'-'
t_TIMES     = r'\*'
t_DIVIDE    = r'/'


#Otros Operadores
t_TERNARY   = r'\?'
t_MODULO    = r'%'
t_XOR       = r'\^'
t_ENNE      = r'~'
t_DOLLAR    = r'\$'
t_ARROBA     = r'@'
t_END        = r'END'

#Definiciones para algunas palabras reservadas.

def t_PRINT(t):
    r'print'
    return t

def t_Exp(t):
    r'exp'
    return t

def t_SQRT(t):
    r'sqrt'
    return t    

def t_LOG(t):
    r'log'
    return t

def t_LOG10(t):
    r'log10'
    return t

def t_ABS(t):
    r'abs'
    return t

def t_FACTORIAL(t):
    r'factorial'
    return t


def t_TOLOWER(t):
    r'tolower'
    return t

def t_TOUPPER(t):
    r'toupper'
    return t

def t_TOSTRING(t):
    r'tostring'
    return t

def t_ATAN(t):
    r'atan'
    return t

def t_COS(t):
    r'cos'
    return t

def t_TAN(t):
    r'tan'
    return t

def t_EXP(t):
    r'exp'
    return t

def t_ELSE(t):
    r'else'
    return t

def t_IF(t):
    r'if'
    return t

def t_LIST(t):
    r'list'
    return t

def t_END_OF_INPUT(t):
    r'end of input'
    return t
    
# def t_ERROR(t):
#     r'input'
#     return t
    
def t_STR_CONST(t):
    r'L?\"(\\.|[^\\"])*\"'
    return t
    
def t_WHILE(t):
    r'while'
    return t

def t_FUNCTION(t):
    r'function'
    return t


def t_NUM_CONST(t):
    r'\d+'
    t.value = int(t.value)
    return t



def t_LEFT_ASSIGN(t):
    #r'assignment'
    r'<-'
    return t

def t_NULL_CONST(t):
    r'NULL'
    return t



def t_RIGHT_ASSIGN(t):
    r'->'
    return t

def t_FALSE(t):
    r'false'
    return t

def t_TRUE(t):
    r'true'
    return t

def t_FOR(t):
    r'for'
    return t

def t_IN(t):
    r'in'
    return t

def t_NEXT(t):
    r'next'
    return t

def t_BREAK(t):
    r'break'
    return t

def t_REPEAT(t):
    r'repeat'
    return t





#Definiciones para num    
# def t_NUM(t):
#     r'\d+'
#     t.value = int(t.value)
#     return t
# #Definicion para ID
# 
# def t_ID(t):
#     r'\w+(_\d\w)*'
#     return t

#Definiciones para operaciones logicas 

def t_LQ(t):
    r'<='
    return t

def t_GE(t):
    r'>='
    return t

def t_EQ(t):
    r'=='
    return t

def t_NE(t):
    r'!='
    return t

def t_AND2(t):
    r'&&'
    return t

def t_OR2(t):
    r"\|\|"
    return t

def t_NS_GET(t):
    r'::'
    return t

def t_NS_GET_INT(t):
    r':::'
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)
    t.type = "NEWLINE"
    return t

t_ignore = ' \t \n'


def t_SYMBOL(t):
    r'\w+(_\d\w)*'
    return t

#Se definen los comentarios
def t_comments(t):
    r'\#(L?\(\\.|[^\\"])*\)'
    t.lexer.lineno += t.value.count('\n')

#Se define otro tipo de comentarios
def t_comments_C99(t):
    r'//(.)*?\n'
    t.lexer.lineno += 1

#Para indicar cuando existe un error
def t_error(t):
    print "Lexical error: " + str(t.value[0])
    t.lexer.skip(1)


# funcion para inprimer un token
def test(data, lexer):
    lexer.input(data)
    while True:
        tok1 = lexer.token()
        if not tok1:
            break
        print tok1

data = '''
     recursive.factorial <- function(x) {
        if (x == 0)    return (1)
         else           return (x * recursive.factorial(x-1))
      }
     '''
lexer = lex.lex()

class lexxer():
    def __init__(self):
        self.lexer = lex.lex()
        
    def RevisarTokens(self,codigo):
        self.lexer.input(codigo)
        test(codigo, self.lexer)
      



