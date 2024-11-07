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
- Biblioteca **cli-lib** (Certifique-se de incluir a biblioteca e suas dependências no projeto)(certifique-se de incluir a biblioteca e suas dependências no projeto)
- Sistema compatível com Makefile (Unix/Linux ou Windows com MinGW ou Cygwin)

### Compilação
No diretório raiz do projeto, compile o jogo com o comando:
gcc src/main.c src/keyboard.c src/screen.c src/timer.c -o build/FlappyC.exe -I include -Wall

### Execução
Após a compilação, para jogar, utilize o comando: 
build\FlappyC.exe

### Limpeza
Para remover os arquivos gerados durante a compilação, execute:
make clean


## Descrição do Jogo
`FlappyC` é uma versão clássica do jogo Flappy Bird jogável no terminal. O objetivo do jogo é controlar um pássaro para evitar os canos enquanto coleta pontos. O jogo fica mais desafiador conforme o tempo passa e o pássaro precisa navegar entre canos em movimento.

### Regras do Jogo
- Use a tecla Espaço para fazer o pássaro subir.
- O pássaro desce automaticamente devido à gravidade
- Cada vez que o pássaro passa por um cano, a pontuação aumenta.
- O jogo termina se o pássaro colidir com um cano ou o chão.

### Como Jogar
- Pressione a tecla **Espaço** para fazer o pássaro subir.
- O pássaro descerá automaticamente devido à gravidade
- Tente passar pelos canos e aumentar sua pontuação.
- Evite bater nos canos ou no chão.

## Bom jogo e boa diversão!
