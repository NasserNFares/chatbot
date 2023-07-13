#include <stdio.h>
#include <string.h>

int main()
{
    struct variaveis
    {

        char tipo[7];
        char pergunta[102];
        float alt[15];
        char checagem1[5];
        char checagem2[5];
        char checagem3[5];
        float resposta;
    } var[5];

    int i = 0, j = 0, k = 0;

    printf("----Etapa de treinamento----\n");

    while (1)
    {
        j = 0;

        fgets(var[k].tipo, 7, stdin);
        i = strlen(var[k].tipo);
        i -= 1;                             //TIPO DA PARADA
        var[k].tipo[i] = '\0';


        if ((strcmp(var[k].tipo, "FIM")) == 0)
            break;


        fgets(var[k].pergunta, 102, stdin);
        i = strlen(var[k].pergunta) - 1;       //PERGUNTA
        var[k].pergunta[i] = '\0';

        for (i = 0; i < 3; i++)
        {
            scanf("%f", &var[k].alt[i]);         //ALTERNATIVAS
            getchar();
        }

        if ((strcmp(var[k].tipo, "INT")== 0))             
            printf("Alternativa correta eh %.f?\n", var[k].alt[j]); //ALT 1
        else                         
            printf("Alternativa correta eh %.2f?\n", var[k].alt[j]);
        fgets(var[k].checagem1, 5, stdin);
        i = strlen(var[k].checagem1) - 1;
        var[k].checagem1[i] = '\0';

        if (strcmp(var[k].checagem1, "SIM") == 0)
        {
            var[k].resposta = var[k].alt[j];
        }
        else
        {
            j++;
            if ((strcmp(var[k].tipo, "INT")== 0))
                printf("Alternativa correta eh %.f?\n", var[k].alt[j]);     //ALT 2
            else
                printf("Alternativa correta eh %.2f?\n", var[k].alt[j]);

            fgets(var[k].checagem2, 5, stdin);
            i = strlen(var[k].checagem2) - 1;
            var[k].checagem2[i] = '\0';

            if (strcmp(var[k].checagem2, "SIM") == 0)
            {

                var[k].resposta = var[k].alt[j];
            }
            else
            {
                j++;
                if ((strcmp(var[k].tipo, "INT") == 0))
                    printf("Alternativa correta eh %.f?\n", var[k].alt[j]); //ALT 3
                else
                    printf("Alternativa correta eh %.2f?\n", var[k].alt[j]);

                fgets(var[k].checagem3, 5, stdin);
                i = strlen(var[k].checagem3) - 1;
                var[k].checagem3[i] = '\0';

                if (strcmp(var[k].checagem3, "SIM") == 0)
                {

                    var[k].resposta = var[k].alt[j];
                }
            }
        }
        k++;
    }
    
    printf("---Etapa de testes---\n");
    while (1)
    {

        char perguntateste[102];

        fgets(perguntateste, 102, stdin);
        j = strlen(perguntateste) - 1;
        perguntateste[j] = '\0';

        if ((strcmp(perguntateste, "FIM")) == 0)
            break;

        for(i = 0; i < k; i++){
        if ((strcmp(var[i].pergunta, perguntateste)) == 0){
            if((strcmp(var[i].tipo, "INT")== 0)){
                printf("A resposta eh: %.f\n", var[i].resposta);
                break;
            }
            else{
                printf("A resposta eh: %.2f\n", var[i].resposta);
                break;
            }
        }
        }
        if(i == k)
            printf("Me desculpe, ainda não fui treinado para responder essa pergunta.\n");
    }

    return 0;
}