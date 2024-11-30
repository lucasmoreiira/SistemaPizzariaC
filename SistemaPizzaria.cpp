#include <stdio.h>
#include <locale.h>
#include <string.h>

#define FILENAME "bibilioteca.csv"

typedef struct
{

    int id;
    char nome[50];
    char endereco[50];
    char telefone[20];
    char email[50];
} Cliente;

#define MAX_PEDIDOS 100

typedef struct
{
    int id;
    char borda[30];
    char tamanho[30];
    char sabor1[30];
    char sabor2[30];
    char bebida[30];
    float total;
} Pedido;

Pedido pedidos[MAX_PEDIDOS];
int totalPedidos = 0;

#define MAX_FUNCIONARIOS 100

typedef struct {
    int id;
    char nome[100];
    char email[100];
    char funcao[20];
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int totalFuncionarios = 0;

void cadastrarClientes();
void listarClientes();
void excluirClientes();
void editarClientes();
void exibirMenu();
void abaClientes();
void exibirMenuCliente();
void exibirMenuPedidos();
void preencherPedido(Pedido *pedido);
float calcularTotal(float valorBorda, float valorTamanho, float valorSabor1, float valorSabor2, float valorBebida);
void abaPedidos();
void adicionarPedido();
void editarPedido();
void listarPedidos();
void exibirMenuFucionario();
void abaFuncionario();
void adicionarFuncionario();
void listarFuncionarios();
void editarFuncionario();
void excluirFuncionario();
void Menu();
void excluirPedido();


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            abaClientes();
            break;
        case 2:
            abaPedidos();
            break;
            
        case 3:
            abaFuncionario();
            break;    
            
        case 4:
            printf("Saindo....\n");
            break;
        default:
            printf("Operação inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

void exibirMenu() {
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|                           PIZZARIA                                         |\n");
    printf("|                                                                            |\n");
    printf("|                  Sistema de Gerenciamento de Pizzaria                      |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|  [1] - Seção Cliente       -> Gerencie informações dos clientes            |\n");
    printf("|  [2] - Seção Pedidos       -> Faça e acompanhe os pedidos                  |\n");
    printf("|  [3] - Seção Funcionarios  -> Gerencie informações dos Funcionarios        |\n");
    printf("|  [4] - Sair                -> Encerrar o sistema                           |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("Digite o número correspondente à sua escolha: ");
}


void exibirMenuCliente() {
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|                           PIZZARIA                                         |\n");
    printf("|                                                                            |\n");
    printf("|                  Sistema de Gerenciamento de Pizzaria                      |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|  [1] - Cadastrar Cliente -> Adicione novos clientes ao sistema             |\n");
    printf("|  [2] - Listar Clientes   -> Visualize a lista de clientes cadastrados      |\n");
    printf("|  [3] - Excluir Cliente   -> Remova clientes do sistema                     |\n");
    printf("|  [4] - Editar Cliente    -> Atualize informações dos clientes              |\n");
    printf("|  [5] - Sair              -> Voltar ao menu principal                       |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("Digite o número correspondente à sua escolha: ");
}

void exibirMenuPedidos(){
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|                           PIZZARIA                                         |\n");
    printf("|                                                                            |\n");
    printf("|                  Sistema de Gerenciamento de Pedidos                       |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|  [1] - Adicionar Pedido   ? Adicione um novo pedido ao sistema             |\n");
    printf("|  [2] - Listar Pedidos     ? Visualize os pedidos realizados                |\n");
    printf("|  [3] - Editar Pedido      ? Atualize informações de um pedido existente    |\n");
    printf("|  [4] - Excluir Pedido     ? Exclua um pedido ja existente                  |\n");
    printf("|  [5] - Sair               ? Voltar ao menu principal                       |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("Digite o número correspondente à sua escolha: ");
    
}

void exibirMenuFucionario() {
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|                           PIZZARIA                                         |\n");
    printf("|                                                                            |\n");
    printf("|                    Gerenciamento de Fucionarios                            |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("|                                                                            |\n");
    printf("|  [1] - Adicionar Funcionario  -> Adicione um Funcionario.                  |\n");
    printf("|  [2] - Listar Funcionarios    -> Veja os funcionarios.                     |\n");
    printf("|  [3] - Editar Funcionario     -> Edite os funcionarios                     |\n");
    printf("|  [4] - Excluir Funcionario    -> Exclua os Funcionarios                    |\n");
    printf("|  [5] - Sair                  -> Encerrar o sistema                         |\n");
    printf("|                                                                            |\n");
    printf("==============================================================================\n");
    printf("Digite o número correspondente à sua escolha: ");
}

void abaClientes()
{

    exibirMenuCliente();
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        cadastrarClientes();
        break;
    case 2:
        listarClientes();
        break;
    case 3:
        excluirClientes();
        break;
    case 4:
        editarClientes();
        break;
    case 5:
        printf("Saindo....\n");
        break;
    default:
        printf("Operação inválida. Tente novamente.\n");
    }
}

void abaPedidos(){
    exibirMenuPedidos();
    int opcao = 0;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            adicionarPedido();
            break;
        case 2:
            listarPedidos();
            break;
        case 3:
            editarPedido();
            break;
        case 4:
            excluirPedido();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
}

void abaFuncionario(){
    exibirMenuFucionario();
    int opcao;
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                adicionarFuncionario();
                break;
            case 2:
                listarFuncionarios();
                break;
            case 3:
                editarFuncionario();
                break;
            case 4:
                excluirFuncionario();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

void cadastrarClientes() {
    FILE *arquivo = fopen(FILENAME, "a+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Cliente cliente;
    int ultimoId = 0;
    char linha[500];


    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int tempId;
        sscanf(linha, "%d,", &tempId); 
        if (tempId > ultimoId) {
            ultimoId = tempId;
        }
    }

    cliente.id = ultimoId + 1;


    while (getchar() != '\n');
    
	printf("Digite as informações do cliente:\n");
    printf("Nome: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; 

    printf("Endereço: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

    printf("Telefone: ");
    fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(cliente.email, sizeof(cliente.email), stdin);
    cliente.email[strcspn(cliente.email, "\n")] = '\0';


    fprintf(arquivo, "%d, %s, %s, %s, %s\n", cliente.id, cliente.nome, cliente.endereco, cliente.telefone, cliente.email);

    fclose(arquivo);
    printf("Cliente cadastrado com sucesso!!!\n");
}


void listarClientes() {
    FILE *arquivo = fopen(FILENAME, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo ou nenhum cliente cadastrado.\n");
        return;
    }

    char linha[500];
    printf("Lista de Clientes:\n");
    printf("ID | Nome                | Endereço            | Telefone        | Email\n");
    printf("-------------------------------------------------------------------------------\n");
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void excluirClientes() {
    FILE *arquivo = fopen(FILENAME, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *tempArquivo = fopen("temp.txt", "w");
    if (!tempArquivo) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    int idAlvo, encontrado = 0;
    printf("Digite o ID do cliente que deseja excluir: ");
    scanf("%d", &idAlvo);

    Cliente cliente;
    char linha[500];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d, %99[^,], %199[^,], %19[^,], %99[^\n]", 
               &cliente.id, cliente.nome, cliente.endereco, cliente.telefone, cliente.email);

        if (cliente.id != idAlvo) {
            fprintf(tempArquivo, "%d, %s, %s, %s, %s\n", 
                    cliente.id, cliente.nome, cliente.endereco, cliente.telefone, cliente.email);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    if (encontrado) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Cliente excluído com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Cliente com ID %d não encontrado.\n", idAlvo);
    }
}


void editarClientes() {
    FILE *arquivo = fopen(FILENAME, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *tempArquivo = fopen("temp.txt", "w");
    if (!tempArquivo) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    int idAlvo, encontrado = 0;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &idAlvo);

    Cliente cliente;
    char linha[500];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%d, %99[^,], %199[^,], %19[^,], %99[^\n]", 
               &cliente.id, cliente.nome, cliente.endereco, cliente.telefone, cliente.email);

        if (cliente.id == idAlvo) {
            encontrado = 1;

            printf("Novo Nome (atual: %s): ", cliente.nome);
            getchar(); // Limpa buffer
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

            printf("Novo Endereço (atual: %s): ", cliente.endereco);
            fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
            cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

            printf("Novo Telefone (atual: %s): ", cliente.telefone);
            fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
            cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';

            printf("Novo Email (atual: %s): ", cliente.email);
            fgets(cliente.email, sizeof(cliente.email), stdin);
            cliente.email[strcspn(cliente.email, "\n")] = '\0';
        }

        fprintf(tempArquivo, "%d, %s, %s, %s, %s\n", 
                cliente.id, cliente.nome, cliente.endereco, cliente.telefone, cliente.email);
    }

    fclose(arquivo);
    fclose(tempArquivo);

    if (encontrado) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Cliente editado com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("Cliente com ID %d não encontrado.\n", idAlvo);
    }
}

void preencherPedido(Pedido *pedido)
{
    pedido->total = 0;

    printf("Selecione a borda (1-Tradicional, 2-Alho frito, 3-Cheddar): ");
    int escolhaBorda;
    scanf("%d", &escolhaBorda);
    switch (escolhaBorda)
    {
    case 1:
        strcpy(pedido->borda, "Tradicional");
        pedido->total += 2.00;
        break;
    case 2:
        strcpy(pedido->borda, "Alho frito");
        pedido->total += 3.00;
        break;
    case 3:
        strcpy(pedido->borda, "Cheddar");
        pedido->total += 4.00;
        break;
    default:
        printf("Opção inválida. Pedido cancelado.\n");
        return;
    }

    printf("Selecione o tamanho (1-Pequena, 2-Média, 3-Grande): ");
    int escolhaTamanho;
    scanf("%d", &escolhaTamanho);
    switch (escolhaTamanho)
    {
    case 1:
        strcpy(pedido->tamanho, "Pequena");
        pedido->total += 10.00;
        break;
    case 2:
        strcpy(pedido->tamanho, "Média");
        pedido->total += 15.00;
        break;
    case 3:
        strcpy(pedido->tamanho, "Grande");
        pedido->total += 20.00;
        break;
    default:
        printf("Opção inválida. Pedido cancelado.\n");
        return;
    }

    printf("Selecione o sabor 1 (1-Calabresa, 2-Mussarela, 3-Frango, 4-Portuguesa, 5-Marguerita): ");
    int escolhaSabor1;
    scanf("%d", &escolhaSabor1);
    switch (escolhaSabor1)
    {
    case 1:
        strcpy(pedido->sabor1, "Calabresa");
        pedido->total += 5.00;
        break;
    case 2:
        strcpy(pedido->sabor1, "Mussarela");
        pedido->total += 6.00;
        break;
    case 3:
        strcpy(pedido->sabor1, "Frango");
        pedido->total += 7.00;
        break;
    case 4:
        strcpy(pedido->sabor1, "Portuguesa");
        pedido->total += 8.00;
        break;
    case 5:
        strcpy(pedido->sabor1, "Marguerita");
        pedido->total += 9.00;
        break;
    default:
        printf("Opção inválida. Pedido cancelado.\n");
        return;
    }

    printf("Selecione o sabor 2 (1-Calabresa, 2-Mussarela, 3-Frango, 4-Portuguesa, 5-Marguerita, 0-Nenhum): ");
    int escolhaSabor2;
    scanf("%d", &escolhaSabor2);
    switch (escolhaSabor2)
    {
    case 0:
        strcpy(pedido->sabor2, "Nenhum");
        break;
    case 1:
        strcpy(pedido->sabor2, "Calabresa");
        pedido->total += 5.00;
        break;
    case 2:
        strcpy(pedido->sabor2, "Mussarela");
        pedido->total += 6.00;
        break;
    case 3:
        strcpy(pedido->sabor2, "Frango");
        pedido->total += 7.00;
        break;
    case 4:
        strcpy(pedido->sabor2, "Portuguesa");
        pedido->total += 8.00;
        break;
    case 5:
        strcpy(pedido->sabor2, "Marguerita");
        pedido->total += 9.00;
        break;
    default:
        printf("Opção inválida. Pedido cancelado.\n");
        return;
    }

    printf("Selecione a bebida (1-Refrigerante, 2-Suco, 0-Nenhum): ");
    int escolhaBebida;
    scanf("%d", &escolhaBebida);
    switch (escolhaBebida)
    {
    case 0:
        strcpy(pedido->bebida, "Nenhum");
        break;
    case 1:
        strcpy(pedido->bebida, "Refrigerante");
        pedido->total += 5.00;
        break;
    case 2:
        strcpy(pedido->bebida, "Suco");
        pedido->total += 3.00;
        break;
    default:
        printf("Opção inválida. Pedido cancelado.\n");
        return;
    }

    printf("Pedido atualizado com sucesso!\n");
}

float calcularTotal(float valorBorda, float valorTamanho, float valorSabor1, float valorSabor2, float valorBebida)
{
    return valorBorda + valorTamanho + valorSabor1 + valorSabor2 + valorBebida;
}

void adicionarPedido()
{
    if (totalPedidos >= MAX_PEDIDOS)
    {
        printf("Erro: Limite máximo de pedidos atingido.\n");
        return;
    }

    Pedido novoPedido;
    novoPedido.id = totalPedidos + 1;

    preencherPedido(&novoPedido);
    pedidos[totalPedidos++] = novoPedido;
}

void editarPedido()
{
    int id;
    printf("Digite o ID do pedido que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalPedidos; i++)
    {
        if (pedidos[i].id == id)
        {
            printf("Editando pedido ID %d:\n", id);
            preencherPedido(&pedidos[i]);
            return;
        }
    }

    printf("Pedido com ID %d não encontrado.\n", id);
}

    void listarPedidos()
{
    printf("\nLista de Pedidos:\n");
    for (int i = 0; i < totalPedidos; i++)
    {
    	printf("Lista de Pedidos:\n");
    	printf("ID | Borda               | Tamanho           | Sabor 1        | Sabor 2      | Bebida  | Total     \n");
    	printf("---------------------------------------------------------------------------------------------------\n");
        printf("%d, %s, %s, %s, %s, %s, R$%.2f\n",
               pedidos[i].id, pedidos[i].borda, pedidos[i].tamanho, pedidos[i].sabor1,
               pedidos[i].sabor2, pedidos[i].bebida, pedidos[i].total);
    }
}

void excluirPedido(){
    int id;
    printf("Digite o ID do pedido que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id) {
            for (int j = i; j < totalPedidos - 1; j++) {
                pedidos[j] = pedidos[j + 1];
            }
            totalPedidos--;
            printf("Pedido com ID %d foi excluído com sucesso.\n", id);
            return;
        }
    }

    printf("Pedido com ID %d não encontrado.\n", id);
}


void adicionarFuncionario() {
    if (totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Erro: Limite máximo de funcionários atingido.\n");
        return;
    }

    Funcionario novoFuncionario;
    novoFuncionario.id = totalFuncionarios + 1;
	printf("Digite as informações do funcionario:\n");
	printf("Nome:");
    getchar();                                                                     
    fgets(novoFuncionario.nome, 100, stdin);
    novoFuncionario.nome[strcspn(novoFuncionario.nome, "\n")] = '\0';

    printf("Email:");
    fgets(novoFuncionario.email, 100, stdin);
    novoFuncionario.email[strcspn(novoFuncionario.email, "\n")] = '\0';

    printf("Selecione a função (1-Gerente, 2-Atendente, 3-Cozinheiro, 4-Entregador):\n ");
    int escolhaFuncao;
    scanf("%d", &escolhaFuncao);
    switch (escolhaFuncao) {
        case 1:
            strcpy(novoFuncionario.funcao, "Gerente");
            break;
        case 2:
            strcpy(novoFuncionario.funcao, "Atendente");
            break;
        case 3:
            strcpy(novoFuncionario.funcao, "Cozinheiro");
            break;
        case 4:
            strcpy(novoFuncionario.funcao, "Entregador");
            break;
        default:
            printf("Opção inválida. Funcionário não adicionado.\n");
            return;
    }

    funcionarios[totalFuncionarios++] = novoFuncionario;
    printf("Funcionario adicionado com sucesso!!!\n");
}

void listarFuncionarios() {
    printf("Lista de Funcionarios\n");
    printf("ID    | Nome                 | Email               | Função            |\n");
    for (int i = 0; i < totalFuncionarios; i++) {
        printf("%d, %s, %s, %s\n",
               funcionarios[i].id, funcionarios[i].nome,
               funcionarios[i].email, funcionarios[i].funcao);
    }
}

void editarFuncionario() {
    int id;
    printf("Digite o id do funcionario que deseja editar: ", id);
    scanf("%d", &id);

    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == id) {

            printf("Digite o novo nome (ou pressione Enter para manter o atual): ");
            getchar();
            char nome[100];
            fgets(nome, 100, stdin);
            if (strcmp(nome, "\n") != 0) {
                nome[strcspn(nome, "\n")] = '\0';
                strcpy(funcionarios[i].nome, nome);
            }

            printf("Digite o novo email (ou pressione Enter para manter o atual): ");
            char email[100];
            fgets(email, 100, stdin);
            if (strcmp(email, "\n") != 0) {
                email[strcspn(email, "\n")] = '\0';
                strcpy(funcionarios[i].email, email);
            }

            printf("Selecione a nova função (1-Gerente, 2-Atendente, 3-Cozinheiro, 4-Entregador, 0-Manter atual): ");
            int escolhaFuncao;
            scanf("%d", &escolhaFuncao);
            if (escolhaFuncao != 0) {
                switch (escolhaFuncao) {
                    case 1:
                        strcpy(funcionarios[i].funcao, "Gerente");
                        break;
                    case 2:
                        strcpy(funcionarios[i].funcao, "Atendente");
                        break;
                    case 3:
                        strcpy(funcionarios[i].funcao, "Cozinheiro");
                        break;
                    case 4:
                        strcpy(funcionarios[i].funcao, "Entregador");
                        break;
                    default:
                        printf("Opção inválida. Mantendo a função atual.\n");
                }
            }

            printf("Funcionario atualizado com sucesso!!!!\n");
            return;
        }
    }

    printf("Funcionário com ID %d não encontrado.\n", id);
}

void excluirFuncionario() {
    int id;
    printf("Digite o id do funcionario que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < totalFuncionarios; i++) {
        if (funcionarios[i].id == id) {
            for (int j = i; j < totalFuncionarios - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            totalFuncionarios--;
            printf("Funcionario excluido com sucesso\n");
            return;
        }
    }

    printf("Funcionário com ID %d não encontrado.\n", id);
}
