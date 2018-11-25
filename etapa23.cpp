#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>

const int MAX=40;
using namespace std;
void imprimir_matriz(char [][MAX], int,int );

void preenche_matriz(char [][MAX], int ,int ,char );

void criar_bomba(char [][MAX], int ,int ,int );

void bomba_proxima( char m[][MAX], int ordemL, int ordemC);

void soma_posicao(char m[][MAX], int ordemL, int ordemC, int , int );

void descubrir (char m[][MAX], char m2[][MAX], int ordemL, int ordemC, int , int  );

int main()
{
    int escolha1,escolha2,dimL,dimC,marcador,L1,C1,L2,C2,L3,C3,L4,C4,variavel,tempo,cont=0,Quant_mina=0;
    bool jogo= true;
    bool ganhar= true;
    char ganhador[50],matriz1[MAX][MAX], matriz2[MAX][MAX];
    tempo=time(0);



    do
    {
        cout<<"1.Novo jogo"<<endl;
        cout<<"2.Melhores tempos"<<endl;
        cout<<"3.Sair"<<endl;

        cout<<"digite sua escolha:"<<endl;
        cin>>escolha1;
    }
    while(escolha1<1 ||escolha1>3);
    //system("cls");     // caso for linux "clear" (para sumir o escrito na tela depois da escolha)
    if(escolha1==1)
    {
        do
        {
            cout<<"tempo:"<<time(0)-tempo<<endl;
            cout<<"1.Jogo Iniciante"<<endl;
            cout<<"2.Jogo Intermediario"<<endl;
            cout<<"3.Jogo Personalizado"<<endl;
            cout<<"4.Voltar"<<endl;

            cout<<"digite sua escolha:"<<endl;
            cin>>escolha2;
        }
        while(escolha2<1 ||escolha2>4);
        if(escolha2==1)
        {
            Quant_mina=10;
            cout<<"INICIANTE" <<endl;
            preenche_matriz(matriz1, 8,8,'.');

            //imprimir_matriz(matriz1, 8,8);

            //cout<<"matriz 2"<<endl;

            preenche_matriz(matriz2, 8,8,'0');

            criar_bomba( matriz2, 8,8, 10);

            bomba_proxima( matriz2, 8,8);

            imprimir_matriz(matriz2, 8,8);


            do
            {
                //system("cls");
                imprimir_matriz(matriz1, 8,8);

                do
                {
                    cout<<endl;
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"minas ha ser descoberta: "<<Quant_mina<<endl;
                    cout<<"escolha: "<<endl;
                    cout<<"1-> descobrir quadrado"<<endl;
                    cout<<"2-> maracar mina(M)"<<endl;
                    cout<<"3-> talvez mina(?)"<<endl;
                    cout<<"4-> limpar marcar"<<endl;
                    cout<<"5-> sair"<<endl;
                    cin>>marcador;


                }
                while(marcador<1 || marcador>6);

                if(marcador==1)
                {
                    cout<<"descobrir a posicao, linha e coluna: "<<endl;
                    cin>>L1>>C1;

                    matriz1[L1][C1]= matriz2[L1][C1];

                    cout<<matriz1[L1][C1];

                    if(matriz2[L1][C1]=='0')
                    {
                        descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                        imprimir_matriz(matriz1, 8,8);
                    }
                    if(matriz2[L1][C1]=='*')
                    {
                        jogo=false;
                        ganhar=false;
                    }

                }
                if(marcador==2)
                {
                    cout<<"marcar mina, linha e coluna:"<<endl;
                    cin>>L2>>C2;

                    if(matriz1[L2][C2]=='.' || matriz1[L2][C2]=='?')
                    {
                        matriz1[L2][C2]='M';
                        Quant_mina--;
                    }
                    imprimir_matriz(matriz1, 8,8);
                }

                if(marcador==3)
                {
                    cout<<"marcar a duvida de mina:"<<endl;
                    cin>>L3>>C3;

                    if(matriz1[L3][C3]=='.' || matriz1[L3][C3]=='M')
                    {
                        matriz1[L3][C3]='?';
                    }
                    imprimir_matriz(matriz1,8,8);
                }
                if(marcador==4)
                {
                    cout<<"limpar marcador: "<<endl;
                    cin>>L4>>C4;
                    if(matriz1[L4][C4]=='M' || matriz1[L4][C4]=='?')
                    {
                        matriz1[L4][C4]='.';
                    }
                    imprimir_matriz(matriz1,8,8);
                }
                imprimir_matriz(matriz2,8,8); // GABARITO
                if(marcador==5)
                {
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"1.Jogo Iniciante"<<endl;
                    cout<<"2.Jogo Intermediario"<<endl;
                    cout<<"3.Jogo Personalizado"<<endl;
                    cout<<"4.Voltar"<<endl;

                    cout<<"digite sua escolha:"<<endl;
                    cin>>escolha2;
                    break;
                    //system("cls");
                }
                cont=0;
                for(int a=0; a<8; a++)
                {
                    for(int b=0; b<8; b++)
                    {
                        if(matriz1[a][b]=='.')
                        {
                            cont++;
                        }
                    }
                }
                if(cont==Quant_mina)
                {
                    jogo=false;
                    ganhar=true;
                }


            }
            while(jogo);

            if(ganhar==true)
            {
                variavel=time(0)-tempo;
                cout<<endl;
                cout<<"VOCE GANHOU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);
                cout<<"Digite seu nome:";
                cin >> ganhador;
                ofstream ganhadores("arquivo.txt");
                if(!ganhadores.is_open())
                {
                    cout<<"Falha ao abrir o arquivo!"<<endl;
                    exit(1);
                }
                ganhadores<<ganhador<<"\ntempo: "<<variavel<<endl;

                ganhadores.close();

                cout<<"1.Novo jogo"<<endl;
                cout<<"2.Melhores tempos"<<endl;
                cout<<"3.Sair"<<endl;

                cout<<"digite sua escolha:"<<endl;
                cin>>escolha1;

            }


            if(ganhar==false)
            {
                cout<<endl;
                cout<<"VOCE PERDEU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);
            }

        }//-------------------FIM DO ESCOLHA2==1( MINA INICIANTE)-------------------------------
        if(escolha2==2)
        {
            Quant_mina=40;
            cout<<"INTERMEDIARIO"<<endl;

            preenche_matriz(matriz1, 16,16,'.');

            //imprimir_matriz(matriz1, 16,16);

            //--------matriz 2------

            preenche_matriz(matriz2, 16,16,'0');

            criar_bomba( matriz2, 16,16, 40);

            bomba_proxima( matriz2, 16,16);

            //imprimir_matriz(matriz2, 16,16);

            do
            {
                //system("cls");
                imprimir_matriz(matriz1, 16,16);

                do
                {
                    cout<<endl;
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"minas ha ser descoberta: "<<Quant_mina<<endl;
                    cout<<"escolha: "<<endl;
                    cout<<"1-> descobrir quadrado"<<endl;
                    cout<<"2-> maracar mina(M)"<<endl;
                    cout<<"3-> talvez mina(?)"<<endl;
                    cout<<"4-> limpar marcar"<<endl;
                    cout<<"5-> sair"<<endl;
                    cin>>marcador;

                }
                while(marcador<1 || marcador>5);

                if(marcador==1)
                {
                    cout<<"descobrir a posicao, linha e coluna: "<<endl;
                    cin>>L1>>C1;

                    matriz1[L1][C1]= matriz2[L1][C1];

                    cout<<matriz1[L1][C1];

                    if(matriz2[L1][C1]=='0')
                    {
                        descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                        imprimir_matriz(matriz1, 16,16);
                    }
                    if(matriz2[L1][C1]=='*')
                    {
                        jogo=false;
                        ganhar=false;
                    }
                }
                if(marcador==2)
                {
                    cout<<"marcar mina, linha e coluna:"<<endl;
                    cin>>L2>>C2;

                    if(matriz1[L2][C2]=='.' || matriz1[L2][C2]=='?')
                    {
                        matriz1[L2][C2]='M';
                        Quant_mina--;
                    }
                    imprimir_matriz(matriz1, 16,16);
                }

                if(marcador==3)
                {
                    cout<<"marcar a duvida de mina:"<<endl;
                    cin>>L3>>C3;

                    if(matriz1[L3][C3]=='.' || matriz1[L3][C3]=='M')
                    {
                        matriz1[L3][C3]='?';
                    }
                    imprimir_matriz(matriz1,16,16);
                }
                if(marcador==4)
                {
                    cout<<"limpar marcador: "<<endl;
                    cin>>L4>>C4;

                    if(matriz1[L4][C4]=='M' && matriz1[L4][C4]=='?')
                    {
                        matriz1[L4][C4]='.';
                    }
                    imprimir_matriz(matriz1,16,16);
                }
                if(marcador==5)
                {
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"1.Jogo Iniciante"<<endl;
                    cout<<"2.Jogo Intermediario"<<endl;
                    cout<<"3.Jogo Personalizado"<<endl;
                    cout<<"4.Voltar"<<endl;

                    cout<<"digite sua escolha:"<<endl;
                    cin>>escolha2;
                    break;
                    system("cls");
                }


            }
            while(jogo);
            if(ganhar==true)
            {
                variavel=time(0)-tempo;
                cout<<endl;
                cout<<"VOCE GANHOU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);
                cout<<"Digite seu nome:";
                cin >> ganhador;
                ofstream ganhadores("arquivo1.txt");
                if(!ganhadores.is_open())
                {
                    cout<<"Falha ao abrir o arquivo!"<<endl;
                    exit(1);
                }
                ganhadores<<ganhador<<"\ntempo: "<<variavel<<endl;

                ganhadores.close();

                cout<<"1.Novo jogo"<<endl;
                cout<<"2.Melhores tempos"<<endl;
                cout<<"3.Sair"<<endl;

                cout<<"digite sua escolha:"<<endl;
                cin>>escolha1;

            }


            if(ganhar==false)
            {
                cout<<endl;
                cout<<"VOCE PERDEU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);
            }
        }//----------------------FIM DO ESCOLHA2==2(MINA INTERMEDIARIO)------------------------
        if(escolha2==3)
        {
            cout<<"PERSONALIZADO"<<endl;
            cout<<"digite as dimensoes da matriz, linhas: "<<endl;
            cin>>dimL;
            cout<<"colunas: "<<endl;
            cin>>dimC;

            do
            {
                cout<<"digite a quantidade de minas: "<<endl;
                cin>>Quant_mina;
            }
            while(Quant_mina>(dimL*dimC)-10);

            preenche_matriz(matriz1, dimL,dimC,'.');

            //imprimir_matriz(matriz1, dimL,dimC);

            //--------mattriz 2-------

            preenche_matriz(matriz2, dimL,dimC,'0');

            criar_bomba( matriz2, dimL,dimC, Quant_mina);

            bomba_proxima( matriz2, dimL,dimC);

            //imprimir_matriz(matriz2, dimL,dimC);

            do
            {
                //system("cls");
                imprimir_matriz(matriz1, dimL,dimC);

                do
                {
                    cout<<endl;
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"minas ha ser descoberta: "<<Quant_mina<<endl;
                    cout<<"escolha: "<<endl;
                    cout<<"1-> descobrir quadrado"<<endl;
                    cout<<"2-> maracar mina(M)"<<endl;
                    cout<<"3-> talvez mina(?)"<<endl;
                    cout<<"4-> limpar marcar"<<endl;
                    cout<<"5-> sair"<<endl;
                    cin>>marcador;

                }
                while(marcador<1 || marcador>5);

                if(marcador==1)
                {
                    cout<<"descobrir a posicao, linha e coluna: "<<endl;
                    cin>>L1>>C1;

                    matriz1[L1][C1]= matriz2[L1][C1];

                    cout<<matriz1[L1][C1];

                    if(matriz2[L1][C1]=='0')
                    {
                        descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                        imprimir_matriz(matriz1, dimL,dimC);
                    }
                    if(matriz2[L1][C1]=='*')
                    {
                        jogo=false;
                    }
                }
                if(marcador==2)
                {
                    cout<<"marcar mina, linha e coluna:"<<endl;
                    cin>>L2>>C2;

                    if(matriz1[L2][C2]=='.' || matriz1[L2][C2]=='?')
                    {
                        matriz1[L2][C2]='M';
                        Quant_mina--;
                    }
                    imprimir_matriz(matriz1, dimL,dimC);
                }

                if(marcador==3)
                {
                    cout<<"marcar a duvida de mina:"<<endl;
                    cin>>L3>>C3;

                    if(matriz1[L3][C3]=='.' || matriz1[L3][C3]=='M')
                    {
                        matriz1[L3][C3]='?';
                    }
                    imprimir_matriz(matriz1, dimL,dimC);
                }
                if(marcador==4)
                {
                    cout<<"limpar marcador: "<<endl;
                    cin>>L4>>C4;

                    if(matriz1[L4][C4]=='M' && matriz1[L4][C4]=='?')
                    {
                        matriz1[L4][C4]='.';
                    }
                    imprimir_matriz(matriz1, dimL,dimC);
                }
                if(marcador==5)
                {
                    cout<<"tempo:"<<time(0)-tempo<<endl;
                    cout<<"1.Jogo Iniciante"<<endl;
                    cout<<"2.Jogo Intermediario"<<endl;
                    cout<<"3.Jogo Personalizado"<<endl;
                    cout<<"4.Voltar"<<endl;

                    cout<<"digite sua escolha:"<<endl;
                    cin>>escolha2;
                    break;
                }

            }
            while(jogo);
            if(ganhar==true)
            {
                variavel=time(0)-tempo;
                cout<<endl;
                cout<<"VOCE GANHOU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);

                cout<<"1.Novo jogo"<<endl;
                cout<<"2.Melhores tempos"<<endl;
                cout<<"3.Sair"<<endl;

                cout<<"digite sua escolha:"<<endl;
                cin>>escolha1;

            }


            if(ganhar==false)
            {
                cout<<endl;
                cout<<"VOCE PERDEU O JOGO"<<endl;
                imprimir_matriz(matriz2, 8,8);
            }
        } //----------------------fim do escolha2==3(MINA PERSONALIZADA)------------------------------------
        if(escolha2==4)
        {


        }//---------------------fim do escolha2==4--------------------------------------
    }//--------------------- FIM DAS ESCOLHAS 2== NIVEL DE DIFICULDADE-------------------
    if(escolha1==2)
    {
        cout <<"MELHORES TEMPOS:"<<endl;
        cout<<" iniciante: "<<endl;
        ifstream ganhadores("arquivo.txt");
        while(!ganhadores.eof()){
            ganhadores.getline(ganhador,50);
            cout<<ganhador<<endl;
        }
        ganhadores.close();
        cout<<"intermediario: "<<endl;




    }//-------------------------FIM DA ESCOLHA1==2( MELHORES TEMPOS)---------------------------

    if(escolha1==3)
    {

    }//---------------------FIM DA ESCOLHA1==3 (SAIR DO JOGO)---------------------------

} //-----------------FIM DA FUNÇÃO "INT MAIN"-----------------------


