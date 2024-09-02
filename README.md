Eu ainda estava aprendendo nessa época

# Sistema de Gestão de Bilheteria em C

## Descrição
Este projeto em C implementa um sistema de gestão de bilheteria que permite a visualização, reserva, compra e bloqueio de poltronas em um ambiente de cinema ou teatro. O sistema armazena as informações de cada poltrona em uma matriz 7x7 e oferece funcionalidades para gerenciar o status das poltronas. Além disso, os dados podem ser salvos em um arquivo binário para que o estado do sistema seja preservado entre execuções.

## Funcionalidades
- **Exibir Status das Poltronas**: Mostra o status atual de todas as poltronas em uma matriz 7x7.
- **Reservar Poltrona**: Permite reservar uma poltrona específica, alterando seu status para reservado.
- **Comprar Poltrona**: Permite comprar uma poltrona específica, alterando seu status para comprado.
- **Bloquear Poltrona**: Permite bloquear uma poltrona específica, alterando seu status para bloqueado.
- **Total Arrecadado**: Calcula e exibe o total arrecadado pela bilheteria com base nas poltronas compradas.
- **Salvar e Carregar Estado**: Salva o estado atual do sistema em um arquivo binário e permite carregar o estado salvo em uma execução futura.

## Como Usar
1. Compile o código utilizando um compilador C. Exemplo:
   ```bash
   gcc -o bilheteria bilheteria.c
   ```
2. Execute o programa:
   ```bash
   ./bilheteria
   ```
3. Utilize as opções do menu para gerenciar as poltronas e visualizar o status da bilheteria.

## Estrutura de Dados
O sistema utiliza uma estrutura `Poltrona` para representar cada poltrona na matriz 7x7. Cada poltrona contém:
- **nome**: Nome do comprador (caso aplicável).
- **valor**: Valor da poltrona (predefinido como R$50,00).
- **status**: Status da poltrona, onde 1 = disponível, 2 = reservada, 3 = comprada, 4 = bloqueada.

## Funções Principais
- **ExibirStatus()**: Exibe a matriz de status das poltronas.
- **Reservar()**: Reserva uma poltrona específica.
- **Comprar()**: Compra uma poltrona específica.
- **Bloquear()**: Bloqueia uma poltrona específica.
- **Salvar()**: Salva o estado atual da matriz em um arquivo binário.
- **Retornar()**: Carrega o estado salvo de um arquivo binário.

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).
