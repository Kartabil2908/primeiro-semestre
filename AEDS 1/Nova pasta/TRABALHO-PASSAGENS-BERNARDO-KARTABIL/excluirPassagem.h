#include <stdio.h>

void excluirPassagem(int IDpesquisa) {
    FILE *arquivo, *temp;
    int quantidadePassagens, ultimoId, idAtual;
    char linha[100], resposta;

    arquivo = fopen("Passagens.txt", "r");
    temp = fopen("TempPassagens.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        puts("Erro ao abrir o arquivo, verifique se o arquivo existe");
        return;
    }

    // Ler a quantidade de passagens e o último ID
    fscanf(arquivo, "%d", &quantidadePassagens);
    fscanf(arquivo, "%d", &ultimoId);
    printf("Quantidade de passagens: %d\nÚltimo ID: %d\n", quantidadePassagens, ultimoId);

    fprintf(temp, "%d\n%d\n", quantidadePassagens, ultimoId);

    while (fscanf(arquivo, "%d", &idAtual) != EOF) {
        if (idAtual == IDpesquisa) {
            puts("<-------------------------------------------------------->");
            printf("Passagem encontrada:\n");
            printf("%d;", idAtual);
            fgets(linha, sizeof(linha), arquivo); // Pula o restante da linha
            printf("%s", linha);
            puts("<-------------------------------------------------------->");

            printf("Deseja excluir essa passagem? (y/n): ");
            scanf(" %c", &resposta);

            if (resposta == 'y' || resposta == 'Y') {
                // Atualiza a quantidade de passagens
                quantidadePassagens--;

                continue;
            }
        }

        fprintf(temp, "%d", idAtual);
        fgets(linha, sizeof(linha), arquivo); // Copia o restante da linha
        fprintf(temp, "%s", linha);
    }

    fclose(arquivo);
    fclose(temp);

    if (remove("Passagens.txt") == 0 && rename("TempPassagens.txt", "Passagens.txt") == 0) {
        puts("Exclusão bem-sucedida!");
    } else {
        puts("Erro ao excluir ou renomear o arquivo.");
    }
}

int main() {
    excluirPassagem(2);  // Altere o ID conforme necessário
    return 0;
}
