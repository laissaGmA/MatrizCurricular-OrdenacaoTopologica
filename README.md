# Matriz Curricular - Bacharelado em Ciência da Computação

Este projeto consiste em um programa em C para gerenciar a matriz curricular do curso de Bacharelado em Ciência da Computação da UFAPE (Universidade Federal do Agreste de Pernambuco). O programa permite visualizar a matriz curricular, as dependências diretas entre disciplinas, realizar ordenação topológica das disciplinas e exportar o grafo em formato DOT.

## Pré-requisitos

- Compilador C (como GCC)
- Sistema operacional compatível (Linux, Windows, MacOS)

## Instalação

1. Clone este repositório em sua máquina local:

git clone https://github.com/seu-usuario/matriz-curricular.git


2. Compile o programa usando o compilador C:

gcc main.c ./grafo/grafo.c ./fila/fila.c ./pilha/pilha.c ./lista_enc/lista_enc.c -o matriz_curricular


3. Execute o programa:

./matriz_curricular


## Como usar

Após executar o programa, um menu será exibido com as seguintes opções:

1. **Imprimir Matriz Curricular**: exibe a lista de disciplinas e suas dependências diretas.
2. **Imprimir Matriz de Dependências Diretas**: exibe a matriz de dependências diretas entre as disciplinas.
3. **Realizar Ordenação Topológica das Disciplinas**: gera uma ordem de cursagem das disciplinas considerando suas dependências.
4. **Exportar Grafo em formato DOT**: exporta o grafo em formato DOT para visualização.
5. **Sair**: encerra o programa.

## Estrutura do Código

O código-fonte está estruturado em diferentes arquivos:

- `grafo.c`: contém as funções relacionadas à criação e manipulação do grafo.
- `fila.c`: contém as implementações de uma fila.
- `pilha.c`: contém as implementações de uma pilha.
- `lista_enc.c`: contém as implementações de uma lista encadeada.

## Funcionalidades

### Criar Grafo

A função `cria_grafo` é responsável por criar um novo grafo com um número especificado de vértices.

### Ler Arquivo

A função `ler_arquivo` lê as informações do arquivo `montagemdagradebcc.txt`, que contém os detalhes da matriz curricular, e cria o grafo correspondente.

### Imprimir Matriz Curricular

A função `imprime_vertices` exibe a lista de disciplinas e suas dependências diretas.

### Imprimir Matriz de Dependências Diretas

A função `imprime_matriz` exibe a matriz de dependências diretas entre as disciplinas.

### Realizar Ordenação Topológica

A função `ordenacao_topologica` gera uma ordem de cursagem das disciplinas considerando suas dependências. A ordem é exibida no terminal e também salva no arquivo `OrdenacaoTopologica_de_Disciplinas.txt`.

### Exportar Grafo em Formato DOT

A função `exportar_grafo_dot` exporta o grafo em formato DOT para visualização.

## Contribuindo

Contribuições são bem-vindas! Para contribuir com este projeto, siga estas etapas:

1. Faça um fork deste repositório
2. Crie uma branch para sua nova feature (`git checkout -b feature/nova-feature`)
3. Faça commit de suas alterações (`git commit -am 'Adiciona nova feature'`)
4. Faça push para a branch (`git push origin feature/nova-feature`)
5. Abra uma pull request

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
