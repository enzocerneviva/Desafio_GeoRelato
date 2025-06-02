# Desafio_GeoRelato
### Interface de Cadastro de Relatos de Catástrofes Naturais

Desenvolva uma interface de programação (API ou CLI) que permita o cadastro de relatos sobre catástrofes naturais ocorridas em um raio de até 10 km a partir de uma localização de referência (ponto central pode ser fixo ou informado pelo usuário).

## Instruções de Execução (via Download ZIP)

### 0. Organização do Projeto

Para conseguirmos fazer todo o código em conjunto, decidimos utilizar o Github. Comçamos dividindo as funções de cadastro entre diferentes aquivos .c mas percebemos depois que seria mais prático criar branchs para depois juntar o código feito por cada integrante e unir filtrando algumas diferenças no final.

### 1. Baixe o projeto
Acesse o repositório pelo navegador: 👉 https://github.com/enzocerneviva/Desafio_GeoRelato

Clique no botão verde “Code” e depois em “Download ZIP”.

Salve o arquivo .zip no seu computador e extraia seu conteúdo (botão direito → Extrair aqui ou Extrair para...).

### 2. Acesse a pasta do projeto
Abra o terminal (Linux/macOS) ou Prompt de Comando (Windows) e navegue até a pasta onde o projeto foi extraído. Por exemplo, se a pasta extraída estiver em Downloads:

bash cd ~/Downloads/Desafio_GeoRelato-main # Linux/macOS

Ou no Windows (caso esteja na pasta padrão de Downloads): cmd cd %HOMEPATH%\Downloads\Desafio_GeoRelato-main

### 3. Compile o projeto
Use o compilador gcc para transformar o arquivo main.c em um executável:

bash gcc main.c -o georelato

Esse comando cria um programa chamado georelato (ou georelato.exe no Windows).

### 4. Execute o sistema
Depois da compilação, execute o programa com: bash

./georelato # No Linux/macOS

Ou no Windows:

cmd georelato.exe

# Formulário do Projeto

### 1. Biliotecas 

#include <stdio.h>: Entrada e saída padrão (printf, scanf, fgets, etc.).

#include <stdlib.h>: Alocação dinâmica e funções utilitárias (system, por exemplo).

#include <string.h>: Manipulação de strings (strlen, strchr, strcmp, etc.).

#include <math.h>: Cálculos matemáticos e trigonométricos (usada no cálculo da distância entre coordenadas geográficas).

#include <ctype.h>: Verificações de caracteres (isdigit).

### 2. Estrutura de Dados

Para organizar os dados utilizamos as structs em C, elas permitem salvar diferentes tipos de variáveis o que nos ajudou a separar de forma clara os dados dos Relatores (usuários) e os Relatos (desastres naturais). Tivemos a ideia de usar um arquivo .csv para guardar as informações de forma definitiva mas prefimos deixar como um futuro upgrade do projeto.

### 3. Cadastros

Para a parte de cadastros, os dados do usuário são pedidos logo na inicialização do sistema para guardar as informações e a localização para futuras buscas de relatos até 10Km de distância. Só é possível fazer o cadastro de uma pessoa por inicialização, nós fizemos dessa forma pois pensamos numa possível plataforma para multiplos usuários utilizando-as ao mesmo tempo futuramente. E para o cadastro de Relatos é possível fazer quantos cadastros desejar.

### 4. Validação dos Dados do Usuário

Para fazer a validação utilizamos algumas funções da biblioteca <string.h> e uma da biblioteca <ctpye.h>, elas servirão desde contagem de caracteres da string para ver se confere com o a forma de algumas informações (ex: telefone ---> 00 00000-0000), até a verificação de um caractere para ver se é um digito ou não.

### 5. Localização e Cálculo da Distância em Km

Para acharmos a distância entre a uma localização central (do usuário) e de um relato de desastre natural utilizamos a fórmula de Haversine. Ela consiste em pegar 2 posições de qualquer ponto da Terra em latitude e longitude, converte-las para radianos, e com isso aplicar na fórmula para achar a distância ente essas 2 posições. Segue a fórmula a seguir:

d = 2 * R * arcsin( √( hav(Δφ) + cos(φ₁) * cos(φ₂) * hav(Δλ) ) )

Onde:
- `d` = distância entre os dois pontos (em metros ou quilômetros)
- `R` = raio da Terra (aproximadamente 6.371.000 metros)
- `φ₁`, `φ₂` = latitude dos pontos 1 e 2 em radianos
- `Δφ` = φ₂ - φ₁
- `Δλ` = longitude₂ - longitude₁
- `hav(θ)` = sin²(θ / 2)

### 6. Listagem e Busca

Para facilitar o acesso às informações cadastradas, implementamos funcionalidades de listagem e busca filtrada. A listagem exibe todos os relatos registrados até o momento, já a busca permite ao usuário encontrar relatos específicos com base em três critérios:

Tipo de desastre (ex: enchente, deslizamento)

Período (ano) de ocorrência

Localização (relatos a até 10 km da posição do usuário)

Essas buscas foram implementadas utilizando laços de repetição (for) e condicionais (if) para comparar os dados do relato com os filtros informados pelo usuário. Para a busca por localização, reutilizamos a função de cálculo da distância com Haversine, garantindo que apenas relatos próximos sejam retornados.

Além disso, usamos a função strcmp() da biblioteca <string.h> para comparar strings como o tipo de desastre, e operadores lógicos para validar intervalos de tempo e distância.

### 7. Menu e Função Main

A função main() foi organizada para simplesmente unir todas as informações e funções e deixar tudo funcional de fato. Logo na inicialização, o sistema realiza o cadastro da pessoa e armazena sua localização.

Em seguida, mostramos ao usuário um menu com opções numeradas, que permitem executar as principais funcionalidades do sistema:

 - Cadastrar um novo relato

 - Listar todos os relatos

 - Buscar relatos filtrando por tipo, ano ou localização

 - Sair do programa

Esse menu é exibido dentro de um laço do-while, que continua rodando até o usuário escolher a opção de sair. A escolha do usuário é lida e por meio de uma estrutura switch é executada uma das funcionalidades, garantindo uma navegação clara e organizada.
