# Nome do Jogo: SnakeC

## Membros da Equipe
| Nome               | Função             | GitHub             |
|--------------------|--------------------|--------------------|
| Ylson Santos       | Developer          | @YlsonSantos       |
| Matheus Rian       | Developer          | @Matheus-Rian      |
| Gabriel Victor     | Developer          | @gabrielvictor00   |

## Disciplina
Programação Imperativa e Funcional - 2024.2

## Instituição de Ensino
CESAR School

## Link do Repositório
[Repositório no GitHub](https://github.com/YlsonSantos/Jogo-C.git)

## Instruções de Compilação e Execução

### Requisitos
- **Compilador C** (recomenda-se `gcc` ou `clang`)
- **cli-lib** (certifique-se de incluir a biblioteca e suas dependências no projeto)
- **Sistema compatível com Makefile** (Unix/Linux rodando na máquina virtual Oracle VirtualBox)

### Compilação
No diretório raiz do projeto, compile o jogo com o comando:
O executável será gerado na pasta build/.

### Execução
Após a compilação, para jogar, utilize o comando:

### Limpeza
Para remover os arquivos gerados durante a compilação, execute:

## Descrição do Jogo
`SnakeC` é uma versão clássica do jogo da cobrinha jogável no terminal. O objetivo é comer frutas que aparecem na tela, fazendo a cobra crescer de tamanho e aumentando a pontuação. O jogo fica mais desafiador conforme a cobra cresce.

### Regras do Jogo
- Controle a cobra usando as teclas direcionais do teclado.
- Cada fruta coletada aumenta o tamanho da cobra e incrementa a pontuação.
- O jogo termina se a cobra colidir com as paredes ou com seu próprio corpo.

### Como Jogar
- Use as **teclas de direção** para mover a cobra para cima, baixo, esquerda ou direita.
- Colete as frutas para aumentar a pontuação.
- Evite colidir com as bordas e com o próprio corpo.

## Bom jogo e boa diversão!

/projeto
├── src/ # Código-fonte (.c)
├── include/ # Cabeçalhos (.h)
├── build/ # Saídas de compilação
├── README.md # Descrição do projeto
├── Makefile # Arquivo de build
└── LICENSE # Licença