void imprimir_matriz(char m[][MAX], int ordemL, int ordemC)
{
    cout<<"    ";
    for(int i=0; i<ordemC; i++)
    {
        cout<<"["<<i<<"]";
    }
    cout<<endl;
    for(int i=0; i<ordemL; i++)
    {
        if(i<10)
        {
            cout<<"["<<i<<"]  ";
        }
        else
        {
            cout<<"["<<i<<"] ";
        }

        for(int j=0; j<ordemC; j++)
        {
            if(j>10)
            {
                cout<<m[i][j]<<"   ";
            }
            else
            {
                cout<<m[i][j]<<"  ";
            }
        }
        cout<<endl;
    }

}
void preenche_matriz(char m[][MAX], int ordemL, int ordemC,char caracter)
{
    for(int i=0; i<ordemL; i++)
    {
        for(int j=0; j<ordemC; j++)
        {
            m[i][j]=caracter;
        }
    }
}

void criar_bomba(char m[][MAX], int ordemL, int ordemC, int cont_bomba)
{
    srand(time(NULL));
    int sorteioI, sorteioJ;
    sorteioI=rand()%ordemL;
    sorteioJ=rand()%ordemC;
    while(cont_bomba>0)
    {
        while(m[sorteioI][sorteioJ]!='0')
        {
            sorteioI=rand()%ordemL;
            sorteioJ=rand()%ordemC;
        }
        m[sorteioI][sorteioJ]='*';
        cont_bomba--;
    }

}

