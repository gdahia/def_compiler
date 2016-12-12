# Linguagem Def

## Objetivo
O objetivo deste projeto é adquirir experiência na implementação de linguagens de programação através da construção de um compilador para uma simples linguagem chamada Def, similar a linguagem C. A linguagem Def é uma adaptaçāo da linguagem Decaf baseada no projeto original do curso 6.035 do MIT.

## Avaliação
* 15%  Analisador Léxico
* 35%  Analisador Sintático/Semântico
* 50%  Gerador de Código

## Linguagem Def
    Program     = (DecVar | DecFunc)*

    DecVar      = Type ID ('=' Expr)? ';'

    DecFunc     = def Type ID '(' ParamList? ')' Block

    ParamList   = Type ID (',' Type ID)*

    Block       = '{' DecVar* Stmt* '}'

    Stmt        = ID '=' Expr ';' |
                  FuncCall ';' |
                  if '(' Expr ')' Block (else Block)? |
                  while '(' Expr ')' Block |
                  return Expr? ';' |
                  break ';' |
                  continue ';' 

    FuncCall    = ID '(' ArgList? ')'

    ArgList     = Expr (',' Expr)*

    Expr        = Expr BinOp Expr |
                  UnOp Expr |
                  '(' Expr ')' |
                  FuncCall |
                  DECIMAL |
                  ID

    BinOp       = '+' | '-' | '*' | '/' | '<' | '<=' |
                '>' | '>=' | '==' | '!=' | '&&' | '||'

    UnOp        = '-'  | '!'

    Type        = int | void

Embora não estejam refletidas explicitamente na gramática, todas as operações binárias na linguagem são associativas à esquerda e a precedência dos operadores é a mesma usada na linguagem C. Mais precisamente, há sete níveis de precedência dos operadores, listados abaixo do maior nível para a menor nível de precedência.

    Operadores    Comentarios
    -             Negaçāo unária             --> maior precedência
    !             Negaçāo lógica unária (NOT)
    * /           Multiplicaçāo e divisāo (inteiros)
    + -           Adiçāo e subtraçāo (inteiros)
    < <= >= >     Relaçāo lógica
    == !=        Igualdade e desigualdade lógicas
    &&            Conjunçāo lógica (AND)
    ||            Disjunçāo lógica (OR)      --> menor precedência

Importante notar que da forma como a  gramática está descrita acima, ela não é nem _LL (1)_ nem _LR (1)_. Contudo, a gramática deve ser transformada (pelas técnicas vistas em sala de aula) para que seja possível a construção mais adequada do _analisador sintático_ para a linguagem. Note também que, pela gramática, variáveis podem ser declaradas sendo do tipo `void`, mas esse tipo de construção não faz sentido e deve ser checado durante a fase de _análise semântica_.

## Exemplo
    // add.def - simple addition example
    def int add(int x, int y)
    {
      return x + y; // add the two parameters
    }

    def int main()
    {
      int a;
      a = 3;
      print(add(a, 2));
    }

O resultado correto da execuçāo do código acima é o valor decimal 5. Note que uma declaraçāo de funçāo deve começar com a palavra-chave **def**, por isso o nome da linguagem.

## Considerações Léxicas
Há quatro classes de tokens na linguagem Def:

    ID          Identificador
    DECIMAL     Literal decimal (inteiro)
    KEY         Palavra-chave
    SYM         símbolos léxicos

Os **identificadores** e **palavras-chave** devem começar com um caractere alfabético e podem conter caracteres alfanuméricos e o caractere de sublinhado `'_'`.  Uma palavra-chave pode ser vista como um identificador especial que é reservado e nao pode ser usado para definir nomes de variáveis ou funções. As palavras-chave e os identificadores são sensíveis a maiúsculas e minúsculas, e todas as palavras-chave são representadas por minúsculas. Por exemplo, **if** é uma palavra-chave, mas **IF** pode ser um nome de variável; **foo** e **Foo** são dois exemplos de nomes diferentes na linguagem, podendo referir-se a duas variáveis distintas.

