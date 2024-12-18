# Nome do Jogo: FlappyC

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
[Repositório no GitHub](https://github.com/YlsonSantos/FlappyC.git)

## Instruções de Compilação e Execução

### Requisitos
- **Compilador C** (recomenda-se `gcc` ou `clang`)
- Biblioteca **cli-lib** (Certifique-se de incluir a biblioteca e suas dependências no projeto)(certifique-se de incluir a biblioteca e suas dependências no projeto)
- Sistema compatível com Makefile (Unix/Linux ou Windows com MinGW ou Cygwin)

### Compilação
No diretório raiz do projeto, compile o jogo com o comando:
`gcc src/main.c src/keyboard.c src/screen.c src/timer.c src/menu.c -o build/FlappyC.exe -I include -Wall`

### Execução
Após a compilação, para jogar, utilize o comando: 
`build\FlappyC.exe`

### Limpeza
Para remover os arquivos gerados durante a compilação, execute:
`make clean`


## Descrição do Jogo
`FlappyC` é uma versão clássica do jogo Flappy Bird jogável no terminal. O objetivo do jogo é controlar um pássaro para evitar os canos enquanto coleta pontos. O jogo fica mais desafiador conforme o tempo passa e o pássaro precisa navegar entre canos em movimento.

### Regras do Jogo
- Use a tecla Espaço para fazer o pássaro subir.
- O pássaro desce automaticamente devido à gravidade
- Cada vez que o pássaro passa por um cano, a pontuação aumenta.
- O jogo termina se o pássaro colidir com um cano ou o chão.

### Como Jogar
Menu Inicial:
- Navegue pelo menu usando as teclas Seta para Cima e Seta para Baixo para selecionar entre as opções.
- Pressione Enter para escolher uma opção:
    - Iniciar Jogo: Comece a jogar.
    - Ver Pontuação: Veja sua pontuação atual e o ranking.
    - Sair: Encerre o jogo.

Durante o Jogo:
- Pressione Espaço para fazer o pássaro subir.
- Tente passar pelos canos para aumentar sua pontuação.
- Evite bater nos canos ou no chão, ou o jogo terminará.

Pós-Jogo:
- Ranking de Pontuação: Após o jogo, você verá sua pontuação final e poderá comparar com as pontuações mais altas no ranking.
    - As melhores pontuações serão salvas e exibidas para motivar sua próxima tentativa.

## Bom jogo e boa diversão!