void bomba_proxima( char m[][MAX], int ordemL, int ordemC)
{

    for(int i=0; i<ordemL; i++)
    {
        for (int j=0; j<ordemC; j++)
        {
            if(m[i][j]=='*')
            {
                soma_posicao(m, ordemL, ordemC, i, j);
            }
        }
    }


}
void soma_posicao(char m[][MAX], int ordemL, int ordemC, int i, int j )
{

    if( (i-1>=0 && j-1>=0) && m[i-1][j-1]!='*' )
    {
        m[i-1][j-1]++;
    }
    if( (i-1>=0 && j>=0)  && m[i-1][j]!='*')
    {
        m[i-1][j]++;
    }
    if( (i-1>=0 && j+1<ordemC) && m[i-1][j+1]!='*')
    {
        m[i-1][j+1]++;
    }
    if( (i>=0 && j-1>=0) && m[i][j-1]!='*')
    {
        m[i][j-1]++;
    }
    if( (i>=0 && j+1<ordemC) && m[i][j+1]!='*')
    {
        m[i][j+1]++;
    }
    if( (i+1<ordemL && j-1>=0) && m[i+1][j-1]!='*')
    {
        m[i+1][j-1]++;
    }
    if( (i+1<ordemL && j>=0) && m[i+1][j]!='*')
    {
        m[i+1][j]++;
    }
    if( (i+1<ordemL && j+1>=0) && m[i+1][j+1]!='*')
    {
        m[i+1][j+1]++;
    }

}

