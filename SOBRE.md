# Sobre o projeto

- Programa desenvolvido simula uma rede social utilizando a linguagem C.

- Todos os membros do grupo sao estudantes de ```Engenharia da Computação``` na ```Universidade de Brasilia``` e implementaram este código como projeto da disciplina ```Métodos de Programacao 2017/1``` .

- O banco de dados foi implementado com o auxilio de funções desenvolvidas que manipulam arquivos e a interface gráfifca do programa foi elaborada com funções da biblioteca ```ncurses```.

- As especificacoes de requisitos que foram seguidas esta presente em um arquivo PDF na pasta [roteiro](https://github.com/gabrielpereirapinheiro/social-network/blob/master/Roteiro/MP_Proj_disc_1_17.pdf) do projeto.

- Os testes automatizados foram gerados utilizando a framework [Catch](https://github.com/philsquared/Catch). Foi seguido desenvolvimento orientado a testes (```Test Driven Development```).

- Os comentarios seguiram o padrao para ser possivel ser gerada a documentacao do codigo por meio do [Doxygen](http://www.stack.nl/~dimitri/doxygen/).

# Funcionalidades

- Entre as funcionalidades do programa é possivel um usuário se cadastrar preenchendo algumas campos e realizar login . Apos o usuario realizar login ele podera adicionar amigos ou exclui-los da sua lista de amizade. 
- Podera disponibilizar serviços de acordos com as categorias existentes e poderá procurar por serviços dessas mesmas categorias e realizar uma transação. Ele poderá alterar seus dados cadastrais tais como senha, nome, email e idade . E tambem pode alterar as cores da tela e da letra .

- Para entrar como ```administrador ``` é necessário na hora de realizar login utilizar o cpf: **00000000000** e a senha: **ADMIN123**, e as funcionalidades do administrador do sistema sâo : visualizar todas as relações de amizado do programa, adicicionar ou remorer categorias, visualizar todas as transações já realizadas .
