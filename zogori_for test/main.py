import ply.lex as lex
import tokrules

global num_count
# Build the lexer
lexer = lex.lex(module=tokrules) #, debug=1)

lexer.num_count = 0 # set initial number count

# Test it out
data = '''  int a = 0;
            int b = 0;
            a = a + b;
            b = a / b;
                string str = "string working";
            for(int i=0; i<3; i++){
                a += b;
            } //what do you want>?
            /*
             testing comment
            */
            
            
            
            '''

# Give the lexer some input
lexer.input(data)

result = {}

# Tokenize
while True:
    tok = lexer.token()
    if not tok:
        break  # No more input

    # print(tok.type, "\t\t", tok.value, "  \t", tok.lineno)#,tok.lexpos)
    if tok.type not in result:
        result[tok.type] = [tok.value]
    else:
        result[tok.type].append(tok.value)


for keys in result.keys():
    print(f'{keys: <15}{len(result[keys]): <5}')
    for val in result[keys]:
        print(f'{" "*10}>>   {val}')

LOC = data.count('\n')
print('-'*40)
print('LOC :', LOC)