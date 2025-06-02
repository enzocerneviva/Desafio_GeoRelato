# Instruções de Execução (via Download ZIP)

## 1. Baixe o projeto
Acesse o repositório pelo navegador:
👉 https://github.com/enzocerneviva/Desafio_GeoRelato

Clique no botão verde “Code” e depois em “Download ZIP”.

Salve o arquivo .zip no seu computador e extraia seu conteúdo (botão direito → Extrair aqui ou Extrair para...).

## 2. Acesse a pasta do projeto

Abra o terminal (Linux/macOS) ou Prompt de Comando (Windows) e navegue até a pasta onde o projeto foi extraído.
Por exemplo, se a pasta extraída estiver em Downloads:

bash
cd ~/Downloads/Desafio_GeoRelato-main  # Linux/macOS

Ou no Windows (caso esteja na pasta padrão de Downloads):
cmd
cd %HOMEPATH%\Downloads\Desafio_GeoRelato-main

## 3. Compile o projeto

Use o compilador gcc para transformar o arquivo main.c em um executável:

bash
gcc main.c -o georelato

Esse comando cria um programa chamado georelato (ou georelato.exe no Windows).

## 4. Execute o sistema

Depois da compilação, execute o programa com:
bash
./georelato       # No Linux/macOS

Ou no Windows:
cmd
georelato.exe
