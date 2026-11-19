#include <stdio.h>
#include <string.h>

int main() {
    char nomes[10][100], cpfs[10][20], telefones[10][20], usuarios[10][50], senhas[10][50], login[50], senhaLogin[50];
    int contas[10], total = 0, opcao, escolha, i, cliente;
    float saldos[10] = {0}, valor;

    do {
        printf("\n===== BEM-VINDO AO UNIBANK =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Fazer login\n");
        printf("3 - Encerrar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total < 10) {
                printf("\n=== CADASTRO ===\n");

                printf("Nome completo: ");
                scanf(" %99[^\n]", nomes[total]);

                printf("CPF: ");
                scanf("%19s", cpfs[total]);

                printf("Telefone: ");
                scanf("%19s", telefones[total]);

                printf("Numero da conta: ");
                scanf("%d", &contas[total]);

                printf("Nome de usuario: ");
                scanf("%49s", usuarios[total]);

                printf("Crie uma senha: ");
                scanf("%49s", senhas[total]);

                total++;

                printf("\nCadastro realizado com sucesso!\n");
            }
            else {
                printf("\nLimite de clientes atingido!\n");
            }
        }

        else if (opcao == 2) {
            if (total == 0) {
                printf("\nNenhum cliente cadastrado!\n");
            }
            else {
                printf("\n=== LOGIN ===\n");

                printf("Usuario: ");
                scanf("%49s", login);

                printf("Senha: ");
                scanf("%49s", senhaLogin);

                cliente = -1;

                for (i = 0; i < total; i++) {
                    if (strcmp(login, usuarios[i]) == 0 &&
                        strcmp(senhaLogin, senhas[i]) == 0) {
                        cliente = i;
                        break;
                    }
                }

                if (cliente == -1) {
                    printf("\nUsuario ou senha incorretos!\n");
                }
                else {
                    printf("\nLogin realizado com sucesso!\n");
                    printf("Bem-vindo, %s!\n", nomes[cliente]);

                    do {
                        printf("\n===== MENU UNIBANK =====\n");
                        printf("1 - Consultar saldo\n");
                        printf("2 - Consultar meus dados\n");
                        printf("3 - Sacar dinheiro\n");
                        printf("4 - Depositar dinheiro\n");
                        printf("5 - Sair da conta\n");
                        printf("Escolha uma opcao: ");
                        scanf("%d", &escolha);

                        if (escolha == 1) {
                            printf("\nSaldo atual: R$ %.2f\n",
                                   saldos[cliente]);
                        }

                        else if (escolha == 2) {
                            printf("\n=== MEUS DADOS ===\n");
                            printf("Nome: %s\n", nomes[cliente]);
                            printf("CPF: %s\n", cpfs[cliente]);
                            printf("Telefone: %s\n", telefones[cliente]);
                            printf("Numero da conta: %d\n", contas[cliente]);
                            printf("Usuario: %s\n", usuarios[cliente]);
                        }

                        else if (escolha == 3) {
                            printf("\nValor do saque: R$ ");
                            scanf("%f", &valor);

                            if (valor <= 0) {
                                printf("Valor invalido!\n");
                            }
                            else if (valor > saldos[cliente]) {
                                printf("Saldo insuficiente!\n");
                            }
                            else {
                                saldos[cliente] = saldos[cliente] - valor;

                                printf("Saque realizado com sucesso!\n");
                                printf("Saldo atual: R$ %.2f\n",
                                       saldos[cliente]);
                            }
                        }

                        else if (escolha == 4) {
                            printf("\nValor do deposito: R$ ");
                            scanf("%f", &valor);

                            if (valor <= 0) {
                                printf("Valor invalido!\n");
                            }
                            else {
                                saldos[cliente] = saldos[cliente] + valor;

                                printf("Deposito realizado com sucesso!\n");
                                printf("Saldo atual: R$ %.2f\n",
                                       saldos[cliente]);
                            }
                        }

                        else if (escolha == 5) {
                            printf("\nSaindo da conta...\n");
                        }

                        else {
                            printf("\nOpcao invalida!\n");
                        }

                    } while (escolha != 5);
                }
            }
        }

        else if (opcao == 3) {
            printf("\nObrigado por usar o UniBank!\n");
        }

        else {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 3);

    return 0;
}
