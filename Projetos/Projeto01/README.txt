Integrantes: Arthur Carlos Neuhauss

Passo a passo de como compilar:
    1º passo : Utilize o comando "make" no terminal da pasta do projeto, isto criará os arquivos ".o" e o programa "sistema_escolar" que será utilizado no proximo passo;
    2º passo : No mesmo terminal, digite "make run" ou "./sistema_escolar" para executar o programa, a partir daí os testes podem ser feitos;
        passo opcional: Eu criei um arquivo adicional "entrada.txt" que testa alguma das funcionalidades do programa.
    3º passo : Digite o comando "make clean" para remover os aquivos criados.

Módulos:
    Main: 
        Inicia e recebe as entradas do sistema, eu em primeiro momento fiz o "menu inicial" em uma função para que o main 
        somente chamasse ela, porém eu achei que era desnecessário.

    Estruturas:
        Ela recebe todas as structs do programa, eu fiz ela no meu "primeiro dia" da produção do projeto, mas passei a limpo
        e utilizei mais "unions"

    Pessoas (.c e .h):
        .h:
            Ele "herda" as structs de estruturas.h

        .c:
            A função "validadora" é o resultado da junção das funções que validam o CPF e o PIS (que tem a mesma quantidade de números) que eu percebi serem redundantes;
            Conforme eu comentei no trecho "Main" eu fiz os menus de acordo com os modulos relacionados;
            Na função de cadastro eu usei as funções verificadoras e caso fosse possível cadastrar os alunos, também realizei a fórmula solicitada para gerar a matricula;
            Na função de pesquisa, nada a mencionar;
            Na função "alterarPessoa", eu considerei fazer ela em duas funções, uma que recebe a matrícula/pis da pessoa e então uma (com o menu) que altera o que você solicita. 
            Porém não fiz isso, pois não queria que parecesse que eu coloquei mais funções só para dizer que tinha mais funções.


    Disciplina (.c e .h):
        .h:
            Ele "herda" as structs de estruturas.h
        
        .c:
            Na função "cadastrarDisciplina" eu não usei o "fgets(entrada, sizeof(entrada), stdin);" que eu usei na função "cadastrarPessoa" pois quando eu estava montando
            a função eu achei que precisaria verificar "manualmente" o PIS para ver se o professor existiria, e isso acabou ficando;
            Nada a comentar sobre a função de alterarProfessorDisciplina;
            Na função "adicionarAlunoDisciplina" ele passa pelas verificações se a disciplina existe, se o aluno existe, se o limite não foi alcançado e se o aluno já não está matriculado.
            Já na função "removerAlunoDisciplina" só verifico se o aluno e a disciplina existem, eu pensei em adicionar uma opcao de "Tem certeza?" com uma frase de confirmação
            mas quando fui começar a realizar os testes eu passei raiva com isso e apaguei, além do fato que isso iria quebrar qualquer teste automatizado;
            Nada a comentar sobre "exibirDisciplina".

            