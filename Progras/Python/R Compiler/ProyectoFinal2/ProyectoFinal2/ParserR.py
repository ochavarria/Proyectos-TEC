import sys
from ply import yacc
from R_Lexer import *
import ast
import decimal
import sys
import logging




logging.basicConfig(
    level = logging.DEBUG,
    filename = "parselog.txt",
    filemode = "w",
    format = "%(filename)10s:%(lineno)4d:%(message)s"
)
log = logging.getLogger()


errorsOccured = False

precedence = (
    ('left', 'TERNARY'),
    #('left','LOW','WHILE','FOR','REPEAT'),
    ('right','IF'),
    ('left', 'ELSE'),
    ('right','LEFT_ASSIGN'),
    ('right','EQ_ASSIGN'),
    ('left','RIGHT_ASSIGN'),
    #('left','ENNE','TILDE'),
    ('left','OR','OR2'),
    ('left','AND','AND2'),
    #('left','UNOT','NOT'),
    ('nonassoc','GT','GE','LT','LE','EQ','NE'),
    ('left','PLUS','MINUS'),
    ('left','COLON'),
    #('left','UMINUS','UPLUS'),
    ('right','XOR'),
    ('left','DOLLAR','ARROBA'),
    ('left','NS_GET','NS_GET_INT'),
    ('nonassoc','LPAREN','LBRACKET','LBB')
)



# def Assign(left, right):
#     names = []
#     if isinstance(left, ast.Name):
#         return ast.Assign([ast.AssName(left.name, 'OP_ASSIGN')], right)
#     elif isinstance(left, ast.List):
#         names = []
#         for child in left.getChildren():
#             names.append(child.name)
#         ass_list = [ast.AssName(name, 'OP_ASSIGN') for name in names]
#         print names
#         return ast.Assign([ast.AssList(ass_list)], right)


def p_prog(p):
    """ prog : exprlist
             """
    p[0] = p[1]
  
  
def p_expr_or_assign(p):
     """expr_or_assign : expr
                      | equal_assign"""
 
def p_equal_assign(p):
     """equal_assign : expr EQ_ASSIGN expr_or_assign"""

def p_expr(p):
   """expr : NUM_CONST
           | STR_CONST
           | NULL_CONST
           | SYMBOL
           | LBRACE exprlist RBRACE
           | LPAREN expr_or_assign RPAREN
           | expr COLON expr
           | expr PLUS expr
           | expr MINUS expr
           | expr TIMES expr
           | expr DIVIDE expr
           | expr XOR expr
           | expr MODULO expr
           | expr ENNE expr
           | expr TERNARY expr
           | expr LT expr
           | expr LE expr
           | expr EQ expr
           | expr NE expr
           | expr GE expr
           | expr GT expr
           | expr AND expr
           | expr OR expr
           | expr AND2 expr
           | expr OR2 expr
           | expr LEFT_ASSIGN expr
           | expr RIGHT_ASSIGN expr
           | FUNCTION LPAREN formlist RPAREN  expr_or_assign 
           | expr LPAREN sublist RPAREN
           | IF ifcond expr_or_assign
           | IF ifcond expr_or_assign ELSE expr_or_assign
           | FOR forcond expr_or_assign
           | WHILE cond expr_or_assign
           | REPEAT expr_or_assign
           | expr LBB sublist RBRACKET RBRACKET
           | expr LBRACKET sublist RBRACKET
           | SYMBOL NS_GET SYMBOL
           | SYMBOL NS_GET STR_CONST
           | STR_CONST NS_GET SYMBOL
           | STR_CONST NS_GET STR_CONST
           | NEXT
           | BREAK """

def p_cond(p):
    """cond : LPAREN expr RPAREN"""

def p_ifcond(p):
    """ifcond : LPAREN expr RPAREN"""

def p_forcond(p):
    """forcond : LPAREN SYMBOL IN expr RPAREN"""

def p_exprlist(p):
    """exprlist : expr_or_assign
                | exprlist SEMI expr_or_assign
                | exprlist SEMI
                """
def p_sublist(p):
    """sublist : sub
               | sublist COMMA sub"""
 
def p_sub(p):
    """sub : expr            
        | SYMBOL EQ_ASSIGN    
        | SYMBOL EQ_ASSIGN expr
        | STR_CONST EQ_ASSIGN        
        | STR_CONST EQ_ASSIGN expr    
        | NULL_CONST EQ_ASSIGN
        | NULL_CONST EQ_ASSIGN expr"""
     
def p_formlist(p):
    """formlist : SYMBOL
                | SYMBOL EQ_ASSIGN expr
                | formlist COMMA SYMBOL
                | formlist COMMA SYMBOL EQ_ASSIGN expr"""



    
    
parser = yacc.yacc(debug=True,debuglog=log)
class Paarser():
    def __init__(self):
        self.parser=yacc.yacc(debug=True,debuglog=log)
    def RevisarGramatica(self,codigo):
        t = self.parser.parse(codigo,debug=log)

f = open('Ejemplo.txt', 'r')
data = f.read()
par=Paarser()
par.RevisarGramatica(data)
