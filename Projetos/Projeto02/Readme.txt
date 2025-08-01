Integrantes: Arthur Carlos Neuhauss

Bem vindo a biblioteca imagens_ppm, nela você pode:
    Inverter as cores da sua foto PPM;
    Aplicar um filtro GrayScale;
    Rotacionar a imagem em ângulos retos;
    Redimensionar a imagem, reduzindo ou ampliando em até 4 vezes;

    Para compilar digite:
        make
    então:
        ./main entrada.ppm cinza saida.ppm
        ./main entrada.ppm inverte saida.ppm
        ./main entrada.ppm rot 90 saida.ppm  //aqui pode ser qualquer valor entre 90/180/270
        ./main entrada.ppm red 1 saida.ppm   //aqui pode ser qualquer valor entre 1 e 4
        ./main entrada.ppm amp 1 saida.ppm   //aqui pode ser qualquer valor entre 1 e 4

    para limpar:
        make clean
        ou:
        make clean-all

Módulos:
    Main:
        Recebe a entrada e encaminha para a função solicitada, também coloquei uma verificação com uma resposta da entrada esperada

    imagens_ppm:
        .h:
            Nela são organizadas as estruturas da biblioteca, eu precisei mudar o "Pixel" que antes era um ponteiro de "Unsigned Char" na versão de teste
            para uma Struct pois eu tive dificuldades em trabalhar com ele na função "converter_dimensao", a Struct Pixel é utilizada dentro da Struct "ImagemPPM"
        
        .c:
            A função "verificaImagem" conforme o seu nome, é responsável por carregar e verificar se a imagem foi aberta corretamente;
            Eu já tinha feito uma versão básica dela no teste, mas decidi expandir um pouco mais para enfeitar melhor.

            A função "liberarImagem" é responsável pelo comando "free()" e sempre é chamada na Main.

            A função "salvarImagem" é uma evolução da função que eu fiz na fase de testes para criar a imagem "rotacionada", em que ela criava um "Pixel" adicional
            que receberia o Pixel original após a aplicação da rotação e que então seria impressa/criada, já aqui ela é responsável por criar o arquivo para todas as
            funções solicitadas e trazer um retorno caso não consiga.

            A função "converter_negativo" foi a primeira que eu fiz no teste e não tive trabalho nenhum;
            Ela só precisava do retorno de 255(ou maxval) menos o valor da cor (R,G,B) do Pixel, quando eu alterei para uma Struct dentro de uma Struct, eu só
            precisei de criar um Pixel que receberia o R,G,B de acordo com a fórmula.

            A função "converter_cinza" foi a segunda que eu fiz, utilizando uma fórmula genéria de GrayScale, desta vez, eu recebi os valores de RGB na auxiliar
            já alterados (R* 0.21 + G* 0.71 + B* 0.02) e apliquei o resultado da fórmula a todas as cores do Pixel.

            A função "converter_rotacao" foi feita na aula, porém também precisou ser adaptada para as structs, na minha ideia original, eu simplesmente iria
            repetir a função X vezes para alcançar o valor desejado 1,2,3 para 90,180,270 respectivamente, porém ao tentar implementar eu não consegui fazer de forma ótima
            utilizando um "aux" então decidi abandonar esta idéia e pesquisar como seriam as fómulas de rotação para os outros graus.

            A função "converter_dimensao" foi a última a ser feita, e foi ela quem motivou a mudança de "paradigma" do Pixel.
            Além disso, na primeira tentativa, eu fiz duas versões diferentes, uma para ampliar e outra para reduzir e uma delas seria chamada após a entrada ser tratada(verificada)
            porém como ambas eram pequenas eu as inseri dentro do próprio "If/Else" que eu estava utilizando para chama-las.