void descubrir (char m[][MAX], char m2[][MAX], int ordemL, int ordemC, int i, int j)
{

    if(i-1>=0 && j-1>=0)
    {
        if( m[i-1][j-1]=='.')
        {
            m[i-1][j-1] = m2[i-1][j-1];
            if( m2[i-1][j-1]=='0' && m[i-1][j-1]!='_')
            {
                m[i-1][j-1]='_';
                descubrir ( m, m2, ordemL, ordemC, i-1, j-1);
            }
        }
    }
    if(i-1>=0 && j>=0)
    {
        if( m[i-1][j]=='.')
        {
            m[i-1][j] = m2[i-1][j];
            if(m2[i-1][j]=='0'&& m[i-1][j]!='_')
            {
                m[i-1][j]='_';
                descubrir ( m, m2, ordemL, ordemC, i-1, j);
            }
        }
    }
    if(i-1>=0 && j+1>=0)
    {
        if( m[i-1][j+1]=='.')
        {
            m[i-1][j+1] = m2[i-1][j+1];
            if( m2[i-1][j+1]=='0' && m[i-1][j+1]!='_')
            {
                m[i-1][j+1]='_';
                descubrir ( m, m2, ordemL, ordemC, i-1, j+1);
            }
        }
    }
    if(i>=0 && j-1>=0)
    {
        if( m[i][j-1]=='.')
        {
            m[i][j-1] = m2[i][j-1];
            if(m2[i][j-1]=='0'&& m[i][j-1]!='_')
            {
                m[i][j-1]='_';

                descubrir ( m, m2, ordemL, ordemC, i, j-1);
            }
        }
    }
    if(i>=0 && j>=0)
    {
        if(m2[i][j]=='0'&& m[i][j]!='_')
        {
            m[i][j]='_';
            descubrir ( m, m2, ordemL, ordemC, i, j);
        }

    }
    if(i>=0 && j+1>=0)
    {
        if( m[i][j+1]=='.')
        {
            m[i][j+1] = m2[i][j+1];
            if(m2[i][j+1]=='0'&& m[i][j+1]!='_')
            {
                m[i][j+1]='_';

                descubrir ( m, m2, ordemL, ordemC, i, j+1);
            }
        }
    }
    if(i+1>=0 && j-1>=0)
    {
        if( m[i+1][j-1]=='.')
        {
            m[i+1][j-1] = m2[i+1][j-1];
            if(m2[i+1][j-1]=='0'&& m[i+1][j-1]!='_')
            {
                m[i+1][j-1]='_';
                descubrir ( m, m2, ordemL, ordemC, i+1, j-1);
            }
        }
    }
    if(i+1>=0 && j>=0)
    {
        if( m[i+1][j]=='.')
        {
            m[i+1][j] = m2[i+1][j];
            if(m2[i+1][j]=='0'&& m[i+1][j]!='_')
            {
                m[i+1][j]='_';
                descubrir ( m, m2, ordemL, ordemC, i+1, j);

            }
        }
    }
    if(i+1>=0 && j+1>=0)
    {
        if( m[i+1][j+1]=='.')
        {
            m[i+1][j+1] = m2[i+1][j+1];
            if(m2[i+1][j+1]=='0'&& m[i+1][j+1]!='_')
            {
                m[i+1][j+1]='_';
                descubrir ( m, m2, ordemL, ordemC, i+1, j+1);
            }
        }
    }

} //----------------fim da função DESCUBRIR-----------------------