Note que palavras-chave e identificadores devem ser separados por espaço em branco, ou por algum token que não é nem uma palavra-chave nem um identificador. Por exemplo, **ifbreak** é um único identificador, e não duas palavras-chave distintas. Se uma sequência de caracteres começa com um caractere alfabético, então ele deve representar a sequência mais longa de caracteres alfanuméricos e sublinhados, formando um único token (palavra-chave ou identificador).

Os **símbolos** podem ser divididos em três tipos: 1) operadores de agrupamento: parênteses, chaves, colchetes, atribuição (sinal de igual), vírgulas e ponto-e-vírgula, 2) operadores binários (BINOP) e 3) operadores unários (UNOP). Há uma variedade de operadores binários e unários na linguagem Def, incluindo tanto os operadores aritméticos (por exemplo, mais e menos) e operadores lógicos/relacionais (por exemplo, ou/e booleano e menor-que). Abaixo está a lista de todos os **símbolos léxicos** da linguagem Def:

    (  {  [  ]  }  )  ,  ;  =  +  -  *  /  <  >  <=  >=  ==  !=  &&  ||  !

As seguintes **palavras-chave** são _reservadas_ na linguagem Def:

    def  if  else  while  return  break  continue  int  void
    
Os comentários em Def são iniciados por "//" e vão até o final da linha. Um token especial "Whitespace" pode aparecer entre quaisquer tokens, e consiste em um ou mais espaços em branco, tabs (\t), e quebra de linhas (\n). Comentários e espaços em branco devem ser descartados durante a fase de análise léxica do compilador.

## Semântica
Um programa escrito na linguagem Def consiste em definições de variáveis e funções, respeitando escopos léxicos correspondentes.

### Variáveis
A linguagem Def permite somente um tipo de variável: inteiro com sinal (32-bit). Uma variável _não pode_ ser declarada como `void`. Variáveis, consideradas _globais_, podem ser declaradas fora de funções e são visíveis por todo código (incluindo as funções já declaradas). Variáveis declaradas dentro de funções ou blocos, consideradas _locais_, somente são visíveis dentro daquela função ou bloco (escopo léxico). Se uma variável for referenciada antes de uma atribuição, considera-se que a variável foi inicializada com valor zero (0).

### Funções
Funções podem não retornar valor algum (`void`) ou retornam um único valor, mas podem receber um número ilimitado de argumentos. Todo código escrito em Def deve conter uma função chamada `main` (sem argumentos) que representa o início da execução do programa. Funções declaradas com retorno de tipo `void` nao podem ser usadas em expressões.

### Escopo léxico
Há dois escopos válidos em um programa Decaf: _global_ e _local_. O escopo global consiste em nomes de funções e variáveis declaradas fora de funções. O escopo local consiste em nomes de variáveis e parâmetros formais declarados em uma função. Escopos locais adicionais podem existem dentro de cada bloco no código, como após as construções `if` ou `while`, ou em qualquer parte do codigo onde há um novo bloco. Nenhum nome de identificador pode ser definido mais de uma vez no mesmo escopo. Assim, nomes de variáveis e funções devem ser distintos no escopo global, e nomes de variáveis locais e nomes de parâmetros formais devem ser distintos em cada escopo local.

## Entrada/Saída
A linguagem prevê a função `print '(' Expr ')'` que não é definida na gramática da linguagem, e sim parte do ambiente de execução da linguagem. A função exibe o valor avaliado de uma expressão na saída padrão seguido de uma quebra de linha (\n). Para isso, será usada uma syscall no MIPS (detalhes na seçāo abaixo). 

## Notas sobre Implementaçāo
O compilador implementado deve gerar código correto (não necessariamente otimizado) para o processador MIPS (32 bits); detalhes da arquitetura MIPS [aqui](https://www.google.com/url?q=https%3A%2F%2Fwww.dropbox.com%2Fs%2F05l8uqe8dbsw5io%2Fmips_quickref.pdf&sa=D&sntz=1&usg=AFQjCNFbKfyXLa740AZfeuSnTbjqGrwsyA) e do conjunto de instruções [aqui](https://www.google.com/url?q=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FMIPS_instruction_set&sa=D&sntz=1&usg=AFQjCNG2bBDmY_-UgpXnWGOPIQZajgxb0g).

**Requisitos da implementaçāo:**
* **Deve** ser implementado em C/C++;
* **Deve** rodar no ambiente Linux/Unix
* _Pode_ opcionalmente usar ferramentas automáticas (Lex/Flex & Yacc/Bison)

O programa do compilador deve receber dois parâmetros/argumentos (argv). O primeiro argumento será o arquivo do código fonte como entrada (e.g., add.def) e o segundo argumento será o arquivo de saída (e.g., out.asm) onde será gravado o código em assembly MIPS; por exemplo:

    $ ./compilador add.def out.asm

Para executar e avaliar os resultados gerados pelos programas da linguagem alvo (MIPS assembly) iremos usar o simulador SPIM (detalhes no manual [aqui](https://www.google.com/url?q=https%3A%2F%2Fwww.dropbox.com%2Fs%2Fugc5oz8c5gpb9ro%2FSPIM_Manual.pdf&sa=D&sntz=1&usg=AFQjCNGd-3qqpbAEyb5fvEHzggjY3HN_fA)).  O SPIM (MIPS32 Simulator) pode ser baixado [aqui](http://www.google.com/url?q=http%3A%2F%2Fspimsimulator.sourceforge.net%2F&sa=D&sntz=1&usg=AFQjCNEE3GRSQ8Z3SmAoPjNDO-mB3qt4Ag).  Veja [aqui](http://www.google.com/url?q=http%3A%2F%2Fwww.doc.ic.ac.uk%2Flab%2Fsecondyear%2Fspim%2Fnode8.html&sa=D&sntz=1&usg=AFQjCNHD4JhPii9dJvVaTQuqvCQm1Xd4-g) detalhes das system calls disponíveis no simulador SPIM.

Para saber mais sobre geradores automáticos de analisadores léxico e sintático, leia os seguintes ponteiros: [Flex in a Nutshell](https://www.google.com/url?q=https%3A%2F%2Fwww.dropbox.com%2Fs%2Fcfu2fvllatyvtg3%2F050%2520Flex%2520In%2520A%2520Nutshell.pdf&sa=D&sntz=1&usg=AFQjCNHdXOyaCdvl1CSVfN4aOYZzl0p3xg)  e [Introduction to Bison](https://www.google.com/url?q=https%3A%2F%2Fwww.dropbox.com%2Fs%2F0fbivxcwi20tpyb%2F120%2520Introducing%2520bison.pdf&sa=D&sntz=1&usg=AFQjCNHhGLYT9NKlTc_fxns3qkbcFWqDoQ).

## Formato de arquivos
### Analisador Léxico
* **Exemplo de Arquivo de Entrada**


    def int main()
    {
      int a;
      a = 4 + 5;
      return a;
    }

* **Exemplo de Arquivo de Saída (espaços em branco serão ignorados):**


    KEY  "def"
    KEY  "int"
    ID   "main"
    SYM  "("  
    SYM  ")"  
    SYM  "{"  
    KEY  "int" 
    ID   "a"  
    SYM  ";"  
    ID   "a"  
    SYM  "="  
    DEC  "4"  
    SYM  "+"  
    DEC  "5"  
    SYM  ";"  
    KEY  "return"  
    ID   "a"  
    SYM  ";"  
    SYM  "}"

## Analisador Sintático

* **Exemplo de Arquivo de Entrada**


    def int add(int x, int y)
    {
        return x + y;
    }

    def int main()
    {
        int a;
        a = 3;
        return add(a, 2);
    }

* **Exemplo de Arquivo de Saída (AST em "labelled bracket notation")**


    [program 
      [decfunc 
        [add] 
        [paramlist [x] [y]] 
        [block 
          [return 
            [+ [x] [y]]
          ]
        ]
      ]  
      [decfunc 
        [main] 
        [paramlist ] 
        [block
          [decvar [a]] 
          [= [a] [3]]
          [return
            [funccall 
              [add]
              [paramlist [a] [2]]
            ]   
          ] 
        ]
      ]
    ]  

A AST pode ser visualizada graficamente (gerada por este site [aqui](http://www.google.com/url?q=http%3A%2F%2Fmshang.ca%2Fsyntree%2F&sa=D&sntz=1&usg=AFQjCNGnXns5cyPIRyZ_qpWuH-tJ0FpRwQ))
